
/*

Rule of 3 implementation

*/

#include <iostream>
#include "Class.h"

using namespace std;



void main()
{
	bool printPlayer01 = true;
	bool printPlayer02 = true;

	ToolArray Player01;
	Player01.addTool("axe");
	Player01.addTool("knife");
	Player01.addTool("bomb");
	
	ToolArray Player02;

	// Since the object Player02 does not already exist it will call the copy constructor in this case and not the assignment operator
	// RULE : Overloaded Assignment operator will only be invoked if the object already exists
	// This is the reason why just the overloaded assignement operator is not sufficient, -
	// - we need to write also the copy constructor
	// ToolArray Player02 = Player01;  
	// ToolArray Player02(Player01); // Another form of calling the copy constructor

	// Default or Overloaded assignment operator will be called here
	Player02 = Player01; 

	Player02.addTool("gun");

	for (std::vector<string>::iterator toolList = Player01.getToolsList().begin(); toolList != Player01.getToolsList().end(); toolList++)
	{
		if (printPlayer01)
		{
			cout << "Player01 tools list: " << endl;
			printPlayer01 = false;
		}
		
		cout << *toolList << endl;
	}

	for (std::vector<string>::iterator toolList02 = Player02.getToolsList().begin(); toolList02 != Player02.getToolsList().end(); toolList02++)
	{
		if (printPlayer02)
		{
			cout << "Player02 tools list: " << endl;
			printPlayer02 = false;
		}
		
		cout << *toolList02 << endl;
	}

	system("PAUSE");
}

