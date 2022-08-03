/*
*   Calvin Neo
*   Copyright (C) 2016  Calvin Neo <calvinneo@calvinneo.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along
*   with this program; if not, write to the Free Software Foundation, Inc.,
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "gen_common.h"
#include <boost/algorithm/string.hpp>

/*
R202 program-unit is main-program
	or external-subprogram (in gen_function.cpp)
	or module (not supported)
	or block-data
*/

void gen_fortran_program(const ParseNode & wrappers) {
	std::string codes;
	std::string main_code;
	get_context().program_tree = wrappers;

	FunctionInfo * program_info = add_function("", "program", FunctionInfo());
	ParseNode script_program = gen_token(Term{ TokenMeta::NT_SUITE , "" });

    typedef struct module_info{
        bool is_set = false;
        std::string module_name;
        std::string module_code;
        FunctionInfo * outer_info = nullptr;
        ParseNode script_outer = gen_token(Term{ TokenMeta::NT_SUITE , "" });
        std::vector<ParseNode *> func_decls_in_module;
        std::vector<ParseNode *> type_decls_in_module;
    }ModuleInfo;

    ModuleInfo minfo;


	for (ParseNode * wrapper_ptr : get_context().program_tree)
	{
		ParseNode & wrapper = *wrapper_ptr;
		if (wrapper.token_equals(TokenMeta::NT_SUITE))
		{
			for (int j = 0; j < wrapper.length(); j++)
			{
				script_program.addchild(wrapper.get(j));
			}
		}
		else if (wrapper.token_equals(TokenMeta::NT_PROGRAM_EXPLICIT))
		{
			for (int j = 0; j < wrapper.get(0).length(); j++)
			{
				script_program.addchild(wrapper.get(0).get(j));
			}
		}
		else if (wrapper.token_equals(TokenMeta::NT_FUNCTIONDECLARE))
		{
			get_context().current_module = "";
			ParseNode & variable_function = wrapper.get(1);
			/************
			* IMPORTANT
			* MUST call `add_function` to all functions
			*	, before actually call `regen_function` or `regen_vardef` to any of the functions
			*************/
			FunctionInfo * finfo = add_function(get_context().current_module, variable_function.get_what(), FunctionInfo{});
		}
        else if (wrapper.token_equals(TokenMeta::NT_MODULE))
        {
            minfo.is_set=true;
            minfo.outer_info = add_function(wrapper.get_what(),"",FunctionInfo{});
            minfo.module_name = wrapper.get_what();
            ModuleInfo &minfo_alias = minfo;
            get_context().current_module = minfo.module_name;
            for (int j = 0; j < wrapper.get(0).length(); j++)
            {
                ParseNode &node = wrapper.get(0).get(j);
                if (node.token_equals(TokenMeta::NT_FUNCTIONDECLARE))
                {
                    minfo_alias.func_decls_in_module.push_back(&node);
                    add_function(get_context().current_module, node.get(1).get_what(),FunctionInfo{});
                }
                else if (node.token_equals(TokenMeta::NT_DERIVED_TYPE))
                {
                    minfo_alias.type_decls_in_module.push_back(&node);
                    add_type(get_context().current_module, node.get(0).get_what(),TypeInfo{});
                }
                /* function and type definition individually processed in `minfo`,
                 * code other than those goes to `script_outer` and will be `regen_suite`ed */
                else
                    minfo_alias.script_outer.addchild(wrapper.get(0).get(j));
            }
        }
		else if (wrapper.token_equals(TokenMeta::NT_DERIVED_TYPE))
		{
			get_context().current_module = "";
			ParseNode& variable_type = wrapper.get(0);
			TypeInfo* tinfo = add_type(get_context().current_module, variable_type.get_what(), TypeInfo{});
		}
		else if (wrapper.token_equals(TokenMeta::NT_DUMMY))
		{
			// YY_END
		}
		else {
			print_error("Unexpected wrappers");
		}
	}

	// regen all subprogram's step 1: generate subprogram's code
	// create function, generate function body
	get_context().current_module = "";
	for (ParseNode * wrapper_ptr : get_context().program_tree)
	{
		ParseNode & wrapper = *wrapper_ptr;
		if(wrapper.token_equals(TokenMeta::NT_FUNCTIONDECLARE))
		{
			ParseNode & variable_function = wrapper.get(1);
			FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
			regen_function_1(finfo, wrapper);
		}
		else if (wrapper.token_equals(TokenMeta::NT_DERIVED_TYPE))
		{
			ParseNode& variable_type = wrapper.get(0);
			TypeInfo* tinfo = get_type(get_context().current_module, variable_type.get_what());
			regen_derived_type_1(tinfo, wrapper);
			//regen_function_1(tinfo, wrapper);
		}
	}

    /* function and type collected from inside module is treated as normal outermost definition, but with assigned module name*/
    if(minfo.is_set)
    {
        get_context().current_module = minfo.module_name;
        std::vector<ParseNode *> &func_decls_in_module = minfo.func_decls_in_module;
        if (!func_decls_in_module.empty())
        {
            for (ParseNode *nodeptr:func_decls_in_module)
            {
                ParseNode &node = *nodeptr;
                ParseNode & variable_function = node.get(1);
                FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
                regen_function_1(finfo, node);
            }
        }
        std::vector<ParseNode *> &type_decls_in_module = minfo.type_decls_in_module;
        if(!type_decls_in_module.empty())
        {
            for(ParseNode *nodeptr:type_decls_in_module)
            {
                ParseNode & variable_type = nodeptr->get(0);
                TypeInfo *tinfo = get_type(get_context().current_module,variable_type.get_what());
                regen_derived_type_1(tinfo, *nodeptr);
            }
        }
    }

    // main program code
    get_context().current_module = "";
    regen_suite(program_info, script_program);
    if(minfo.is_set)
    {
        get_context().current_module = minfo.module_name;
        regen_suite(minfo.outer_info,minfo.script_outer);
    }
    get_context().current_module = "";

	// regen common definition
	// this MUST before generate subprogram's code(`regen_function_2`), ref `regen_function_2` for reason
	// if you move this code block under the "regen all subprogram's step 2" block, errors will occur when processing file *For3d14.for*
	std::string common_decls;
	for (std::map<std::string, CommonBlockInfo *>::value_type & pr : get_context().commonblocks)
	{
		string s = gen_common_definition(pr.first).get_what();
		common_decls += s;
	}

	// regen all subprogram's step 2: generate subprogram's code
	// generate function signature
    assert( get_context().current_module == "");
	for (ParseNode * wrapper_ptr : get_context().program_tree)
	{
		ParseNode & wrapper = *wrapper_ptr;
		if (wrapper.token_equals(TokenMeta::NT_FUNCTIONDECLARE))
		{
			ParseNode & variable_function = wrapper.get(1);
			FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
			regen_function_2(finfo);
			codes += finfo->node->get_what();
			codes += "\n";
		}
		//else if (wrapper.token_equals(TokenMeta::NT_DERIVED_TYPE))
		//{
		//	ParseNode& variable_type = wrapper.get(0);
		//	//ParseNode& suite = wrapper.get(1);
		//	TypeInfo* tinfo = get_type(get_context().current_module, variable_type.get_what());
		//	regen_derived_type_2(tinfo);
		//	codes += tinfo->node->get_what();
		//	//codes += "struct " + variable_type.get_what() + "\n";
		//	//codes += suite.get_what();
		//	codes += "\n";
		//}
	}
    if(minfo.is_set)
    {
        get_context().current_module = minfo.module_name;
        std::vector<ParseNode *> &func_decls_in_module = minfo.func_decls_in_module;
        if (!func_decls_in_module.empty())
        {
            for (ParseNode *nodeptr:func_decls_in_module)
            {
                ParseNode &node = *nodeptr;
                ParseNode & variable_function = node.get(1);
                FunctionInfo * finfo = get_function(get_context().current_module, variable_function.get_what());
                regen_function_2(finfo);
                codes += "#ifndef "+minfo.module_name+"_"+finfo->local_name+"\n";
                codes += "#define "+minfo.module_name+"_"+finfo->local_name+"\n";
                codes += finfo->node->get_what();
                codes += "\n";
                codes += "#endif\n";
            }
        }
    }

    get_context().current_module = "";
	for (TypeInfo * tinfo : get_context().types_vec)
	{
			regen_derived_type_2(tinfo);
            if(minfo.is_set && std::find(minfo.type_decls_in_module.begin(), minfo.type_decls_in_module.end(),tinfo->node)!=minfo.type_decls_in_module.end())
            {/**/
                codes += "#ifndef "+minfo.module_name+"_"+tinfo->local_name+"\n";
                codes += "#define "+minfo.module_name+"_"+tinfo->local_name+"\n";
                codes += tinfo->node->get_what();
                codes += "\n";
                codes += "#endif\n";
            }else
            {
                codes += tinfo->node->get_what();
                codes += "\n";
            }
    }

    // main program code
	regen_all_variables_decl_str(program_info, script_program);
	main_code = tabber(script_program.get_what());
    sprintf(codegen_buf, "int main()\n{\n%s\treturn 0;\n}", main_code.c_str());
    main_code = codegen_buf;
    boost::trim(script_program.get_what());
    if(!script_program.get_what().empty())
        codes+=main_code;
    if(minfo.is_set)
    {
        get_context().current_module = minfo.module_name;
        regen_all_variables_decl_str(minfo.outer_info,minfo.script_outer);
        minfo.module_code = minfo.script_outer.get_what();
        sprintf(codegen_buf, "#ifndef %s\n#define %s\n%s\n#endif\n", minfo.module_name.c_str(),minfo.module_name.c_str(),minfo.module_code.c_str());
    }
	codes += string(codegen_buf);

	// forward declarations
    get_context().current_module = "";
	std::string forward_decls;
	forall_function_in_module("", [&](std::pair<std::string , FunctionInfo * > pr) {
		FunctionInfo * finfo;
		std::tie(std::ignore, finfo) = pr;
		std::string name = finfo->local_name;
		if (name != "program" && name != "")
		{
			forward_decls += gen_function_signature(finfo);
			forward_decls += ";\n";
		}
        if(!finfo->func_alias.empty())
        {
            for(std::string sig: gen_func_alias_signature(finfo))
            {
                forward_decls += sig;
                forward_decls += ";\n";
            }
        }
    });

    get_context().current_module = minfo.module_name;
    forall_function_in_module(get_context().current_module, [&](std::pair<std::string , FunctionInfo * > pr) {
        FunctionInfo * finfo;
        std::tie(std::ignore, finfo) = pr;
        std::string name = finfo->local_name;
        if (name != "program" && name != "")
        {
            forward_decls += gen_function_signature(finfo);
            forward_decls += ";\n";
            if(!finfo->func_alias.empty())
            {
                for(std::string sig: gen_func_alias_signature(finfo))
                {
                    forward_decls += sig;
                    forward_decls += ";\n";
                }
            }
        }
    });
    get_context().current_module = "";

    /*construct use statements, i.e., `#include "module name"` after conversion*/
    std::string use_statements;
    for(ParseNode* incl:program_info->use_stmts){
        use_statements += incl->get_what();
        use_statements += "\n";
    }
    for(ParseNode* incl:minfo.outer_info->use_stmts){
        use_statements += "#ifndef " + minfo.module_name + "\n";
        use_statements += "#define " + minfo.module_name + "\n";
        use_statements += incl->get_what();
        use_statements += "\n";
        use_statements += "#endif\n";
    }

	/************
	* PROGRAM STRUCTURE
	*
	* common blocks
	* forward function decls
	* function definitions
	* the `main` program
	*************/
    codes = use_statements + codes;
	codes = forward_decls + codes;
	codes = common_decls + codes;

	get_context().program_tree.get_what() = codes;
}