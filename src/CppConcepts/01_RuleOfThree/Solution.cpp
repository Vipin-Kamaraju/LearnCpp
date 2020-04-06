
/*

Rule of 3 implementation

Task:
 - Add doxygen comments

Code Comments:
 - Added Doxygen comments

Answers:
 - 
*/

#include <iostream>
#include "Class.h"


void main()
{
	std::vector<std::string> PowersList;
	PowersList.push_back("kill");
	PowersList.push_back("shoot");
	PowersList.push_back("thunder");

	std::vector<std::string>* const p_PowersList = &PowersList;

	// Overloaded Constructor
	ToolArray Player01("Matthias", p_PowersList);

	// This will no longer be valid since we added the & in the overloaded assignment operator funct
	// The & in the end will prevent accepting rvalues as parameters
	// The built-in assignment operators do not accept rvalues as parameters and hence it would be confusing if 
	// built-in parameters accept rvalue parameters
	// QAC rule violation A12-8-7 :Assignment operators should be declared with the ref-qualifier &.
	// Due to this violation ToolArray Player02 = "Tobi" cannot be used

	ToolArray Player02("Tobi");

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
	Player04 = Player01;

	Player01.addTool("gun");
	Player01.addPower("explode");
	Player03.setName("Michael");
	Player04.setName("Karl");
	Player05.setName("Stefan");

#ifdef ACTV_COUT_DEBUG

	std::cout << "**********Deep copy of m_ListOfTools different address************" << "\n";
	std::cout << &(Player01.getToolsList()) << "\n";
	std::cout << &(Player02.getToolsList()) << "\n";
	std::cout << &(Player03.getToolsList()) << "\n";
	std::cout << &(Player04.getToolsList()) << "\n";
	std::cout << &(Player05.getToolsList()) << "\n";

	std::cout << "**********Shallow copy of p_PowersList same address************" << "\n";
	std::cout << (Player01.getPowersList()) << "\n";
	std::cout << (Player02.getPowersList()) << "\n";
	std::cout << (Player03.getPowersList()) << "\n";
	std::cout << (Player04.getPowersList()) << "\n";
	std::cout << (Player05.getPowersList()) << "\n";

#endif // ACTV_COUT_DEBUG

	Player01.PrintToolArrayClass();
	Player02.PrintToolArrayClass();
	Player03.PrintToolArrayClass();
	Player04.PrintToolArrayClass();
	Player05.PrintToolArrayClass();

	
	system("PAUSE");
}

