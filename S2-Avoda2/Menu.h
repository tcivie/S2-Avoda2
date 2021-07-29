/* Assignment: 2
Author: Gleb Tcivie*/
#pragma once
#define MAXSTRING 256
#include "MatchmakingAgency.h"

using namespace std;
class Menu {
private:
	MatchmakingAgency mDB;

	// METHODS 
	/// <summary>
	/// Adds new client to the database
	/// </summary>
	void addClient();
	/// <summary>
	/// Deletes client from the database with the given id
	/// </summary>
	/// <param name="id">Id of the client</param>
	void removeClient();
	/// <summary>
	/// Prints all the customers
	/// </summary>
	void print() const;
	/// <summary>
	/// Finds match for the selected client, If not found relevant message will appear
	/// </summary>
	/// <param name="id">Clients Id</param>
	void findMatch() const;
	/// <summary>
	/// Prints the main menu
	/// </summary>
	void printMenu() const;

public:
	// CTOR
	/// <summary>
	/// Constructor that displays menu on screen
	/// </summary>
	Menu();
};

