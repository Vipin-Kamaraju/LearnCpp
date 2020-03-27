#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ToolArray
{
public:
	ToolArray();
	~ToolArray();
	void addTool(string f_tool);
	vector<string>& getToolsList();

	// Operator OVerloading for cout
	friend ostream& operator<<(ostream& os, ToolArray& tools);

private:
	
	vector<string> m_ListOfTools;
};
