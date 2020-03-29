
/*

Rule of 3 implementation

Task:
 - Overloaded cout operator : COMPLETED
 - Check when
	- Default constructor is called (vs)
	- Copy Constructor is called (vs)
	- Overloaded assignment operator is called
 - Use const in the cout overloaded operator
 - Rule of 3 : Overloaded Assignment operator, Copy Constructor, Destructor

Code Comments:
	- This shows all the scenarios when copy constructor (vs) overloaded assignemnt operator 
	- .. (vs) default constructor is called

*/

#include <iostream>
#include "Class.h"

using namespace std;

void main()
{
	// Overloaded Constructor
	ToolArray Player01("Mathias");
	ToolArray Player02("Tobi");
	cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;

	Player01.addTool("axe");
	Player01.addTool("knife");
	Player01.addTool("bomb");
	
	// Default Constructor
	ToolArray Player03;
	cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;

	// Copy Costructor
	ToolArray Player04 = Player01;
	ToolArray Player05(Player01);
	cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;

	// Overloaded Assignment Operator
	// This is only invoked when the object already exists
	Player04 = Player01;
	cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
	
	system("PAUSE");
}

