#include "Class.h"

// Default Constructor
ToolArray::ToolArray() : name("Unknown"), m_ListOfTools({ "candle" })
{
	cout << "Default constructor is called" << endl;
}

// Overloaded constructor
ToolArray::ToolArray(string PlayerName)
{
	m_ListOfTools = {};
	name = PlayerName;
	cout << "ToolArray overloaded constructor called" << endl;
}

// destructor
ToolArray::~ToolArray()
{
	cout << "ToolArray destructor called" << endl;
}

//Copy Constructor
ToolArray::ToolArray(const ToolArray& source)
{
	cout << "Copy Constructor is called" << endl;
}

// Overloaded Assignment Operator
ToolArray& ToolArray::operator=(const ToolArray& source)
{
	cout << "Overloaded assignment operator called" << endl;
	ToolArray destination;

	return destination;
}

void ToolArray::addTool(string f_tool)
{
	this->m_ListOfTools.push_back(f_tool);
}


vector<string>& ToolArray::getToolsList()
{
	return m_ListOfTools;
}


// Overloaded operator for cout
ostream& operator<<(ostream& os,ToolArray& tools)
{
	os << tools.name << ":" << endl;
	for (std::vector<string>::iterator toolList = tools.getToolsList().begin(); toolList != tools.getToolsList().end(); toolList++)
	{
		os << *toolList << endl;
	}
	return os;
}