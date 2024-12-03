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
	return;
};

Contact::~Contact( void )
{
	return;
};

void DisplayContacts()
{
	while (true)
	{
	int contact_index;
	cout << "Please enter a contact index between 0 and 8.\n";
	cin >> contact_index;
	if (contact_index > 8)
	{
		cout << "Error. ";
		continue;
	}
	else
	{
		cout << "hey.\n";
		break;
	}
	}
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

void InputInfo(Contact& contact)
{
	Contact newContact;

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
	Phonebook pb;
	std::string first_prompt;
	Contact instance1;
	std::map<std::string, int> myMap;

	while (1)
	{
	cout << "Please enter one of the three following commands: add, search or exit.\n";
	cin >> first_prompt;
	if (first_prompt == "add")
		InputInfo(pb.Con[0]);
	else if (first_prompt == "search")
	{
		DisplayContacts();
	}
	else if (first_prompt == "exit")
        exit(0);
	}
}