/* Assignment: 2
Author: Gleb Tcivie*/
#include "Menu.h"

void Menu::addClient() {
	char isVip;
	String id, name;
	char* stringHelper = new char[MAXSTRING]; // temp value for helping with the strings with spaces
	char gender;
	int age;
	char** hobbies = nullptr;
	int numHobbies = 0;
	int commonHobbies;
	cout << "Please insert client's information: " << endl
		<< "Client's ID : ";
	cin >> stringHelper;	// store id
	id = stringHelper;
	cout << "Full Name (Name Surename) : ";
	getchar(); // get the \n character
	cin.getline(stringHelper, MAXSTRING);	// read whole line
	name = stringHelper;					// apply the name
	cout << "Gender (M/F) : ";
	cin >> gender;			// store gender
	cout << "Age (18-120) : ";
	cin >> age;				// store age
	cout << "Number of hobbies : ";
	cin >> numHobbies;		// store hobbies
	cout << "Insert hobbies: " << endl;
	hobbies = new char* [numHobbies]; // allocate new hobbies
	getchar(); // get the \n character
	for (int i = 0; i < numHobbies; i++) {
		cin.getline(stringHelper, MAXSTRING);	// get whole line
		hobbies[i] = new char[MAXSTRING];		// allocate new memmory
		hobbies[i] = String::strCpy(hobbies[i],stringHelper); // apply the string
	}
	cout << "Is the client VIP ? (Y/N) : ";
	cin >> isVip;
	if (isVip == 'Y') { // if VIP client
		cout << "How many common hobbies for matching ? : ";
		cin >> commonHobbies;
		this->mDB += VIPClient(id, name, gender, age, hobbies, numHobbies, commonHobbies); // add the VIP client
	} else { // else add non VIP client
		this->mDB += Client(id, name, gender, age, hobbies, numHobbies); // add the client to the database
	}
	cout << "Client Added !" << endl;
	delete[] stringHelper; // deallocate memmory
}

void Menu::removeClient() {
	String id;
	char* stringHelper = new char[MAXSTRING]; // allocate memmory
	cout << "Insert the client's id: ";
	cin >> stringHelper;	// store id
	id = stringHelper;		// id of the client to find matches for
	this->mDB -= *this->mDB.getClient(id); // remove the client from the database
	delete[] stringHelper;
}

void Menu::print() const {
	cout << "Printing all the database: " << endl << this->mDB; // print all the database
}

void Menu::findMatch() const {
	String id;
	char* stringHelper = new char[MAXSTRING]; // allocate memmory
	cout << "Insert the client's ID : ";
	cin >> stringHelper;	// store id
	id = stringHelper;		// id of the client to find matches for
	delete[] stringHelper;	// deallocate memmory
	this->mDB.getMatches(id);
}

void Menu::printMenu() const {
	cout << "Please choose one of the following options: " << endl
		<< "===================================================================================" << endl
		<< "1) Add a new client to the database. " << endl
		<< "2) Remove an existing client from the database. " << endl
		<< "3) Print all clients. " << endl
		<< "4) Print all matches for a client. " << endl
		<< "5) Quit the program. " << endl
		<< "===================================================================================" << endl;
}

Menu::Menu() {
	int choice;
	this->mDB; // init main db
	while (true) {
		this->printMenu(); // prints the menu
		cin >> choice; // save the answer
		switch (choice) { // menu items
			case 1: // ADD TO DATABASE
			this->addClient();
			break;
			case 2: // REMOVE FROM DATABASE
			this->removeClient();
			break;
			case 3: // PRINT ALL DATABASE
			this->print();
			break;
			case 4: // PRINT ALL MATCHES FOR CLIENT
			this->findMatch();
			break;
			case 5: // EXIT
			return; // end program
			break;
		}
	}
}
