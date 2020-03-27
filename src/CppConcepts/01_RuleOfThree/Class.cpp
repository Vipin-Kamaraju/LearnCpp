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

ostream& operator<<(ostream& os, ToolArray& tools)
{
	for (std::vector<string>::iterator toolList = tools.getToolsList().begin(); toolList != tools.getToolsList().end(); toolList++)
	{
		os << *toolList << endl;
	}
}