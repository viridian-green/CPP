#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class Phonebook
{
	public: // Public access specifier
    Phonebook( void );  // Constructor
    Contact Contacts[8];
    ~Phonebook( void );
};






#endif