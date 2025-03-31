#include "Phonebook.hpp"
#include "Contact.hpp"

Contact::Contact( void )
{
	return;
};

Contact::~Contact( void )
{
	return;
};

void DisplayContact(Contact& Con)
{
	std::cout << "First name :" << Con.FirstName << "\n";
	std::cout << "Last name :" << Con.LastName << "\n";
	std::cout << "Nickname :" << Con.NickName << "\n";
	std::cout << "Phone number :" << Con.PhoneNumber << "\n";
	std::cout << "Darkest secret :" << Con.DarkestSecret << "\n";
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
	if (index > 8 || index > pb.num - 1)
	{
		std::cout << "Error. Please enter a valid index visible in table.\n";
		std::cout << "If table is empty please exit and add a contact: ";
		continue;
	}
	DisplayContact(pb.Con[index]);
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
        for (int i = 0; i < pb.num; ++i)
        {
		std::cout << "\n" << std::setw(10) << std::right << i << "|";
        format(pb.Con[i].FirstName);
		format(pb.Con[i].LastName);
		format(pb.Con[i].NickName);
        }
		std::cout << "\n";
    }

void InputNewContact(Contact& Con)
{
	std::cin.ignore();
	getInput(Con.FirstName, "Enter your first name: ");
	getInput(Con.LastName, "Enter your last name: ");
	getInput(Con.NickName, "Enter your nickname: ");
	getInput(Con.PhoneNumber, "Enter your phone number: ");
	getInput(Con.DarkestSecret, "Enter your darkest secret: ");
}

int main()
{
	Phonebook pb;
	std::string first_prompt;
	pb.num = 0;
	int MAX_CONTACT = 8;

	while (1)
	{
	std::cout << "Enter one of the three commands: add, search or exit.\n";
	std::cin >> first_prompt;
	if (first_prompt == "add")
	{
		if (pb.num < MAX_CONTACT)
		{
			InputNewContact(pb.Con[pb.num]);
			pb.num++;
		}
		else
			InputNewContact(pb.Con[7]);
	}
	else if (first_prompt == "search")
	{
		Display(pb);
		InputIndex(pb);
	}
	else if (first_prompt == "exit")
		exit(0);
	}
}