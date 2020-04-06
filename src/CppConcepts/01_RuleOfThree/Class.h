#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

//#define ACTV_COUT_INFO
//#define ACTV_COUT_DEBUG

class ToolArray
{
public:
	// Default Constructor with initialization list
	ToolArray() : name("Unknown"), m_ListOfTools({}), p_PowersList(nullptr)
	{
		#ifdef ACTV_COUT_INFO
		std::cout << "Constructor is called" << "\n";
		#endif
	}

	// Overloaded Constructor
	ToolArray(std::string const PlayerName, std::vector<std::string>* const p_PList) : name(PlayerName), m_ListOfTools({}), p_PowersList(p_PList)
	{
		#ifdef ACTV_COUT_INFO
		std::cout << "ToolArray overloaded constructor called" << "\n";
		#endif
	}

	explicit ToolArray(std::string const PlayerName) : name(PlayerName), m_ListOfTools({}), p_PowersList(nullptr)
	{
		#ifdef ACTV_COUT_INFO
		std::cout << "ToolArray overloaded constructor called" << "\n";
		#endif
	}

	// Default Destructor
	~ToolArray() noexcept;

	// Overloaded assignment operator
	ToolArray& operator=(ToolArray const& source) &;

	// Copy Constructor
	ToolArray(ToolArray const& source) : name(source.name), m_ListOfTools(source.m_ListOfTools), p_PowersList(source.p_PowersList)
	{
		#ifdef ACTV_COUT_INFO
		std::cout << "Copy Constructor is called" << "\n";
		#endif
	}

	std::string const& getName() const;

	void addTool(std::string f_tool);
	std::vector<std::string> const& getToolsList() const;

	void addPower(std::string f_Power);
	std::vector<std::string>const* getPowersList() const;

	void setName(std::string PlayerName);

	// Operator Overloading for std::cout
	// keyword friend is used to access the private members of ToolArray class
	friend std::ostream& operator<<(std::ostream& os,ToolArray const& source);

	// PrintClass function
	void PrintToolArrayClass();
	
	// The function cannot be written this way since it cannot be called in Solution.cpp. 
	// How can we call the below mentioned function Player01.PrintToolArrayClass(Player01) 
	// does not make sense if declared like this void PrintToolArrayClass(const ToolArray& Player)

private:
	std::string name;
	std::vector<std::string> m_ListOfTools;
	std::vector<std::string>* p_PowersList;

};
