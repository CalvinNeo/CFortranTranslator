#include "gen_common.h"

ParseNode gen_vardef_simple(const ParseNode & type, std::string name) {
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDEFINE, name }), nullptr);
	newnode.addchild(new ParseNode(type)); // type
	newnode.addchild(new ParseNode(gen_flex(Term{ TokenMeta::NT_VOID, "" }), nullptr)); // variable_desc
	ParseNode kv = gen_keyvalue(gen_token(Term{ TokenMeta::UnknownVariant, name }));
	ParseNode pt = gen_paramtable(kv);
	newnode.addchild(new ParseNode(pt)); // type
	return newnode;
}


ParseNode * promote_type(const ParseNode & type_spec, VariableDescAttr * vardescattr) {
	// reset type according to kind
	ParseNode * ty = new ParseNode(type_spec); // type
	VariableDescAttr * ty_a = dynamic_cast<VariableDescAttr *>(type_spec.attr);
	/* merge type_spec and variable_desc attr */
	vardescattr->merge(*ty_a);
	if (vardescattr->desc.kind != 0) {
		if (type_spec.fs.CurrentTerm.token == TokenMeta::Int_Def) {
			if (vardescattr->desc.kind == 1) {
				ty->fs.CurrentTerm.what = "char";
			}
			else if (vardescattr->desc.kind == 2) {
				ty->fs.CurrentTerm.what = "int";
			}
			else if (vardescattr->desc.kind == 4) {
				ty->fs.CurrentTerm.what = "int";
			}
			else if (vardescattr->desc.kind == 8) {
				ty->fs.CurrentTerm.what = "long long";
			}
		}
		else if (type_spec.fs.CurrentTerm.token == TokenMeta::Float_Def) {
			if (vardescattr->desc.kind == 1) {
				ty->fs.CurrentTerm.what = "float";
			}
			else if (vardescattr->desc.kind == 2) {
				ty->fs.CurrentTerm.what = "double";
			}
			else if (vardescattr->desc.kind == 4) {
				ty->fs.CurrentTerm.what = "double";
			}
			else if (vardescattr->desc.kind == 8) {
				ty->fs.CurrentTerm.what = "long double";
			}
		}
	}
	return ty;
}

std::string gen_qualified_typestr(std::string type_name, VariableDescAttr * vardescattr) {
	string var_pattern;
	if (vardescattr == nullptr) {
		var_pattern = "%s ";
	}
	else {
		if (vardescattr->desc.reference) {
			if (vardescattr->desc.constant) {
				var_pattern = "const %s & ";
			}
			else {
				var_pattern = "%s & ";
			}
		}
		else {
			if (vardescattr->desc.constant) {
				var_pattern = "const %s ";
			}
			else {
				var_pattern = "%s ";
			}
		}
	}
	sprintf(codegen_buf, var_pattern.c_str(), type_name.c_str());
	return string(codegen_buf);
}

std::string gen_lbound_size(const ParseNode * slice) {
	std::string vec_size = "{", vec_lb = "{";
	for (auto sliceid = 0; sliceid < slice->child.size(); sliceid++)
	{
		if (sliceid != 0) {
			vec_lb += ","; vec_size += ",";
		}
		int lb, ub;
		sscanf(slice->child[sliceid]->child[0]->fs.CurrentTerm.what.c_str(), "%d", &lb);
		sscanf(slice->child[sliceid]->child[1]->fs.CurrentTerm.what.c_str(), "%d", &ub);
		sprintf(codegen_buf, "%d", ub - lb + 1);
		vec_lb += slice->child[sliceid]->child[0]->fs.CurrentTerm.what; vec_size += codegen_buf;
	}
	vec_size += "}", vec_lb += "}";
	return vec_lb + ", " + vec_size;
}

