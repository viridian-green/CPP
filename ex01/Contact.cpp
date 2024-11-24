#include <iostream>
#include <cstring>
#include <string.h>
#include "Phonebook.hpp"
#include "Contact.hpp"

using namespace std;

Contact::Contact( void )
{
	cout << "Constructer called" << endl;
	return;
};

Contact::~Contact( void )
{
	cout << "Destructor called" << endl;
	return;
};

void DisplayContacts()
{
	cout << "Please enter one of the three following commands\nADD\nSEARCH\nEXIT" << endl;
	cout << "Please enter one of the three following commands\nADD\nSEARCH\nEXIT" << endl;
	cout << "Please enter one of the three following commands\nADD\nSEARCH\nEXIT" << endl;
	cout << "Please enter one of the three following commands\nADD\nSEARCH\nEXIT" << endl;
}

void InputInfo()
{
	std::string FirstName;
	std::string LastName;
	std::string NickName;
    int PhoneNumber;
    std::string DarkestSecret;

	cout << "Please enter the contact's data" << endl;
	cin >> first_prompt;
}


int main()
{
	std::string first_prompt;
	Phonebook myPhonebook;
	Contact instance1;

	cout << "Please enter one of the three following commands\nADD\nSEARCH\nEXIT" << endl;
	cin >> first_prompt;
	if (first_prompt == "ADD")
		InputInfo();
	else if (first_prompt == "SEARCH")
		search_functin();
	else if (first_prompt == "EXIT")
		exit_functin();

}