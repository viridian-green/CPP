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

class Contact;

class Phonebook
{
private:
	static const int MAX_CONTACTS = 8;
    Contact Con[MAX_CONTACTS];
    int num;


public: // Public access specifier
    Phonebook();  // Constructor
    ~Phonebook();


	   // Getters
	   Contact& getContact(int index);
	   int getMaxContact() const;
	   int getNum() const;
	 // Setter for num
	 void incrementNum();

};
#endif