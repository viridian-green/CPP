#ifndef CONTACT_H
# define CONTACT_H
#include "Phonebook.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cctype>
#include <map>
#include "Contact.hpp"

class Phonebook;

class Contact
{
private:
    int index;
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string PhoneNumber;
    std::string DarkestSecret;

public:
    Contact();  // Constructor
    ~Contact();

	//Getters
	std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

	//Setters
	 void setFirstName(const std::string& firstName);
	 void setLastName(const std::string& lastName);
	 void setNickName(const std::string& nickName);
	 void setPhoneNumber(const std::string& phoneNumber);
	 void setDarkestSecret(const std::string& darkestSecret);
};
void InputNewContact(Contact& Con);
void Display(Phonebook& pb);
void InputIndex(Phonebook& pb);
#endif