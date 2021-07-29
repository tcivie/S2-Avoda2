/* Assignment: 2
Author: Gleb Tcivie*/
#include "Client.h"

int Client::countStrlen(const char* str) {
	int i = 0;
	while (str[i++] != '\0'); // count how many letters there are
	return i;
}

void Client::copyHobbies(const Client& other) {
	int strLen;
	this->mHobbies = new char* [other.mNumHobbies];			// allocate memmory for the hobbies
	for (int i = 0; i < other.mNumHobbies; i++) {			// run trough all the hobbies
		strLen = countStrlen(other.mHobbies[i]);			// count hobby length
		this->mHobbies[i] = new char[strLen];				// allocate new memmory for the hobby
		this->mHobbies[i] = String::strCpy(this->mHobbies[i], other.mHobbies[i]);	// copy the values
	}
	this->mNumHobbies = other.mNumHobbies;
}

void Client::copyHobbies(char** hobbies, const int numHobbies) {
	int strLen;
	this->mHobbies = new char* [numHobbies];		// allocate memmory for the hobbies
	for (int i = 0; i < numHobbies; i++) {			// run trough all the hobbies
		strLen = countStrlen(hobbies[i]);			// count hobby length
		this->mHobbies[i] = new char[strLen];		// allocate new memmory for the hobby
		this->mHobbies[i] = String::strCpy(this->mHobbies[i], hobbies[i]); // copy the values
	}
	this->mNumHobbies = numHobbies; // copy number of hobbies
}

bool Client::checkSimHobbies(const Client& first, const Client& second) const {
	for (int i = 0; i < first.mNumHobbies; i++) { // run on all first persons hobbies
		for (int j = 0; j < second.mNumHobbies; j++) { // run on all second persons hobbies
			if (String::strCmp(first.mHobbies[i], second.mHobbies[j])) // chek hobbies
				return true;
		}
	}
	return false; // if none found
}

Client::Client(const String id, const String name, const char gender, const int age,  char** hobbies, const int numHobbies) {
	
	this->mId = id;			// copy the string with = operator
	this->mName = name;		// copy name with = operator
	this->mGender = gender; // copy the char
	this->mAge = age;		// copy the age
	this->copyHobbies(hobbies, numHobbies); // use copy function
}

Client::Client(const Client& other) {
	this->mId = other.mId;			// copy the string with = operator
	this->mName = other.mName;		// copy name with = operator
	this->mGender = other.mGender;	// copy the char
	this->mAge = other.mAge;		// copy the age
	this->copyHobbies(other);		// use copy function
}

Client::~Client() {
	for (int i = 0; i < this->mNumHobbies; i++) { // run on all the hobbies and deallocate them
		delete this->mHobbies[i]; // deallocate hobbies
	}
	delete this->mHobbies; // delete the rest of the link
	// the rest will be automatically deletede with teir destructors
}

bool Client::operator==(const Client& other) const {
	if (this->mGender != other.mGender) // 1# check the oposite gender
		if ((this->mAge + 5) >= other.mAge || (this->mAge - 5) <= other.mAge) // 2# check the age diference
			if (Client::checkSimHobbies(*this, other)) // 3# check if there is similar hobbie
				return true;
	return false; // not matched
}

Client* Client::operator=(const Client& other) {
	if (this != &other) { // check if not the same
		this->mAge = other.mAge;		// copy age
		this->mGender = other.mGender;	// copy gender
		this->mId = other.mId;			// copy id
		this->mName = other.mName;		// copy name
		if (this->mNumHobbies) { // if there are any stored values
			for (int i = 0; i < this->mNumHobbies; i++) {	// run trough all old hobbies
				delete this->mHobbies[i];					// delete each hobby
			}
			delete this->mHobbies;							// delete the hobby array
		}
		this->mHobbies = new char* [other.mNumHobbies]; // allocate new memmory for the hobbies
		this->mNumHobbies = other.mNumHobbies;			// copy number of hobbies
		for (int i = 0; i < this->mNumHobbies; i++) {
			this->mHobbies[i] = new char[MAXSTRING];	// allocate new memmory
			this->mHobbies[i] = String::strCpy(this->mHobbies[i], other.mHobbies[i]); // copy hobbies
		}
	}
	return this;
}

ostream& operator<<(ostream& os, const Client& str) {
	os << "ID: " << str.mId << endl <<
		"Name:  " << str.mName << endl <<
		"Gender: " << str.mGender << endl <<
		"Age: " << str.mAge << endl <<
		"Hobbies: " << endl;
	for (int i = 0; i < str.mNumHobbies; i++) // run on all the hobbies and append them to the out strem
		os << "\t" << str.mHobbies[i] << endl;
	os << "Total Number of hobbies: " << str.mNumHobbies << endl;
	os << "==============================================";
	return os;
}
