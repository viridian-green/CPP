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
	cout << "Please enter a contact index between 0 and 8.\n";
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

void InputNewContact(Contact& contact)
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

void format(string& str)
{
	int i = 0;
	if (str.length() >= 10)
        str = str.substr(0, 9) + ".";
    cout << setw(10) << right << str << "|";
}

 void Display(std::vector<Contact>& contacts)
    {
        std::cout << "     index" << "|" << "first name" << "|" << " last name" << "|" << "  nickname";
        for (size_t i = 0; i < contacts.size(); ++i)
        {
        cout << setw(10) << right << i << "|";
        //format(contacts[i].FirstName);
        }
    }

int main()
{
	Phonebook pb;
	std::string first_prompt;
	std::map<std::string, int> myMap;
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