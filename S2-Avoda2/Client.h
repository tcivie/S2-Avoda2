/* Assignment: 2
Author: Gleb Tcivie*/
#pragma once
#define MAXSTRING 256
#include "String.h"
class Client {
protected:
	String mId;			// Persons Id number
	String mName;		// Persons full name
	char mGender;		// persons gender (F/M)
	int mAge;			// persons age
	char** mHobbies;	// pointer to array of pointers to hobbies
	int mNumHobbies;	// total number of hobbies
private:
	/// <summary>
	/// Counts the length of the given pointer to array of chars
	/// </summary>
	/// <param name="str">Pointer to array of characters</param>
	/// <returns>Length of the string</returns>
	int countStrlen(const char* str);
	/// <summary>
	/// Copy hobbies from pp to hobbies to this object
	/// </summary>
	/// <param name="hobbies">pointer to pointer to hobbies</param>
	/// <param name="numHobbies">number of hobbies</param>
	void copyHobbies(char** hobbies, const int numHobbies);
public:
	// CTOR CCTOR AND DTOR
	/// <summary>
	/// Default constructor
	/// </summary>
	/// <param name="id">| String with the persons Id | defaults to 000000000</param>
	/// <param name="name">| String with the full name (Name Surename) | defaults to John Doe</param>
	/// <param name="gender">| char persons gender (M or F) | defaults to M</param>
	/// <param name="age">| int persons age , minimum 18 and maximum 120 , | defaults to 35</param>
	/// <param name="hobbies">| ppchar list of person's hobbies | defaults to nullptr</param>
	/// <param name="numHobbies">| int number of person's hobbies | defaults to 0</param>
	Client(const String id = "000000000", const String name = "John Doe",
		const char gender = 'M', const int age = 35,
		 char** hobbies = nullptr, const int numHobbies = 0);
	/// <summary>
	/// Copy constructor
	/// </summary>
	/// <param name="other">Parameter to copy from</param>
	Client(const Client& other);
	/// <summary>
	/// Default destructor
	/// </summary>
	~Client();

	// OPERATORS
	/// <summary>
	/// Print operator
	/// </summary>
	/// <param name="os">Outstream object</param>
	/// <param name="str">Client to print</param>
	/// <returns>Outstream object with print data</returns>
	friend ostream& operator << (ostream& os, const Client& str);
	/// <summary>
	/// Cheks if the clients are matching (other is the opposite gender , age difference not greater than 5 , at least one similar hobby)
	/// </summary>
	/// <param name="other">The other client</param>
	/// <returns>True if they metch , False otherwise</returns>
	virtual bool operator == (const Client& other) const;
	/// <summary>
	/// Apply the client to the first clinet (copy)
	/// </summary>
	/// <param name="other">the client to copy</param>
	/// <returns>The ne copied client</returns>
	Client* operator = (const Client& other);
	
	// METHODS
	/// <summary>
	/// Searches for one common hobbie in two persons
	/// </summary>
	/// <param name="fisrt">The first Client</param>
	/// <param name="secod">The second Client</param>
	/// <returns>True if found one hobby in both of the clients</returns>
	bool checkSimHobbies(const Client& first, const Client& second) const;
	/// <summary>
	/// Copy hobbies from other to this object
	/// </summary>
	/// <param name="other">The object to copy the hobbies from</param>
	void copyHobbies(const Client& other);

	// GET METHODS
	/// <summary>
	/// Gets the Gender
	/// </summary>
	/// <returns>char Gender (M/F)</returns>
	inline char getGender() const { return this->mGender; };
	inline int getAge() const { return this->mAge; };
	inline String getId() const { return this->mId; };
	inline String getName() const { return this->mName; };
	inline int getNumHobbies() const { return this->mNumHobbies; };
	inline char* getHobbies(int i) const { return this->mHobbies[i]; };
	virtual inline int getNumCommonHobbies() const { return 0; };
};