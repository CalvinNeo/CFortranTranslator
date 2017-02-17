#include "gen_common.h"

std::string gen_lbound_size_str(const std::tuple<std::vector<int>, std::vector<int>> & shape) {
	std::string size_str = "{", lbound_str = "{";
	lbound_str += make_str_list(get<0>(shape).begin(), get<0>(shape).end(), [&](auto x) {  return to_string(x); });
	size_str += make_str_list(get<1>(shape).begin(), get<1>(shape).end(), [&](auto x) { return to_string(x); });
	size_str += "}"; lbound_str += "}";
	return lbound_str + ", " + size_str;
}

std::tuple<std::vector<int>, std::vector<int>> gen_lbound_size(const ParseNode * slice) {
	if (slice == nullptr) {
		return make_tuple(std::vector<int>(), std::vector<int>());
	}
	std::vector<int> lb(slice->child.size()), sz(slice->child.size());
	if (slice->fs.CurrentTerm.token == TokenMeta::NT_ARGTABLE_PURE)
	{
		transform(slice->child.begin(), slice->child.end(), lb.begin(), [](const ParseNode * x) {
			return 1;
		});
		transform(slice->child.begin(), slice->child.end(), sz.begin(), [](const ParseNode * x) {
			int l; sscanf(x->fs.CurrentTerm.what.c_str(), "%d", &l);
			return l;
		});
	}
	else {
		transform(slice->child.begin(), slice->child.end(), lb.begin(), [](const ParseNode * x) {
			int l; sscanf(x->child[0]->fs.CurrentTerm.what.c_str(), "%d", &l);
			return l;
		});
		transform(slice->child.begin(), slice->child.end(), sz.begin(), [](const ParseNode * x) {
			int u; sscanf(x->child[1]->fs.CurrentTerm.what.c_str(), "%d", &u);
			int l; sscanf(x->child[0]->fs.CurrentTerm.what.c_str(), "%d", &l);
			return u - l + 1;
		});
	}
	return make_tuple(lb, sz);
}

std::string gen_vardef_array_str(VariableInfo * vinfo, std::string alias_name, ParseNode * entity_variable, const ParseNode & type_nospec, const std::tuple<std::vector<int>, std::vector<int>> & shape, VariableDescAttr & vardescattr) {
	string arr_decl = "";
	// entity_variable is 
	// NT_VARIABLEINITIAL(entity_variable) -> NT_EXPRESSION(entity_variable_name) -> NT_FUCNTIONARRAY -> (UnknownVariant, NT_ARGTABLE_PURE)/NT_VARIABLEINITIAL
	// or NT_VARIABLEINITIAL(entity_variable) -> (UnknownVariant, NT_VARIABLEINITIALDUMMY or else)
	int dimension = (int)get<0>(shape).size();
	if (alias_name == "")
	{
		alias_name = entity_variable->child[0]->fs.CurrentTerm.what;
	}
	string type_str;
	if (type_nospec.fs.CurrentTerm.what == "")
	{
		// implicit type
		sprintf(codegen_buf, "farray<%s>", implicit_type_from_name(alias_name).fs.CurrentTerm.what.c_str());
		type_str = string(codegen_buf);
	}
	else {
		type_str = gen_qualified_typestr(type_nospec, vardescattr.desc); // `T`
	}

	// no desc if var_def is not in paramtable
	sprintf(codegen_buf, "%s %s", type_str.c_str(), alias_name.c_str()  /* array name */);
	arr_decl += string(codegen_buf);
	if (entity_variable->child[1]->fs.CurrentTerm.token == TokenMeta::NT_VARIABLEINITIALDUMMY) {
		// default initialize
		if (get_context().parse_config.usefarray) {
			sprintf(codegen_buf, "{%s}", gen_lbound_size_str(shape).c_str()); // compile reckon "T a();" as function decl, so use `{}` 
			arr_decl += string(codegen_buf);
		}
		else {
			sprintf(codegen_buf, "(%d, %d)", get<0>(shape)[0], get<0>(shape)[0] + get<1>(shape)[0] + 1 /* slice from to */);
			arr_decl += string(codegen_buf);
		}
	}
	else {
		// init from array_builder
		sprintf(codegen_buf, "{%s};\n", gen_lbound_size_str(shape).c_str());
		arr_decl += string(codegen_buf);
		ParseNode * variable_initial = entity_variable;
		ParseNode * compound_arraybuilder = entity_variable->child[1]; // NT_ARRAYBUILDER
		gen_arraybuilder_str(*compound_arraybuilder);
		sprintf(codegen_buf, "%s = %s", alias_name.c_str(), compound_arraybuilder->fs.CurrentTerm.what.c_str());
		arr_decl += string(codegen_buf);
	}
	//VariableInfo vinfo = VariableInfo(type_str, vardescattr->desc, *(entity_variable->child[1]));
	entity_variable->attr = new VariableAttr(vardescattr.parsenode, vinfo);
	return arr_decl;
}

