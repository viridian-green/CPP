#ifndef CONTACT_H
# define CONTACT_H
#include "Phonebook.hpp"

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