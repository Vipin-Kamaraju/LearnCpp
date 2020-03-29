#include "Class.h"

// Default Constructor
ToolArray::ToolArray() : name("Unknown")
{
	cout << "Default constructor is called" << endl;
}

// Overloaded constructor
ToolArray::ToolArray(string PlayerName)
{
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

	name = source.name; // Same as this->name = source.name;

	// Is this a shallow copy or deep copy?
	// copy(source.m_ListOfTools.begin(), source.m_ListOfTools.end(), m_ListOfTools.begin());
	m_ListOfTools = source.m_ListOfTools;
}

// Overloaded Assignment Operator
ToolArray& ToolArray::operator=(const ToolArray& source)
{
	cout << "Overloaded assignment operator called" << endl;
	
	// Check for self assignment
	if (this == &source)
	{
		return *this;
	}
	this->name = source.name; // Same as this->name = source.name;

	// Is this a shallow copy or deep copy?
	copy(source.m_ListOfTools.begin(), source.m_ListOfTools.end(), m_ListOfTools.begin());
	//this->m_ListOfTools = source.m_ListOfTools;
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