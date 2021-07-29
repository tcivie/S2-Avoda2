/* Assignment: 2
Author: Gleb Tcivie*/
#pragma once
#include "VIPClient.h"
class MatchmakingAgency {
private:
	Client** mDataBase;
	int mDbSize;

public:
	// CTOR AND DTOR
	/// <summary>
	/// Default constructor
	/// </summary>
	MatchmakingAgency();
	/// <summary>
	/// Default destructor
	/// </summary>
	~MatchmakingAgency();

	// METHODS
	/// <summary>
	/// Searches the database for matches and prints them
	/// </summary>
	/// <param name="id">Id of the client to look for matches for</param>
	void getMatches(const String id) const;
	/// <summary>
	/// Searches the database for clients by id
	/// </summary>
	/// <param name="id">Clients id</param>
	/// <returns>Client if found , Null otherwise</returns>
	Client* getClient(const String id) const;
	/// <summary>
	/// Returns the database size
	/// </summary>
	/// <returns>Database size in integer</returns>
	inline int getDbSize() const { return this->mDbSize; };

	// OPERATORS
	/// <summary>
	/// Prints all the database
	/// </summary>
	/// <param name="os">Outsream object to store the data in</param>
	/// <param name="db">The database to print</param>
	/// <returns>Outstream object with the data to print</returns>
	friend ostream& operator << (ostream& os, const MatchmakingAgency& db);
	/// <summary>
	/// Adds client to the database
	/// </summary>
	/// <param name="client">The client to add to the datbaase</param>
	void operator += (const Client& client);
	/// <summary>
	/// Adds client to the database
	/// </summary>
	/// <param name="client">The client to add to the datbaase</param>
	void operator += (const VIPClient& client);
	/// <summary>
	/// Finds the client in the database (With the given client database) and removes it from it
	/// </summary>
	/// <param name="client">The client to remove from the database</param>
	void operator -= (const Client& client);

};

