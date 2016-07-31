#pragma once
#include <string>
#include <vector>
template<struct VART>

struct VariablePanel
{
public:
	VART & GetOwnVar(const std::string &);
	virtual VART AddVariable(class Variable *, bool insert_into_global = true);

	vector<VART> All;
	VART HolderVar;

	VariablePanel * Upper;//…œ“ªº∂
};