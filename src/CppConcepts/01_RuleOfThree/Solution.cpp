
/*

Rule of 3 implementation

Task:
 - Overloaded cout operator : COMPLETED
 - Check when : COMPLETED
	- Default constructor is called (vs)
	- Copy Constructor is called (vs)
	- Overloaded assignment operator is called
 - Use const in the cout overloaded operator
 - Rule of 3 : Overloaded Assignment operator, Copy Constructor, Destructor

Code Comments:
	- Demonstration of how copy ctr and overloaded assignment operator can be used to initialize an object
	- Uncomment the line.30 copy() in Class.cpp. you will get a segmentation fault. But the same line in 
	- .. overloaded assignment operator does not give this error. Why? Compare both the functions for copy()
	- Difference between Copy constructor and Overloaded assignment operator

Answers:
	- the copy funtion was failing in the copy ctr and passing in the overloaded assignment operator since
	- .. the size of the m_ListOfTools vector is not the same as source.m_ListOfTools. Run this code to see the 
	- ..size being printed. It passed in overloaded assignment operator since the size was same. Also this is deep copy
	- ..which means there will a significant loss in performance.

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
	// a = b => a.operator=(b)
	Player04 = Player01;
	cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;

	cout << &(Player01.getToolsList()) << endl;
	cout << &(Player02.getToolsList()) << endl;
	cout << &(Player03.getToolsList()) << endl;
	cout << &(Player04.getToolsList()) << endl;
	cout << &(Player05.getToolsList()) << endl;

	cout << Player01 << endl;
	cout << Player02 << endl;
	cout << Player03 << endl;
	cout << Player04 << endl;
	cout << Player05 << endl;

	
	system("PAUSE");
}

