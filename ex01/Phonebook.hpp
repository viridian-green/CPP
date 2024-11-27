#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class Phonebook
{
	public: // Public access specifier
    Contact Con[8];
    Phonebook( void );  // Constructor
    ~Phonebook( void );
};






#endif