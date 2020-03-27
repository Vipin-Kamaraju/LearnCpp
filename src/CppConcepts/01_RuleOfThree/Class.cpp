#include "Class.h"

ToolArray::ToolArray()
{
	m_ListOfTools = {};
}

ToolArray::~ToolArray()
{
}

void ToolArray::addTool(string f_tool)
{
	this->m_ListOfTools.push_back(f_tool);
}


vector<string>& ToolArray::getToolsList()
{
	return m_ListOfTools;
}