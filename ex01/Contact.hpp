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

using namespace std;

class Contact
{
	public:

    int index;
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string PhoneNumber;
    std::string DarkestSecret;

    Contact( void );  // Constructor
    ~Contact( void );
};
#endif