#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ToolArray
{
public:
	// Default Constructor with initialization list
	ToolArray();

	// Overloaded Constructor
	ToolArray(string PlayerName, std::vector<string>* p_PowersList);
	ToolArray(string PlayerName);

	// Default Destructor
	~ToolArray();

	// Overloaded assignment operator
	//ToolArray& operator=(const ToolArray& source);

	// Copy Constructor
	//ToolArray(const ToolArray& source);

	void addTool(string f_tool);
	vector<string>& getToolsList();

	void addPower(string f_Power);
	vector<string>* getPowersList();

	// Operator Overloading for cout
	// keyword friend is used to access the private members of ToolArray class
	friend ostream& operator<<(ostream& os, ToolArray& source);

private:
	string name;
	vector<string> m_ListOfTools;
	vector<string>* p_PowersList;

};
