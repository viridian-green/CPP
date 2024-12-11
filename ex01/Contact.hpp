#ifndef CONTACT_H
# define CONTACT_H
#include "Phonebook.hpp"
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <map>
#include "Phonebook.hpp"
#include "Contact.hpp"

class Contact
{
	public:

    int index;
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string PhoneNumber;
    std::string DarkestSecret;

    void Display(const vector<Contact>& contacts)
    {
        std::cout << "     index" << "|" << "first name" << "|" << " last name" << "|" << "  nickname";
        for (size_t i = 0; i < contacts.size(); ++i)
        {
        cout << setw(10) << right << i << "|"
           // format(contacts[i].FirstName)
    }
    }
    Contact( void );  // Constructor
    ~Contact( void );
};
#endif