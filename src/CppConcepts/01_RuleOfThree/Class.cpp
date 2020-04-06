#include "Class.h"


// Destructor
ToolArray::~ToolArray() noexcept
{
	std::cout << "ToolArray destructor called" << "\n";
	std::cout << &m_ListOfTools << "\n";
	std::cout << p_PowersList << "\n";
	if (!m_ListOfTools.empty())
	{
		std::cout << "m_ListOfTools is being cleared" << "\n";
		this->m_ListOfTools.clear();
	}

	if (p_PowersList != nullptr)
	{
		std::cout << "p_PowersList is being cleared" << "\n";
		p_PowersList->clear();
	}
}

// Overloaded Assignment Operator
ToolArray& ToolArray::operator=(ToolArray const& source) &
{
	std::cout << "Overloaded assignment operator called" << "\n";
	
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

std::string const& ToolArray::getName() const
{
	return name;
}

void ToolArray::addTool(std::string const f_tool)
{
	this->m_ListOfTools.push_back(f_tool);
}


std::vector<std::string> const& ToolArray::getToolsList() const
{
	return m_ListOfTools;
}

void ToolArray::addPower(std::string const f_Power)
{
	p_PowersList->push_back(f_Power);
}


std::vector<std::string>const* ToolArray::getPowersList() const
{
	return p_PowersList;
}

void ToolArray::setName(std::string const PlayerName)
{
	name = PlayerName;
}


// Overloaded operator for std::cout
std::ostream& operator<<(std::ostream& os,ToolArray const& tools)
{
	os << "**********" << tools.getName() << "**********" << "\n";
	os << "Tools List:" << "\n";
	for (std::vector<std::string>::const_iterator toolList = tools.getToolsList().begin(); toolList != tools.getToolsList().end(); toolList++)
	{
		os << *toolList << "\n";
	}
	os << "Powers List:" << "\n";
	if (tools.getPowersList() != nullptr) {
		for (std::vector<std::string>::const_iterator powersList = tools.getPowersList()->begin(); powersList != tools.getPowersList()->end(); powersList++)
		{
			os << *powersList << "\n";
		}
	}
	return os;
}

void ToolArray::PrintToolArrayClass()
{
	std::cout << *this << "\n";
}