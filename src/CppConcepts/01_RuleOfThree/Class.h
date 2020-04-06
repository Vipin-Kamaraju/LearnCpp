#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

class ToolArray
{
public:
	// Default Constructor with initialization list
	ToolArray() : name("Unknown"), m_ListOfTools({}), p_PowersList(nullptr)
	{
		//cout << "Constructor is called" << endl;
	}

	// Overloaded Constructor
	ToolArray(string PlayerName, std::vector<string>* p_PList) : name(PlayerName), m_ListOfTools({}), p_PowersList(p_PList)
	{
		//cout << "ToolArray overloaded constructor called" << endl;
	}

	ToolArray(string PlayerName) : name(PlayerName), m_ListOfTools({}), p_PowersList(nullptr)
	{
		//cout << "ToolArray overloaded constructor called" << endl;
	}

	// Default Destructor
	~ToolArray() noexcept;

	// Overloaded assignment operator
	ToolArray& operator=(const ToolArray& source);

	// Copy Constructor
	ToolArray(const ToolArray& source) : name(source.name), m_ListOfTools(source.m_ListOfTools), p_PowersList(source.p_PowersList)
	{
		//cout << "Copy Constructor is called" << endl;
	}

	const string& getName() const;

	void addTool(string f_tool);
	const vector<string>& getToolsList() const;

	void addPower(string f_Power);
	const vector<string>* getPowersList() const;

	void setName(string PlayerName);

	// Operator Overloading for cout
	// keyword friend is used to access the private members of ToolArray class
	// friend ostream& operator<<(ostream& os, ToolArray& source);

	// PrintClass function
	void PrintToolArrayClass();
	
	// The function cannot be written this way since it cannot be called
	// in Solution.cpp how can we call this Player01.PrintToolArrayClass(Player01) 
	// void PrintToolArrayClass(const ToolArray& Player);

private:
	string name;
	vector<string> m_ListOfTools;
	vector<string>* p_PowersList;	

};
