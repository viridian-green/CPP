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
#include "Phonebook.hpp"
#include "Contact.hpp"

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
    Contact( void );  // Constructor
    ~Contact( void );
	void getInput(std::string &field, const std::string &prompt);
	void DisplayContact(Contact& Con);
	void Display(Phonebook& pb);
};
#endif