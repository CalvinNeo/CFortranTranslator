#include "gen_common.h"

std::string gen_lbound_size_str(const std::tuple<std::vector<int>, std::vector<int>> & shape) {
	std::string size_str = "{", lbound_str = "{";
	lbound_str += make_str_list(get<0>(shape).begin(), get<0>(shape).end(), [&](auto x) {  return to_string(x); });
	size_str += make_str_list(get<1>(shape).begin(), get<1>(shape).end(), [&](auto x) { return to_string(x); });
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

std::string gen_vardef_array_str(ParseNode * entity_variable, const ParseNode & type_spec, const std::tuple<std::vector<int>, std::vector<int>> & shape, VariableDescAttr * vardescattr) {
	return gen_vardef_array_str(entity_variable->child[0]->fs.CurrentTerm.what.c_str(), entity_variable, type_spec, shape, vardescattr);
}
std::string gen_vardef_array_str(std::string alias_name, ParseNode * entity_variable, const ParseNode & type_spec, const std::tuple<std::vector<int>, std::vector<int>> & shape, VariableDescAttr * vardescattr) {
	string arr_decl = "";
	// entity_variable is 
	// NT_VARIABLEINITIAL(entity_variable) -> NT_EXPRESSION(entity_variable_name) -> NT_FUCNTIONARRAY -> (UnknownVariant, NT_ARGTABLE_PURE)/NT_VARIABLEINITIAL
	// or NT_VARIABLEINITIAL(entity_variable) -> (UnknownVariant, NT_VARIABLEINITIALDUMMY or else)
	int dimension = (int)get<0>(shape).size();
	string type_str;
	string innermost_typestr = gen_qualified_typestr(type_spec.fs.CurrentTerm.what, vardescattr == nullptr? VariableDesc() : vardescattr->desc); // `T`
	if (parse_config.usefarray) {
		sprintf(codegen_buf, "farray<%s>", innermost_typestr.c_str());
		type_str = string(codegen_buf);
	}
	else {
		sprintf(codegen_buf, "for1array<%s>", innermost_typestr.c_str());
		type_str = string(codegen_buf);
		for (int sliceid = dimension - 2; sliceid >= 0; sliceid--)
		{
			sprintf(codegen_buf, "for1array<%s>", type_str.c_str());
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
	VariableInfo vinfo = VariableInfo(alias_name, vardescattr->desc, *(entity_variable->child[1]));
	entity_variable->attr = new VariableAttr(vardescattr->parsenode, add_variable("@", "@", alias_name, vinfo));
	return arr_decl;
}

std::string get_variable_name(ParseNode * entity_variable) {
	ParseNode * entity_variable_name = entity_variable->child[0];
	if (entity_variable_name->fs.CurrentTerm.token == TokenMeta::NT_EXPRESSION && entity_variable_name->child[0]->fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY)
	{
		// entity_variable_name->child[0] is like `A(0,1,2)`
		return entity_variable_name->child[0]->child[0]->fs.CurrentTerm.what;
	}
	//else if (entity_variable_name->fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY) {
	//	// 在common部分不能满足上面的规则
	//	return entity_variable_name->child[0]->fs.CurrentTerm.what;
	//}
	else {
		// entity_variable_name->child[0] is like `A`
		return entity_variable_name->fs.CurrentTerm.what;
	}
}

std::string gen_vardef_scalar_str(ParseNode * entity_variable, const ParseNode & type_spec, VariableDescAttr * vardescattr) {
	string var_decl;
	ParseNode * entity_variable_name = entity_variable->child[0];
	// from entity_variable
	// NT_VARIABLEINITIAL(entity_variable) -> NT_EXPRESSION(entity_variable_name) -> NT_FUCNTIONARRAY -> (UnknownVariant, NT_ARGTABLE_PURE)
	if (entity_variable_name->fs.CurrentTerm.token == TokenMeta::NT_EXPRESSION && entity_variable_name->child[0]->fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY)
	{
		ParseNode * argtable = entity_variable_name->child[0]->child[1];
		std::vector<int> lb(argtable->child.size()), sz(argtable->child.size());
		std::fill(lb.begin(), lb.end(), 1);
		std::transform(argtable->child.begin(), argtable->child.end(), sz.begin(), [](auto x) {
			int y;  sscanf(x->fs.CurrentTerm.what.c_str(), "%d", &y); return y; 
		});
		var_decl = gen_vardef_array_str(get_variable_name(entity_variable), entity_variable, type_spec, make_tuple(lb, sz), vardescattr);
	}
	else {
		var_decl += get_variable_name(entity_variable);
		if (entity_variable->child[1]->fs.CurrentTerm.token != TokenMeta::NT_VARIABLEINITIALDUMMY) {
			/* if initial value is not dummy but `exp` */
			var_decl += " = ";
			var_decl += entity_variable->child[1]->fs.CurrentTerm.what; // initial value
		}
	}
	/* attr */
	VariableInfo vinfo(entity_variable_name->fs.CurrentTerm.what, vardescattr->desc, *(entity_variable->child[1]));
	VariableInfo * itt = add_variable("@", "@", entity_variable_name->fs.CurrentTerm.what, vinfo);
	entity_variable->attr = new VariableAttr(vardescattr->parsenode, itt);
	//entity_variable->attr = vardescattr->clone();
	return var_decl;
}

ParseNode gen_vardef_simple(const ParseNode & type, std::string name) {
	ParseNode newnode = ParseNode(gen_flex(Term{ TokenMeta::NT_VARIABLEDEFINE, name }), nullptr);
	newnode.addchild(new ParseNode(type)); // type
	newnode.addchild(new ParseNode(gen_flex(Term{ TokenMeta::NT_VOID, "" }), nullptr)); // variable_desc
	ParseNode kv = gen_keyvalue(gen_token(Term{ TokenMeta::UnknownVariant, name }));
	ParseNode pt = gen_paramtable(kv);
	newnode.addchild(new ParseNode(pt)); // type
	return newnode;
}

ParseNode gen_vardef(const ParseNode & type_nospec, const ParseNode & variable_desc, const ParseNode & paramtable) {
	//ParseNode kvparamtable = gen_promote_paramtable(paramtable); // a flatterned paramtable with all keyvalue elements
	//ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDEFINESET, "LAZY GENERATED" });
	//for (int i = 0; i < (int)kvparamtable.child.size(); i++)
	//{
	//	ParseNode newvardef = ParseNode();
	//	newvardef.addchild(new ParseNode(type_nospec)); // type
	//	newvardef.addchild(variable_desc); // variable_desc
	//	newvardef.addchild(new ParseNode(*kvparamtable.child[i]));
	//	newvardef.attr = new VariableDescAttr(*dynamic_cast<VariableDescAttr *>(variable_desc.attr)); // attr
	//	newvardef.fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, "LAZY GENERATED" };
	//}
	// //regen_vardef(newnode, nullptr);
	//return newnode;
	ParseNode newnode = ParseNode();
	newnode.addchild(new ParseNode(type_nospec)); // type
	newnode.addchild(variable_desc); // variable_desc
	newnode.addchild(new ParseNode(gen_promote_paramtable(paramtable))); // a flatterned paramtable with all keyvalue elements
	newnode.attr = new VariableDescAttr(*dynamic_cast<VariableDescAttr *>(variable_desc.attr)); // attr
	newnode.fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, "LAZY GENERATED" };
	return newnode;
	//regen_vardef(newnode, nullptr);
}

void regen_vardef(ParseNode & newnode, const ParseNode & type_nospec, const ParseNode & vardescattr_node, ParseNode * entity_variable) {
	string var_decl = ""; bool do_arr = false;
	VariableDescAttr * vardescattr = dynamic_cast<VariableDescAttr *>(vardescattr_node.attr);
	ParseNode * slice = vardescattr->desc.slice;
	ParseNode type_spec = promote_type(type_nospec, vardescattr == nullptr ? VariableDesc() : vardescattr->desc); // reset type according to kind

	if (slice == nullptr) {
		// slice == nullptr if this is not array
		/* must assure no ParseNode * is nullptr */
		slice = new ParseNode(gen_flex(Term{ TokenMeta::NT_VOID, "" }), nullptr);
	}
	else {
		do_arr = true;
	}
	if (do_arr)
	{
		// ARRAY
		var_decl += gen_vardef_array_str(entity_variable, type_spec, gen_lbound_size(slice), vardescattr);
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, var_decl };
	}
	else {
		// SCALAR
		string typestr = gen_qualified_typestr(type_spec.fs.CurrentTerm.what, vardescattr == nullptr ? VariableDesc() : vardescattr->desc);
		var_decl += typestr;
		var_decl += gen_vardef_scalar_str(entity_variable, type_spec, vardescattr);
		var_decl += ";";
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, var_decl };
	} // end if
}
