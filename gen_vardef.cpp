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

std::string gen_vardef_typestr(VariableDescAttr * vardescattr) {
	string var_pattern;
	if (vardescattr == nullptr) {
		return "%s ";
	}
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
	return var_pattern;
}

std::string gen_vardef_array(ParseNode * pn, ParseNode * spec_typename, ParseNode * slice, VariableDescAttr * vardescattr) {
	// ARRAY
	/* in cpp code, definition of an array is inherit attribute(继承属性) grammar */
	string arr_decl = "";
#define USE_LOOP
	// pn is flattened
	for (int i = 0; i < pn->child.size(); i++)
	{
		// for each variable in flatterned paramtable
		int sliceid = 0;
		sprintf(codegen_buf, "for1array<%s>", spec_typename->fs.CurrentTerm.what.c_str());
		sprintf(codegen_buf, gen_vardef_typestr(vardescattr).c_str(), string(codegen_buf).c_str());
		string type_str(codegen_buf);
		sprintf(codegen_buf, gen_vardef_typestr(vardescattr).c_str(), spec_typename->fs.CurrentTerm.what.c_str());
		string elem_type_str(codegen_buf); // `T`
										   // init high dimension array
										   /* though using for-loop to init a high-dimension array is verbose comparing to using constructors, 
										   i use this form because it is more clear and it can remind users of the cost of using a high dimension array */
		vector<string> this_major; /* if you want to set value of a(i0)(i1)(i2) then this_major is a(i0)(i1) */
		this_major.push_back(pn->child[i]/* NT_VARIABLEINITIAL/NT_KEYVALUE */->child[0]->fs.CurrentTerm.what /* array name */);
		for (int i = 1; i < slice->child.size(); i++)
		{
			sprintf(codegen_buf, "%s(i%d)", this_major.back().c_str(), i - 1);
			this_major.push_back(string(codegen_buf));
		}
		for (sliceid = slice->child.size() - 2; sliceid >= 0; sliceid--)
		{
			string prev_type_str = type_str;
			sprintf(codegen_buf, "for1array< %s >", type_str.c_str());
			type_str = string(codegen_buf);
			sprintf(codegen_buf, "for(int i%d = %s; i%d < %s; i%d++){\n\t%s(i%d) = %s(%s, %s + 1);\n%s\n}\n" /* NOTE fortran is [lower_bound, upper_bound] cpp is [lower_bound, upper_bound) */
				, sliceid, slice->child[sliceid]->child[0]->fs.CurrentTerm.what.c_str(), sliceid, slice->child[sliceid]->child[1]->fs.CurrentTerm.what.c_str(), sliceid
				, this_major[sliceid].c_str(), sliceid, prev_type_str.c_str(), slice->child[sliceid + 1]->child[0]->fs.CurrentTerm.what.c_str(), slice->child[sliceid + 1]->child[1]->fs.CurrentTerm.what.c_str()
				, sliceid + 1 == slice->child.size() - 1 ? "" : tabber(slice->child[sliceid + 1]->fs.CurrentTerm.what).c_str());
			prev_type_str = type_str;
			slice->child[sliceid]->fs.CurrentTerm.what = string(codegen_buf);
		}
		// use it in fucntion_decl
		//string var_pattern = gen_vardef_pattern(vardescattr, false);

		// no desc if var_def is not in paramtable
		sprintf(codegen_buf, "%s %s(%s, %s + 1);\n", type_str.c_str(), pn->child[i]->child[0]->fs.CurrentTerm.what.c_str() /* array name */
			, slice->child[0]->child[0]->fs.CurrentTerm.what.c_str(), slice->child[0]->child[1]->fs.CurrentTerm.what.c_str() /* slice from to */);
		arr_decl += codegen_buf;
		/* set initial value */
		if (pn->child[i]->child[1]->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER)
		{
			for (int abid = 0; abid < pn->child[i]->child[1]->child.size(); abid++)
			{
				ParseNode * ab = pn->child[i]->child[1]->child[abid];
				if (ab->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_VALUE) {
					std::string vec_size = "std::vector<int>{", vec_lb = "std::vector<int>{";
					for (int sliceid = 0; sliceid < slice->child.size(); sliceid++)
					{
						if (sliceid != 0) {
							vec_lb += ",";
							vec_size += ",";
						}
						vec_lb += slice->child[sliceid]->child[0]->fs.CurrentTerm.what;
						int lb, ub;
						sscanf(slice->child[sliceid]->child[0]->fs.CurrentTerm.what.c_str(), "%d", &lb);
						sscanf(slice->child[sliceid]->child[1]->fs.CurrentTerm.what.c_str(), "%d", &ub);
						sprintf(codegen_buf, "%d", ub - lb + 1);
						vec_size += codegen_buf;
					}
					vec_size += "}", vec_lb += "}";
					sprintf(codegen_buf, ab->fs.CurrentTerm.what.c_str() /*  "init_for1array(%%s, %%s, %%s, %s)\n" */
						, pn->child[i]->child[0]->fs.CurrentTerm.what.c_str() /* variable name */
						, vec_lb.c_str()
						, vec_size.c_str()
						, elem_type_str.c_str());
				}
				else if (ab->fs.CurrentTerm.token == TokenMeta::NT_ARRAYBUILDER_EXP) {
					string formatter = (ab->fs.CurrentTerm.what + ";\n");
					sprintf(codegen_buf, formatter.c_str(), pn->child[i]->child[0]->fs.CurrentTerm.what.c_str());
				}
				else {
					sprintf(codegen_buf, "");
				}
			}
		}
		else {
			sprintf(codegen_buf, "");
		}
		arr_decl += codegen_buf;
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
		sprintf(codegen_buf, gen_vardef_typestr(vardescattr).c_str(), spec_typename->fs.CurrentTerm.what.c_str());
		string typestr = string(codegen_buf);
		var_decl += typestr;
		bool hitted = false; // 是否至少有一个变量，因为有的变量定义可能是函数的声明，这在c++规范是不允许的，所以可能出现空int，空逗号的情况。
							 /* enumerate paramtable */
		// pn is flattened
		for (int i = 0; i < pn->child.size(); i++)
		{
			ParseNode * this_variable = new ParseNode(*pn->child[i]);
			// skip if it is a function
			// TODO no module currently
			if (try_get_function("", this_variable->fs.CurrentTerm.what)) {
				continue;
			}
			if (hitted) {
				var_decl += ", ";
			}
			hitted = true;

			sprintf(codegen_buf, "%s", this_variable->child[0]->fs.CurrentTerm.what.c_str());

			var_decl += codegen_buf;
			/* initial value */
			if (this_variable->child[1]->fs.CurrentTerm.token != TokenMeta::NT_VARIABLEINITIALDUMMY) {
				/* if initial value is not dummy but `exp` */
				var_decl += " = ";
				var_decl += this_variable->child[1]->fs.CurrentTerm.what;
			}
			/* desc */
			this_variable->attr = vardescattr->clone();
		}
		var_decl += ";";
		if (!hitted) {
			// all function declarations
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

