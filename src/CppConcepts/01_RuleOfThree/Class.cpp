#include "Class.h"

// Default Constructor
//ToolArray::ToolArray() : name("Unknown")
//{
//	cout << "Constructor is called" << endl;
//}

// Overloaded constructor
//ToolArray::ToolArray(string PlayerName)
//{
//	name = PlayerName;
//	cout << "ToolArray overloaded constructor called" << endl;
//}

// Overloaded constructor
//ToolArray::ToolArray(string PlayerName, std::vector<string>* p_PList)
//{
//	cout << "ToolArray overloaded constructor called" << endl;
//	p_PowersList = p_PList;
//	name = PlayerName;
//}

// destructor
ToolArray::~ToolArray() noexcept
{
	cout << "ToolArray destructor called" << endl;
	cout << &m_ListOfTools << endl;
	cout << p_PowersList << endl;
	if (!m_ListOfTools.empty())
	{
		cout << "m_ListOfTools is being cleared" << endl;
		this->m_ListOfTools.clear();
	}

	if (p_PowersList != nullptr)
	{
		cout << "p_PowersList is being cleared" << endl;
		p_PowersList->clear();
	}
}

//Copy Constructor
//ToolArray::ToolArray(const ToolArray& source) : name(source.name), m_ListOfTools(source.m_ListOfTools), p_PowersList(source.p_PowersList)
//{
//	cout << "Copy Constructor is called" << endl;
//}

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
	this->m_ListOfTools = source.m_ListOfTools;

	// Shallow copy
	this->p_PowersList = source.p_PowersList;

	return *this;
}

void ToolArray::addTool(string f_tool)
{
	this->m_ListOfTools.push_back(f_tool);
}


vector<string>& ToolArray::getToolsList()
{
	return m_ListOfTools;
}

void ToolArray::addPower(string f_Power)
{
	p_PowersList->push_back(f_Power);
}


vector<string>* ToolArray::getPowersList() const
{
	return p_PowersList;
}

void ToolArray::setName(string PlayerName)
{
	name = PlayerName;
}


// Overloaded operator for cout
ostream& operator<<(ostream& os,ToolArray& tools)
{
	os << "**********" << tools.name << "**********" << endl;
	os << "Tools List:" << endl;
	for (std::vector<string>::iterator toolList = tools.getToolsList().begin(); toolList != tools.getToolsList().end(); toolList++)
	{
		os << *toolList << endl;
	}
	os << "Powers List:" << endl;
	if (tools.getPowersList() != nullptr) {
		for (std::vector<string>::iterator powersList = tools.getPowersList()->begin(); powersList != tools.getPowersList()->end(); powersList++)
		{
			os << *powersList << endl;
		}
	}
	
	return os;
}

void ToolArray::PrintToolArrayClass()
{
	cout << *this << endl;
}