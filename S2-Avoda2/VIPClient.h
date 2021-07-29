/* Assignment: 2
Author: Gleb Tcivie*/
#pragma once
#include "Client.h"
class VIPClient :
    public Client {
private:
    int mNumCommonHobbies;

public:
    /// <summary>
    /// Default constructor
    /// </summary>
    /// <param name="id">| String with the persons Id | defaults to 000000000</param>
    /// <param name="name">| String with the full name (Name Surename) | defaults to John Doe</param>
    /// <param name="gender">| char persons gender (M or F) | defaults to M</param>
    /// <param name="age">| int persons age , minimum 18 and maximum 120 , | defaults to 35</param>
    /// <param name="hobbies">| ppchar list of person's hobbies | defaults to nullptr</param>
    /// <param name="numHobbies">| int number of person's hobbies | defaults to 0</param>
    /// <param name="common">| int number of common hobbies for matching | defaults to 1</param>
    VIPClient(const String id = "000000000", const String name = "John Doe",
        const char gender = 'M', const int age = 35,
         char** hobbies = nullptr, const int numHobbies = 0, const int common = 1) :
        Client(id, name, gender, age, hobbies, numHobbies) , mNumCommonHobbies(common < 1 ? 1 : common){
    };
    VIPClient(const VIPClient& other);
    /// <summary>
    /// Checks if the Client has number of common hobbies
    /// </summary>
    /// <param name="other">The client to check with</param>
    /// <returns>True if the number of common hobbies is the same as defined for VIP client, False otherwise</returns>
    bool operator == (Client& other);

    inline int getNumCommonHobbies() const { return this->mNumCommonHobbies; };
};

