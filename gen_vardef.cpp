#include "gen_common.h"

ParseNode gen_vardef(const ParseNode & type_spec, const ParseNode & variable_desc, const ParseNode & paramtable) {
	ParseNode newnode = ParseNode();
	string arr_decl = ""; string var_decl = ""; bool do_arr = false;
	ParseNode * ty = new ParseNode(type_spec); // type
	VariableDescAttr * vardescattr = dynamic_cast<VariableDescAttr *>(variable_desc.attr);
	ParseNode * slice = vardescattr->desc.slice;
	newnode.addchild(ty); // type
						   // specify type
						   /* merge type_spec and dummy_variable_iden attr */
	VariableDescAttr * ty_a = dynamic_cast<VariableDescAttr *>(type_spec.attr);
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
	if (slice == nullptr) {
		// slice == nullptr if this is not array
		/* must assure no ParseNode * is nullptr */
		slice = new ParseNode();
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_VOID, "" };
	}
	else {
		do_arr = true;
	}
	newnode.addchild(slice);
	ParseNode * pn = new ParseNode(paramtable); // paramtable
	newnode.addchild(pn); // paramtable
	if (do_arr)
	{
		// ARRAY
		/* in cpp code, definition of an array is inherit attribute(继承属性) grammar */
		/* enumerate paramtable */
		do {
			// for all non-flatterned paramtable
#define USE_LOOP
			for (int i = 0; i < pn->child.size(); i++)
			{
				// for each variable in flatterned paramtable
				int sliceid = 0;
				sprintf(codegen_buf, "forarray<%s>", ty->fs.CurrentTerm.what.c_str());
				string type_str(codegen_buf);
				// init high dimension array
				/* though using for-loop to init a high-dimension array is verbose comparing to using constructors, i use this form because it is more clear and it can remind users of the cost of using a high dimension array */
				vector<string> this_major; /* if you want to set value of a(i0)(i1)(i2) then this major is a(i0)(i1) */
				this_major.push_back(pn->child[i]->child[0]->fs.CurrentTerm.what /* array name */);
				for (int i = 1; i < slice->child.size(); i++)
				{
					sprintf(codegen_buf, "%s(i%d)", this_major.back().c_str(), i - 1);
					this_major.push_back(string(codegen_buf));
				}
				for (sliceid = slice->child.size() - 2; sliceid >= 0; sliceid--)
				{
					string prev_type_str = type_str;
					sprintf(codegen_buf, "forarray< %s >", type_str.c_str());
					type_str = string(codegen_buf);
					sprintf(codegen_buf, "for(int i%d = %s; i%d < %s; i%d++){\n\t%s(i%d) = %s(%s, %s + 1);\n%s\n}\n" /* NOTE fortran is [lower_bound, upper_bound] cpp is [lower_bound, upper_bound) */
						, sliceid, slice->child[sliceid]->child[0]->fs.CurrentTerm.what.c_str(), sliceid, slice->child[sliceid]->child[1]->fs.CurrentTerm.what.c_str(), sliceid
						, this_major[sliceid].c_str(), sliceid, prev_type_str.c_str(), slice->child[sliceid + 1]->child[0]->fs.CurrentTerm.what.c_str(), slice->child[sliceid + 1]->child[1]->fs.CurrentTerm.what.c_str()
						, sliceid + 1 == slice->child.size() - 1 ? "" : tabber(slice->child[sliceid + 1]->fs.CurrentTerm.what).c_str());
					prev_type_str = type_str;
					slice->child[sliceid]->fs.CurrentTerm.what = string(codegen_buf);
				}
				// use it in fucntion_decl
				string var_pattern;
				if (vardescattr->desc.reference) {
					if (vardescattr->desc.constant) {
						var_pattern = "const %s & %s";
					}
					else {
						var_pattern = "%s & %s";
					}
				}
				else {
					if (vardescattr->desc.constant) {
						var_pattern = "const %s %s";
					}
					else {
						var_pattern = "%s %s";
					}
				}
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
							sprintf(codegen_buf, ab->fs.CurrentTerm.what.c_str() /* sth like "init_for1array(%%s, %%s, %%s, %s)\n" */
								, pn->child[i]->child[0]->fs.CurrentTerm.what.c_str() /* variable name */
								, vec_lb.c_str()
								, vec_size.c_str());
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
			if (pn->child.size() >= 2)
			{
				/* if pn->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
				/* if the paramtable is not flatterned pn->child[1] is a right-recursive paramtable node */
				pn = pn->child[1];
			}
		} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, arr_decl };
	}
	else {
		// SCALAR
		sprintf(codegen_buf, "%s ", ty->fs.CurrentTerm.what.c_str());
		var_decl += string(codegen_buf);
		bool hitted = false; // 是否至少有一个变量，因为有的变量定义可能是函数的声明，这在c++规范是不允许的，所以可能出现空int，空逗号的情况。
							 /* enumerate paramtable */
		do {
			// for all non-flatterned paramtable
			for (int i = 0; i < pn->child.size(); i++)
			{
				ParseNode * this_variable = pn->child[i];
				// skip if it is a function
				// TODO no module currently
				if (try_get_function("", this_variable->fs.CurrentTerm.what)) {
					continue;
				}
				if (hitted) {
					var_decl += ", ";
				}
				hitted = true;
				// use it in fucntion_decl
				string var_pattern;
				if (vardescattr->desc.reference) {
					if (vardescattr->desc.constant) {
						var_pattern = "const & %s";
					}
					else {
						var_pattern = "& %s";
					}
				}
				else {
					if (vardescattr->desc.constant) {
						var_pattern = "const %s";
					}
					else {
						var_pattern = "%s";
					}
				}
				// no desc if var_def is not in paramtable
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
			if (pn->child.size() >= 2)
			{
				/* if pn->child.size() == 0, this is an empty paramtable(this function takes no arguments) */
				/* if the paramtable is not flatterned pn->child[1] is a right-recursive paramtable node */
				pn = pn->child[1];
			}
		} while (pn->child.size() == 2 && pn->child[1]->fs.CurrentTerm.token == TokenMeta::NT_PARAMTABLE);
		var_decl += ";";
		if (!hitted) {
			// all function declarations
			var_decl = "";
		}

#ifndef LAZY_GEN
		newnode.fs.CurrentTerm = Term{ TokenMeta::NT_VARIABLEDEFINE, var_decl };
#endif // !LAZY_GEN
	} // end if
	return newnode;
}

