#include "Class.h"

ToolArray::ToolArray(string PlayerName)
{
	m_ListOfTools = {};
	name = PlayerName;
	cout << "ToolArray constructor called" << endl;
}

ToolArray::~ToolArray()
{
	cout << "ToolArray destructor called" << endl;
}

void ToolArray::addTool(string f_tool)
{
	this->m_ListOfTools.push_back(f_tool);
}


vector<string>& ToolArray::getToolsList()
{
	return m_ListOfTools;
}

ostream& operator<<(ostream& os,ToolArray& tools)
{
	os << tools.name << ":" << endl;
	for (std::vector<string>::iterator toolList = tools.getToolsList().begin(); toolList != tools.getToolsList().end(); toolList++)
	{
		os << *toolList << endl;
	}
	return os;
}