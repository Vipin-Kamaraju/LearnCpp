#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ToolArray
{
public:
	// Default Constructor with initialization list
	ToolArray();

	// Overloaded Constructor
	ToolArray(string PlayerName);

	// Default Destructor
	~ToolArray();

	// Overloaded assignment operator
	ToolArray& operator=(const ToolArray& source);

	// Copy Constructor
	ToolArray(const ToolArray& source);

	string name;
	void addTool(string f_tool);
	vector<string>& getToolsList();

	// Operator Overloading for cout
	friend ostream& operator<<(ostream& os, ToolArray& source);

private:
	vector<string> m_ListOfTools;
};
