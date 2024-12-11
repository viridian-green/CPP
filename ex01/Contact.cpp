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

void DisplayContact(Contact& contact)
{
	 cout << "Please enter a contact index between 0 and 8.\n";
}

void InputIndex(Phonebook& pb)
{
	while (true)
	{
	int contact_index;
	cout << "Please enter an index to view contact info.\n";
	cin >> contact_index;
	if (contact_index > 8)
	{
		cout << "Error. ";
		continue;
	}
	else
	{
		DisplayContact(pb.Con[contact_index]);
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
	getInput(Con.PhoneNumber, "Enter your darkest secret: ");
}

int main()
{
	Phonebook pb;
	std::string first_prompt;
	pb.num = 0;

	while (1)
	{
	cout << "Please enter one of the three following commands: add, search or exit.\n";
	cin >> first_prompt;
	if (first_prompt == "add")
	{
		InputNewContact(pb.Con[pb.num]);
		pb.num++;
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