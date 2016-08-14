#pragma once
#include <string>
#include <vector>

struct VariablePanel
{
	struct Variable * GetVariable(const std::string &);
	void AddVariable(Variable *, bool insert_into_global = true);
	std::vector<Variable> MemberVariables;
	Variable * HolderVariable;
	VariablePanel * Upper;//…œ“ªº∂

};

struct Variable
{
public:
	int name;
	void * value;

	VariablePanel * HolderPanel;
	VariablePanel * MemberPanel;
};

Variable * get_panel_variable(const std::string &); // return observer
Variable * get_literal_variable(const struct Term & ); // return observer

extern VariablePanel program_panel;