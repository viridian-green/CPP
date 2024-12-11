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

void DisplayContact(Contact& Con)
{
	cout << "First name :" << Con.FirstName << "\n";
	cout << "Last name :" << Con.LastName << "\n";
	cout << "Nickname :" << Con.NickName << "\n";
	cout << "Phone number :" << Con.PhoneNumber << "\n";
	cout << "Darkest secret :" << Con.DarkestSecret << "\n";
	cout << "\n";
}

void InputIndex(Phonebook& pb)
{
	cout << "Please enter an index to view contact info.\n";
	while (1)
	{
	int index;
	cin >> index;
	cout << "\n";
	if (index > 8 || index > pb.num - 1)
	{
		cout << "Error. Please enter a valid index: ";
		continue;
	}
	else
	{
		DisplayContact(pb.Con[index]);
		break;
	}
	}
}

void getInput(std::string &field, const std::string &prompt) {
	while (1)
	{
	std::cout << prompt;
	std::getline(std::cin, field);
	if (field.empty())
		cout << "Error, you may not leave an field empty.\n";
	else
		break;
	}
}

void format(string& str)
{
	int i = 0;
	if (str.length() >= 10)
        str = str.substr(0, 9) + ".";
    cout << setw(10) << right << str << "|";
}

 void Display(Phonebook& pb)
    {
        std::cout << "     Index" << "|" << "First Name" << "|" << " Last Name" << "|" << "  Nickname" << "\n";
		int début = 1;
        for (int i = 0; i < pb.num; ++i)
        {
        cout << "\n" << setw(10) << right << i << "|";
        format(pb.Con[i].FirstName);
		format(pb.Con[i].LastName);
		format(pb.Con[i].NickName);
        }
		cout << "\n";
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
	cout << "Enter one of the three commands: add, search or exit.\n";
	cin >> first_prompt;
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