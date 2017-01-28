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

std::string gen_lbound_size_str(const std::tuple<std::vector<int>, std::vector<int>> & shape) {
	std::string size_str = "{", lbound_str = "{";
	lbound_str += make_str_list(get<0>(shape).begin(), get<0>(shape).end(), [&](auto x) {
		sprintf(codegen_buf, "%d", *x); return string(codegen_buf);
	});
	size_str += make_str_list(get<1>(shape).begin(), get<1>(shape).end(), [&](auto x) {
		sprintf(codegen_buf, "%d", *x); return string(codegen_buf);
	});
	size_str += "}"; lbound_str += "}";
	return lbound_str + ", " + size_str;
}

std::tuple<std::vector<int>, std::vector<int>> gen_lbound_size(const ParseNode * slice) {
	std::vector<int> lb(slice->child.size()), sz(slice->child.size());
	transform(slice->child.begin(), slice->child.end(), lb.begin(), [](const ParseNode * x) {
		int l; sscanf(x->child[0]->fs.CurrentTerm.what.c_str(), "%d", &l);
		return l;
	});
	transform(slice->child.begin(), slice->child.end(), sz.begin(), [](const ParseNode * x) {
		int u; sscanf(x->child[1]->fs.CurrentTerm.what.c_str(), "%d", &u);
		int l; sscanf(x->child[0]->fs.CurrentTerm.what.c_str(), "%d", &l);
		return u - l + 1;
	});
	return make_tuple(lb, sz);
}

std::string gen_vardef_array_initial(ParseNode * entity_variable, ParseNode * slice) {
	/* set initial value from array_builder */
	/* entity_variable is NT_VARIABLEINITIAL = NT_KEYVALUE*/
	string arr_decl;

	return arr_decl;
}

std::string gen_vardef_array(ParseNode * entity_variable, ParseNode * spec_typename, const std::tuple<std::vector<int>, std::vector<int>> & shape, VariableDescAttr * vardescattr) {
	return gen_vardef_array(entity_variable->child[0]->fs.CurrentTerm.what.c_str(), entity_variable, spec_typename, shape, vardescattr);
}
std::string gen_vardef_array(std::string alias_name, ParseNode * entity_variable, ParseNode * spec_typename, const std::tuple<std::vector<int>, std::vector<int>> & shape, VariableDescAttr * vardescattr) {
	/* in cpp code, definition of an array is inherit attribute(继承属性) grammar */
	string arr_decl = "";
	// entity_variable is 
	// NT_VARIABLEINITIAL(entity_variable) -> NT_EXPRESSION(entity_variable_name) -> NT_FUCNTIONARRAY -> (UnknownVariant, NT_ARGTABLE_PURE) or NT_VARIABLEINITIAL
	// or NT_VARIABLEINITIAL(entity_variable) -> (UnknownVariant, NT_VARIABLEINITIALDUMMY or else)
	int sliceid = 0;
	int dimension = get<0>(shape).size();
	string type_str;
	string innermost_type = gen_qualified_typestr(spec_typename->fs.CurrentTerm.what, vardescattr); // `T`
	if (parse_config.usefarray) {
		sprintf(codegen_buf, "farray<%s>", innermost_type.c_str());
		type_str = string(codegen_buf);
	}
	else {
		sprintf(codegen_buf, "for1array<%s>", innermost_type.c_str());
		type_str = string(codegen_buf);
		for (sliceid = dimension - 2; sliceid >= 0; sliceid--)
		{
			sprintf(codegen_buf, "for1array< %s >", type_str.c_str());
			type_str = string(codegen_buf);
		}
	}

	// no desc if var_def is not in paramtable
	sprintf(codegen_buf, "%s %s", type_str.c_str(), alias_name.c_str()  /* array name */);
	arr_decl += string(codegen_buf);
	if (entity_variable->child[1]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEINITIALDUMMY) {
		// default initialize
		if (parse_config.usefarray) {
			sprintf(codegen_buf, "{%s};", gen_lbound_size_str(shape).c_str()); // compile reckon "T a();" as function decl, so use `{}` 
			arr_decl += string(codegen_buf);
		}
		else {
			sprintf(codegen_buf, "(%d, %d)", get<0>(shape)[0], get<0>(shape)[0] + get<1>(shape)[0] + 1 /* slice from to */);
			arr_decl += string(codegen_buf);
			arr_decl += ";";
		}
	}
	else {
		// init from array_builder
		sprintf(codegen_buf, "{%s};\n", gen_lbound_size_str(shape).c_str());
		arr_decl += string(codegen_buf);
		sprintf(codegen_buf, "%s = ", alias_name.c_str());
		arr_decl += string(codegen_buf);
		ParseNode * variable_initial = entity_variable;
		ParseNode * compound_arraybuilder = entity_variable->child[1]; // NT_ARRAYBUILDER

		gen_arraybuilder_str(*compound_arraybuilder);
		arr_decl += compound_arraybuilder->fs.CurrentTerm.what;
		arr_decl += ";";
	}
	arr_decl += "\n";
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
		for (auto i = 0; i < pn->child.size(); i++)
		{
			// pn is flattened
			arr_decl += gen_vardef_array(pn->child[i], spec_typename, gen_lbound_size(slice), vardescattr);
		}
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, arr_decl };
	}
	else {
		// SCALAR
		string typestr = gen_qualified_typestr(spec_typename->fs.CurrentTerm.what, vardescattr);
		var_decl += typestr;
		bool hitted = false; // 是否至少有一个变量，因为有的变量定义可能是函数的声明，这在c++规范是不允许的，所以可能出现空int，空逗号的情况。
		// pn is flattened, for each variable in flatterned paramtable
		for (auto i = 0; i < pn->child.size(); i++)
		{
			ParseNode * entity_variable = pn->child[i];
			// skip if it is a function, no module currently
			if (get_function("", entity_variable->fs.CurrentTerm.what)) {
				continue;
			}
			if (hitted) {
				var_decl += ", ";
			}
			hitted = true;

			ParseNode * entity_variable_name = entity_variable->child[0];
			// from entity_variable
			// NT_VARIABLEINITIAL(entity_variable) -> NT_EXPRESSION(entity_variable_name) -> NT_FUCNTIONARRAY -> (UnknownVariant, NT_ARGTABLE_PURE)
			if (entity_variable_name->fs.CurrentTerm.token == TokenMeta::NT_EXPRESSION && entity_variable_name->child[0]->fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY)
			{
				ParseNode * argtable = entity_variable_name->child[0]->child[1];
				std::vector<int> lb(argtable->child.size()), sz(argtable->child.size());
				std::fill(lb.begin(), lb.end(), 1);
				std::transform(argtable->child.begin(), argtable->child.end(), sz.begin(), [](auto x) {
					int y;  sscanf(x->fs.CurrentTerm.what.c_str(), "%d", &y);
					return y;
				});
				var_decl = gen_vardef_array(entity_variable_name->child[0]->child[0]->fs.CurrentTerm.what, entity_variable, spec_typename, make_tuple(lb, sz), vardescattr);
			}
			else {
				var_decl += entity_variable_name->fs.CurrentTerm.what;
				if (entity_variable->child[1]->fs.CurrentTerm.token != TokenMeta::NT_VARIABLEINITIALDUMMY) {
					/* if initial value is not dummy but `exp` */
					var_decl += " = ";
					var_decl += entity_variable->child[1]->fs.CurrentTerm.what;
				}
				var_decl += ";";
			}
			/* desc */
			entity_variable->attr = vardescattr->clone();
		}
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
