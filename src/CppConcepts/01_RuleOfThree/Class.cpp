#include "Class.h"

// Destructor
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

// Overloaded Assignment Operator
ToolArray& ToolArray::operator=(const ToolArray& source)
{
	cout << "Overloaded assignment operator called" << endl;
	
	// Check for self assignment
	if (this == &source)
	{
		return *this;
	}
	
	this->name = source.name; // Same as name = source.name;
	this->m_ListOfTools = source.m_ListOfTools;	
	this->p_PowersList = source.p_PowersList; // Shallow copy

	return *this;
}

const string& ToolArray::getName() const
{
	return name;
}

void ToolArray::addTool(string f_tool)
{
	this->m_ListOfTools.push_back(f_tool);
}


const vector<string>& ToolArray::getToolsList() const
{
	return m_ListOfTools;
}

void ToolArray::addPower(string f_Power)
{
	p_PowersList->push_back(f_Power);
}


const vector<string>* ToolArray::getPowersList() const
{
	return p_PowersList;
}

void ToolArray::setName(string PlayerName)
{
	name = PlayerName;
}


// Overloaded operator for cout
ostream& operator<<(ostream& os,const ToolArray& tools)
{
	os << "**********" << tools.getName() << "**********" << endl;
	os << "Tools List:" << endl;
	for (std::vector<string>::const_iterator toolList = tools.getToolsList().begin(); toolList != tools.getToolsList().end(); toolList++)
	{
		os << *toolList << endl;
	}
	os << "Powers List:" << endl;
	if (tools.getPowersList() != nullptr) {
		for (std::vector<string>::const_iterator powersList = tools.getPowersList()->begin(); powersList != tools.getPowersList()->end(); powersList++)
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