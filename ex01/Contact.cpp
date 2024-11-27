#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <map>
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

void getInput(std::string &field, const std::string &prompt) {
	while (1)
	{
	std::cout << prompt;
	std::getline(std::cin, field);
	if (field.empty() || field.find(' ') != std::string::npos)
		cout << "Error, you may not leave an field empty.\n";
	else
		break;
	}

}

void InputInfo()
{
	std::string FirstName, LastName, NickName, PhoneNumber, DarkestSecret;

	std::cin.ignore();
	getInput(FirstName, "Enter your first name: ");
	getInput(LastName, "Enter your last name: ");
	getInput(NickName, "Enter your nickname: ");
	getInput(PhoneNumber, "Enter your phone number: ");
	getInput(PhoneNumber, "Enter your darkest secret: ");
}


int main()
{
	std::string first_prompt;
	Phonebook myPhonebook;
	Contact instance1;
	std::map<std::string, int> myMap;

	cout << "Please enter one of the three following commands: add, search or exit.\n";
	cin >> first_prompt;
	if (first_prompt == "add")
		InputInfo();
	/*
	else if (first_prompt == "SEARCH")
		search_functin();
	else if (first_prompt == "EXIT")
		exit_functin();
	*/
}