std::string gen_vardef_array(ParseNode * pn, ParseNode * spec_typename, ParseNode * slice, VariableDescAttr * vardescattr) {
	/* in cpp code, definition of an array is inherit attribute(继承属性) grammar */
	string arr_decl = "";
	// pn is flattened
	for (auto i = 0; i < pn->child.size(); i++)
	{
		// for each variable in flatterned paramtable
		int sliceid = 0;
		string type_str;
		string innermost_type = gen_qualified_typestr(spec_typename->fs.CurrentTerm.what, vardescattr); // `T`
		if (parse_config.usefarray) {
			//sprintf(codegen_buf, "farray<%s, %d>", innermost_type.c_str(), (int)slice->child.size());
			sprintf(codegen_buf, "farray<%s>", innermost_type.c_str());
			type_str = string(codegen_buf);
		}
		else {
			sprintf(codegen_buf, "for1array<%s>", innermost_type.c_str());
			type_str = string(codegen_buf);
			for (sliceid = slice->child.size() - 2; sliceid >= 0; sliceid--)
			{
				sprintf(codegen_buf, "for1array< %s >", type_str.c_str());
				type_str = string(codegen_buf);
			}
		}

		// no desc if var_def is not in paramtable
		sprintf(codegen_buf, "%s %s", type_str.c_str(), pn->child[i]->child[0]->fs.CurrentTerm.what.c_str() /* array name */);
		arr_decl += string(codegen_buf);
		/* set initial value from array_builder */
		if (pn->child[i]->child[1]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEINITIALDUMMY){
			// default initialize
			if (parse_config.usefarray) {
				arr_decl += "{};\n"; // compile reckon "T a();" as function decl, so use `{}` 
			}
			else {
				sprintf(codegen_buf, "(%s, %s + 1)", slice->child[0]->child[0]->fs.CurrentTerm.what.c_str(), slice->child[0]->child[1]->fs.CurrentTerm.what.c_str() /* slice from to */);
				string dimension = string(codegen_buf);
				arr_decl += dimension;
				arr_decl += ";\n";
				sprintf(codegen_buf, "");
			}
		}
		else {
			// init from array_builder
			arr_decl += "(";
			ParseNode * variable_initial = pn->child[i];
			ParseNode * compound_arraybuilder = variable_initial->child[1]; // NT_ARRAYBUILDER
			bool can_list_init = true;
			for (auto builderid = 0; builderid < compound_arraybuilder->child.size(); builderid++)
			{
				ParseNode * array_builder = compound_arraybuilder->child[builderid];
				if (array_builder->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_VALUE) {
					can_list_init = false;
					break;
				}
				else if (array_builder->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_EXP) {

				}
				else {

				}
			}
			string lbound_size = gen_lbound_size(slice);
			arr_decl += lbound_size;
			arr_decl += ", ";
			if (can_list_init) 
			{
				// can init array from initializer_list of initial value
				for (auto builderid = 0; builderid < compound_arraybuilder->child.size(); builderid++)
				{
					ParseNode * array_builder = compound_arraybuilder->child[builderid];
					sprintf(codegen_buf, "%s", array_builder->fs.CurrentTerm.what.c_str());
					if (builderid > 0) {
						arr_decl += " , ";
					}
					arr_decl += codegen_buf;
				}
			}
			else {
				// must init array from another farray/for1array
				arr_decl += "{";
				for (auto builderid = 0; builderid < compound_arraybuilder->child.size(); builderid++)
				{
					ParseNode * array_builder = compound_arraybuilder->child[builderid];
					sprintf(codegen_buf, "farray<T>(%s, %s)", lbound_size.c_str(), array_builder->fs.CurrentTerm.what.c_str());
					if (builderid > 0) {
						arr_decl += " , ";
					}
					arr_decl += codegen_buf;
				}
				arr_decl += "}";
			}
			
			arr_decl += ");\n";
		}
	}
	return arr_decl;
}

ParseNode gen_vardef(const ParseNode & type_spec, const ParseNode & variable_desc, const ParseNode & paramtable) {
	ParseNode newnode = ParseNode();
	string arr_decl = ""; string var_decl = ""; bool do_arr = false;
	VariableDescAttr * vardescattr = dynamic_cast<VariableDescAttr *>(variable_desc.attr);
	ParseNode * slice = vardescattr->desc.slice;
	ParseNode * spec_typename = promote_type(type_spec, vardescattr); // reset type according to kind
	if (slice == nullptr) {
		// slice == nullptr if this is not array
		/* must assure no ParseNode * is nullptr */
		slice = new ParseNode(gen_flex(Term{ TokenMeta::NT_VOID, "" }), nullptr);
	}
	else {
		do_arr = true;
	}
	newnode.addchild(spec_typename); // type
	newnode.addchild(slice); // variable_desc
	ParseNode * pn = new ParseNode(gen_promote_paramtable(paramtable));
	newnode.addchild(pn); // paramtable
	newnode.attr = new VariableDescAttr(*dynamic_cast<VariableDescAttr *>(variable_desc.attr)); // attr
	if (do_arr)
	{
		// ARRAY
		arr_decl = gen_vardef_array(pn, spec_typename, slice, vardescattr);
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, arr_decl };
	}
	else {
		// SCALAR
		string typestr = gen_qualified_typestr(spec_typename->fs.CurrentTerm.what, vardescattr);
		var_decl += typestr;
		bool hitted = false; // 是否至少有一个变量，因为有的变量定义可能是函数的声明，这在c++规范是不允许的，所以可能出现空int，空逗号的情况。
		// pn is flattened
		for (auto i = 0; i < pn->child.size(); i++)
		{
			ParseNode * this_variable = new ParseNode(*pn->child[i]);
			// skip if it is a function, no module currently
			if (get_function("", this_variable->fs.CurrentTerm.what)) {
				continue;
			}
			if (hitted) {
				var_decl += ", ";
			}
			hitted = true;

			// variable name
			var_decl += this_variable->child[0]->fs.CurrentTerm.what;

			// variable initial value
			if (this_variable->child[1]->fs.CurrentTerm.token != TokenMeta::NT_VARIABLEINITIALDUMMY) {
				/* if initial value is not dummy but `exp` */
				var_decl += " = ";
				var_decl += this_variable->child[1]->fs.CurrentTerm.what;
			}
			/* desc */
			this_variable->attr = vardescattr->clone();
			delete this_variable; // TODO temporarily not use this_variable
		}
		var_decl += ";";
		if (!hitted) {
			// all function then remove even type declarator
			var_decl = "";
		}

		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, var_decl };
	} // end if
	// set all elements' attr in paramtable 
	for (int i = 0; i < pn->child.size(); i++)
	{
		pn->child[i]->attr = newnode.attr->clone();
	}
	return newnode;
}

