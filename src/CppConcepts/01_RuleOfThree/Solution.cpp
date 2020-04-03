
/*

Rule of 3 implementation

Task:
 - Write a case where there is no copy ctr , overloaded ass operator and the system shall not crash

Code Comments:
 - This code does not crash
 - m_ListOfTools is an example of deep copy
 - p_PowersList is an example of Shallow copy
 - Set a breakpoint in the destructor to see the program flow

Answers:
 - A good check to verify whether a copy is shallow or deep.
 - Verify the address printed for m_ListOfTools & p_PowersList
 - p_PowersList shows the same address => shallow copy
 - m_ListOfTools shows different address => deep copy

*/

#include <iostream>
#include "Class.h"

using namespace std;

void main()
{
	std::vector<string> PowersList;
	PowersList.push_back("kill");
	PowersList.push_back("shoot");
	PowersList.push_back("thunder");

	std::vector<string>* p_PowersList = &PowersList;

	// Overloaded Constructor
	ToolArray Player01("Matthias", p_PowersList);
	ToolArray Player02 = "Tobi";

	Player01.addTool("axe");
	Player01.addTool("knife");
	Player01.addTool("bomb");
	
	// Constructor
	ToolArray Player03;

	// Copy Costructor
	// C++ provides a default copy ctr, default assignment operator, destructor
	// These default functions are called here
	ToolArray Player04 = Player01;
	ToolArray Player05(Player01);

	// Overloaded Assignment Operator
	// This is only invoked when the object already exists
	// a = b => a.operator=(b)
	// Player04 = Player01;

	Player01.addTool("gun");
	Player01.addPower("explode");
	Player03.setName("Michael");
	Player04.setName("Karl");
	Player05.setName("Stefan");

	cout << "**********Deep copy of m_ListOfTools different address************" << endl;
	cout << &(Player01.getToolsList()) << endl;
	cout << &(Player02.getToolsList()) << endl;
	cout << &(Player03.getToolsList()) << endl;
	cout << &(Player04.getToolsList()) << endl;
	cout << &(Player05.getToolsList()) << endl;

	cout << "**********Shallow copy of p_PowersList same address************" << endl;
	cout << (Player01.getPowersList()) << endl;
	cout << (Player02.getPowersList()) << endl;
	cout << (Player03.getPowersList()) << endl;
	cout << (Player04.getPowersList()) << endl;
	cout << (Player05.getPowersList()) << endl;

	Player01.PrintToolArrayClass();
	Player02.PrintToolArrayClass();
	Player03.PrintToolArrayClass();
	Player04.PrintToolArrayClass();
	Player05.PrintToolArrayClass();

	
	system("PAUSE");
}

