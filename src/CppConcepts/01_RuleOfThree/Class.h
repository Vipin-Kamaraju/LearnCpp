#pragma once

/*!
** @file Class.h
** @author Vipin
** @date 04/2020
** @version 0.0.1
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

//#define ACTV_COUT_INFO
//#define ACTV_COUT_DEBUG

class ToolArray
{
public:
	/*!
	** @brief Constructor with no arguments & initialization list
	** @param[in] no arguements
	*/
	ToolArray() : name("Unknown"), m_ListOfTools({}), p_PowersList(nullptr)
	{
		#ifdef ACTV_COUT_INFO
		std::cout << "Constructor is called" << "\n";
		#endif
	}

	/*!
	** @brief Overloaded Constructor with two arguements & initialization list
	** @description Constructor with name and powerslist as input
	** @param[in] PlayerName Name of the player
	** @param[in] p_PList Pointer to data containing powers list
	*/
	ToolArray(std::string const PlayerName, std::vector<std::string>* const p_PList) : name(PlayerName), m_ListOfTools({}), p_PowersList(p_PList)
	{
		#ifdef ACTV_COUT_INFO
		std::cout << "ToolArray overloaded constructor called" << "\n";
		#endif
	}

	/*!
	** @brief Overloaded Constructor with one arguement & initialization list
	** @description Constructor with name as input. PowersList and ToolsList are initialized to nullptr and empty list
	** @param[in] PlayerName Name of the player
	*/
	explicit ToolArray(std::string const PlayerName) : name(PlayerName), m_ListOfTools({}), p_PowersList(nullptr)
	{
		#ifdef ACTV_COUT_INFO
		std::cout << "ToolArray overloaded constructor called" << "\n";
		#endif
	}

	/*!
	** @brief Destructor
	** @description Destructor to clear the ToolsList and the data contained in PowersList
	*/
	~ToolArray() noexcept;

	/*!
	** @brief Overloaded assignment operator
	** @description Overloaded assignment operator '='to copy the elements of existing ToolArray object from one to another
	** @param[in] source Input ToolArray object
	** @param[out] this Output ToolArray object
	*/
	ToolArray& operator=(ToolArray const& source) &;

	/*!
	** @brief Copy Constructor
	** @description Copy Constructor to copy source ToolArray elements to destination ToolArray elements
	** @param[in] source Input ToolArray object
	** @param[out] this Output ToolArray object
	*/
	ToolArray(ToolArray const& source) : name(source.name), m_ListOfTools(source.m_ListOfTools), p_PowersList(source.p_PowersList)
	{
		#ifdef ACTV_COUT_INFO
		std::cout << "Copy Constructor is called" << "\n";
		#endif
	}
	
	/*!
	** @brief Read only function that returns the name of Player called by the object
	** @param[out] name Name of the Player
	*/
	std::string const& getName() const;

	/*!
	** @brief Adds tool to the m_ToolsList of the player
	** @param[in] tool Tool to be added to the list
	*/
	void addTool(std::string f_tool);

	/*!
	** @brief Read only function that returns the list of tools for the resp. object
	** @param[out] m_ToolsList List of tools of the Player
	*/
	std::vector<std::string> const& getToolsList() const;

	/*!
	** @brief Adds power at the data pointed by p_PowersList
	** @param[in] Power Power to be added to the list of powers
	*/
	void addPower(std::string f_Power);

	/*!
	** @brief Read only function that returns the pointer to list of Powers for the resp. object
	** @param[out] p_PowersList Pointer to the list of powers of the Player
	*/
	std::vector<std::string>const* getPowersList() const;

	/*!
	** @brief sets the name of the Player
	** @param[in] name Name of the Player
	*/
	void setName(std::string PlayerName);
 
	
	/*!
	** @brief Operator Overloading for std::cout
	** @description This function will be called by the PrintToolArrayClass() to print the elements of the object
	** @param[in] ToolArray ToolArray object referece that is to be printed
	*/
	friend std::ostream& operator<<(std::ostream& os,ToolArray const& source);

	/*!
	** @brief Function to print out a class.
	** @description  Does not take in any arguements but is used to call the overloaded cout optr by passing ToolArray object reference
	** @param[in] ToolArray ToolArray object referece that is to be printed
	*/
	void PrintToolArrayClass();

private:
	std::string name;
	std::vector<std::string> m_ListOfTools;
	std::vector<std::string>* p_PowersList;

};
