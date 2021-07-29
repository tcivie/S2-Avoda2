/* Assignment: 2
Author: Gleb Tcivie*/
#include "VIPClient.h"

VIPClient::VIPClient(const VIPClient& other) {
	this->mId = other.mId;			// copy the string with = operator
	this->mName = other.mName;		// copy name with = operator
	this->mGender = other.mGender;	// copy the char
	this->mAge = other.mAge;		// copy the age
	this->copyHobbies(other);		// use copy function
	this->mNumCommonHobbies = other.mNumCommonHobbies; // get num common hobbies
}

bool VIPClient::operator==(Client& other) {
	int counter = 0; // counted matches
	if (this->getGender() != other.getGender()) // 1# check the oposite gender
		if ((this->getAge() + 5) == other.getAge() || (this->getAge() - 5) == other.getAge()) // 2# check the age diference
			if (Client::checkSimHobbies(*this, other)) // 3# check if there is similar hobbie
				counter++; // increment counter
	
	return counter >= this->mNumCommonHobbies; // return if matched enough
}
