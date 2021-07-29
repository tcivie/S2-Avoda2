/* Assignment: 2
Author: Gleb Tcivie*/
#include "MatchmakingAgency.h"

MatchmakingAgency::MatchmakingAgency() {
	this->mDataBase = nullptr;
	this->mDbSize = 0;
}

MatchmakingAgency::~MatchmakingAgency() {
	for (int i = 0; i < this->mDbSize; i++) {
		delete this->mDataBase[i]; // removes each client from the database
	}
	delete this->mDataBase; // deletes the database
}

void MatchmakingAgency::getMatches(const String id) const {
	Client* client = nullptr;
	for (int i = 0; i < this->mDbSize; i++) {		// search for the client in the database
		if (this->mDataBase[i]->getId() == id) {	// check if ID matches
			client = this->mDataBase[i];			// our client
			break; // exit loop if is
		}
	}
	// Do nothing if not found
	if (client) { // if client found
		for (int i = 0; i < this->mDbSize; i++) {
			if (!(this->mDataBase[i]->getId() == id)) {	// check if not the same person
				if (*client == *this->mDataBase[i])		// check if the client matches
					cout << *this->mDataBase[i] << endl;	// print the match
			}
		}
	}
}

Client* MatchmakingAgency::getClient(const String id) const {
	for (int i = 0; i < this->mDbSize; i++) {
		if (this->mDataBase[i]->getId() == id)
			return this->mDataBase[i];
	}
	return nullptr;
}

void MatchmakingAgency::operator+=(const Client& client) {
	if (!this->mDbSize) { // if database dosent exist
		this->mDataBase = new Client * [1];			// array of one pointer
		this->mDataBase[0] = new Client(client);	// allocate new memmory for client and add to database
	} else {
		Client** backup = new Client * [this->mDbSize + 1]; // allocate backup with one more size
		for (int i = 0; i < this->mDbSize; i++) {	// copy all values from old database
			backup[i] = this->mDataBase[i];			// copy pointers
		}
		delete this->mDataBase;	// un allocate the database
		backup[this->mDbSize] = new Client(client);			// copy the new client to the end of the database
		this->mDataBase = new Client * [this->mDbSize + 1]; // allocate new databse + 1
		for (int i = 0; i <= this->mDbSize; i++) {			// place the backup in the newly allocated database
			this->mDataBase[i] = backup[i];					// copy the pointers (with the added client) to the new database
		}
		delete[] backup; // deallocates the backup databse without deallocating the pointers
	}
	this->mDbSize++; // increase database size by one
}

void MatchmakingAgency::operator+=(const VIPClient& client) {
	if (!this->mDbSize) { // if database dosent exist
		this->mDataBase = new Client * [1];			// array of one pointer
		this->mDataBase[0] = new VIPClient(client);	// allocate new memmory for client and add to database
	} else {
		Client** backup = new Client * [this->mDbSize + 1]; // allocate backup with one more size
		for (int i = 0; i < this->mDbSize; i++) {	// copy all values from old database
			backup[i] = this->mDataBase[i];			// copy pointers
		}
		delete this->mDataBase;	// un allocate the database
		backup[this->mDbSize] = new VIPClient(client);		// copy the new client to the end of the database
		this->mDataBase = new Client * [this->mDbSize + 1]; // allocate new databse + 1
		for (int i = 0; i <= this->mDbSize; i++) {			// place the backup in the newly allocated database
			this->mDataBase[i] = backup[i];					// copy the pointers (with the added client) to the new database
		}
		delete[] backup; // deallocates the backup databse without deallocating the pointers
	}
	this->mDbSize++; // increase database size by one
}

void MatchmakingAgency::operator-=(const Client& client) {
	Client** backup = new Client * [this->mDbSize - 1];		// allocate new memmory
	int j = 0; // backup index
	for (int i = 0; i < this->mDbSize; i++) {				// find the client in the database
		if (this->mDataBase[i]->getId() == client.getId())	// match the client
			continue; // skip if found
		backup[j++] = this->mDataBase[i];					// copy pointers + increment j by one
	}
	delete this->mDataBase;									// deallocate the old database
	this->mDataBase = new Client * [this->mDbSize - 1];		// allocate new database with - 1 space
	for (int i = 0; i < this->mDbSize - 1; i++) {
		this->mDataBase[i] = backup[i];						// copy the pointers
	}
	delete[] backup; // deallocates the backup databse without deallocating the pointers
	this->mDbSize--;
}

ostream& operator<<(ostream& os, const MatchmakingAgency& db) {
	for (int i = 0; i < db.mDbSize; i++) {	// goes trough all the clients int the database
		os << (*db.mDataBase[i]) << endl;	// prints the clients
	}
	return os;
}
