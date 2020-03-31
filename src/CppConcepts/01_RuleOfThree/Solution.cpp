
/*

Rule of 3 implementation

Task:
 - Write a case where there is no copy ctr , overloaded ass operator and the system shall crash

Code Comments:
 - Demonstration why rule of three is needed
 - No copy ctr and no overloaded ass optr
 - Code crashes on exit
 - A shallow copy for the PowersList is created and in the destructor when this is deleted we will see that the application is crashing
 - p_PowersList is a shallow copy : since the 'explode' power is added only for Player01 but is duplicated for Player04, Player05
 - m_ListOfTools is a deep copy :  since every Player has its own memory address for this member variable. Also the 'gun' tool is only
 - .. for Player01 in the o/p

Answers:
 - A good check to verify whether a copy is shallow or deep. Modify the contents that the pointer is pointing to.
 - By doing this you can check if the output was modified for both the Objects
 - If yes => Shallow copy, else => deep copy

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

	cout << &(Player01.getToolsList()) << endl;
	cout << &(Player02.getToolsList()) << endl;
	cout << &(Player03.getToolsList()) << endl;
	cout << &(Player04.getToolsList()) << endl;
	cout << &(Player05.getToolsList()) << endl;

	cout << (Player01.getPowersList()) << endl;
	cout << (Player02.getPowersList()) << endl;
	cout << (Player03.getPowersList()) << endl;
	cout << (Player04.getPowersList()) << endl;
	cout << (Player05.getPowersList()) << endl;

	cout << Player01 << endl;
	cout << Player02 << endl;
	cout << Player03 << endl;
	cout << Player04 << endl;
	cout << Player05 << endl;

	
	system("PAUSE");
}

