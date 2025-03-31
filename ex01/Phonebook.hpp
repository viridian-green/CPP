#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <iomanip>
#include <map>
#include "Phonebook.hpp"
#include "Contact.hpp"

class Phonebook
{
private:
    Contact Con[8];
    int num;
    int MAX_CONTACT;

public: // Public access specifier
    Phonebook( void );  // Constructor
    ~Phonebook( void );
};






#endif