#include <iostream>
#include "Phonebook.hpp"

Phonebook::Phonebook() : num(0)
{
}

Phonebook::~Phonebook()
{
}

Contact& Phonebook::getContact(int index)
{
    return Con[index];
}


int Phonebook::getNum() const {
    return num;
}

void Phonebook::incrementNum() {
    if (num < MAX_CONTACTS)
	{
        num++;
    }
}


int Phonebook::getMaxContact() const {
    return MAX_CONTACTS;
}

void DisplayContact(Contact& Con)
{
    std::cout << "First name :" << Con.getFirstName() << "\n";
    std::cout << "Last name :" << Con.getLastName() << "\n";
    std::cout << "Nickname :" << Con.getNickName() << "\n";
    std::cout << "Phone number :" << Con.getPhoneNumber() << "\n";
    std::cout << "Darkest secret :" << Con.getDarkestSecret() << "\n";
    std::cout << "\n";
}

void InputIndex(Phonebook& pb)
{
	std::cout << "Please enter an index to view contact info.\n";
	std::string input;
	while (1)
	{
	std::cin >> input;
	std::cout << "\n";
	if (input == "exit")
		break;
	int index;
	index = atoi(input.c_str());
	if (index <= 0 || index > pb.getNum() - 1 )
	{
		std::cout << "Error. Please enter a valid index visible in table.\n";
		std::cout << "If table is empty please exit and add a contact: ";
		continue;
	}
	DisplayContact(pb.getContact(index));
	break;
	}
}

void getInput(std::string &field, const std::string &prompt) {
	while (1)
	{
	std::cout << prompt;
	std::getline(std::cin, field);
	if (field.empty())
	std::cout << "Error, you may not leave an field empty.\n";
	else
		break;
	}
}

void format(std::string& str)
{
	int i = 0;
	if (str.length() >= 10)
        str = str.substr(0, 9) + ".";
	std::cout << std::setw(10) << std::right << str << "|";
}

 void Display(Phonebook& pb)
    {
        std::cout << std::setw(10) << "Index" << "|";
		std::cout << std::setw(10) << "Firstname" << "|";
		std::cout << std::setw(10) << "Lastname" << "|";
		std::cout << std::setw(10) << "Nickname" << std::endl;
		int start = 1;
        for (int i = 0; i < pb.getNum(); ++i)
        {
		std::cout << "\n" << std::setw(10) << std::right << i << "|";
        std::string firstName = pb.getContact(i).getFirstName();
        std::string lastName = pb.getContact(i).getLastName();
        std::string nickName = pb.getContact(i).getNickName();

        format(firstName);
        format(lastName);
        format(nickName);
        }
		std::cout << "\n";
    }

void InputNewContact(Contact& Con)
{
	std::cin.ignore();
	std::string input;

    getInput(input, "Enter your first name: ");
    Con.setFirstName(input);
	
    getInput(input, "Enter your last name: ");
    Con.setLastName(input);

    getInput(input, "Enter your nickname: ");
    Con.setNickName(input);

    getInput(input, "Enter your phone number: ");
    Con.setPhoneNumber(input);

    getInput(input, "Enter your darkest secret: ");
    Con.setDarkestSecret(input);
}