std::string get_variable_name(ParseNode * entity_variable) {
	ParseNode * entity_variable_name = entity_variable->child[0];
	if (entity_variable_name->fs.CurrentTerm.token == TokenMeta::NT_EXPRESSION && entity_variable_name->child[0]->fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY)
	{
		// entity_variable_name->child[0] has subobject designator like `A(0,1,2)`
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

std::string gen_vardef_scalar_str(VariableInfo * vinfo, ParseNode * entity_variable, const ParseNode & type_nospec, VariableDescAttr & vardescattr) {
	string var_decl; string typestr;
	ParseNode * entity_variable_name = entity_variable->child[0];
	if (type_nospec.fs.CurrentTerm.what == "")
	{
		// implicit type
		goto LABEL_DIMENSION_IMPLICIT;
	}
	typestr = gen_qualified_typestr(type_nospec, vardescattr.desc);
	// from entity_variable
	// NT_VARIABLEINITIAL(entity_variable) -> NT_EXPRESSION(entity_variable_name) -> NT_FUCNTIONARRAY -> (UnknownVariant, NT_ARGTABLE_PURE)
	if (entity_variable_name->fs.CurrentTerm.token == TokenMeta::NT_EXPRESSION && entity_variable_name->child[0]->fs.CurrentTerm.token == TokenMeta::NT_FUCNTIONARRAY)
	{
		LABEL_DIMENSION_IMPLICIT:
		ParseNode * argtable = entity_variable_name->child[0]->child[1];
		std::tuple<std::vector<int>, std::vector<int>> ls = gen_lbound_size(argtable);
		vardescattr.desc.slice = *argtable;
		var_decl = gen_vardef_array_str(vinfo, get_variable_name(entity_variable), entity_variable, type_nospec, ls, vardescattr);
	}
	else {
		sprintf(codegen_buf, "%s %s", typestr.c_str(), get_variable_name(entity_variable).c_str());
		var_decl = string(codegen_buf);
		if (entity_variable->child[1]->fs.CurrentTerm.token != TokenMeta::NT_VARIABLEINITIALDUMMY) {
			/* if initial value is not dummy but `exp` */
			var_decl += " = ";
			var_decl += entity_variable->child[1]->fs.CurrentTerm.what; // initial value
		}
	}
	entity_variable->attr = new VariableAttr(vardescattr.parsenode, vinfo);
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
	ParseNode kvparamtable = gen_promote_paramtable(paramtable); // a flatterned paramtable with all keyvalue elements
	ParseNode newnode = gen_token(Term{ TokenMeta::NT_VARIABLEDEFINESET, "LAZY GENERATED" });
	for (int i = 0; i < (int)kvparamtable.child.size(); i++)
	{
		ParseNode newvardef = ParseNode();
		newvardef.addchild(new ParseNode(type_nospec)); // type
		newvardef.addchild(variable_desc); // variable_desc
		newvardef.addchild(new ParseNode(*kvparamtable.child[i]));
		newvardef.attr = variable_desc.attr->clone(); // new VariableDescAttr( *dynamic_cast<VariableDescAttr *>(variable_desc.attr)); // attr
		newvardef.fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, "LAZY GENERATED" };
		newnode.addchild(new ParseNode(newvardef));
	}
	 //regen_vardef(newnode, nullptr);
	return newnode;
}

void regen_vardef(VariableInfo * vinfo, ParseNode & newnode, const ParseNode & type_nospec, ParseNode & vardescattr_node, ParseNode * entity_variable) {
	string var_decl = ""; 
	VariableDescAttr vardescattr = vardescattr_node.attr != nullptr ? *dynamic_cast<VariableDescAttr *>(vardescattr_node.attr) : VariableDescAttr(&vardescattr_node);
	VariableDesc & desc = vardescattr.desc;

	bool do_arr = desc.slice.is_initialized();
	if(do_arr){
		// ARRAY
		var_decl += gen_vardef_array_str(vinfo, "", entity_variable, type_nospec, gen_lbound_size(desc.slice.get_ptr()), vardescattr);
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, var_decl };
	}
	else {
		// SCALAR
		var_decl += gen_vardef_scalar_str(vinfo, entity_variable, type_nospec, vardescattr);
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, var_decl };
	} // end if
}
