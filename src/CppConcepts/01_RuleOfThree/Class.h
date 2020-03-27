#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ToolArray
{
public:
	ToolArray(string PlayerName);
	~ToolArray();

	string name;
	void addTool(string f_tool);
	vector<string>& getToolsList();

	// Operator Overloading for cout
	friend ostream& operator<<(ostream& os, ToolArray& tools);

private:
	vector<string> m_ListOfTools;
};
