#include "Phonebook.hpp"
#include "Contact.hpp"

int main()
{
	Phonebook pb;
	std::string first_prompt;

	while (1)
	{
	std::cout << "Enter one of the three commands: add, search or exit.\n";
	std::cin >> first_prompt;
	if (first_prompt == "add")
	{
		if (pb.getNum() < pb.getMaxContact())
		{
			InputNewContact(pb.getContact(pb.getNum()));
			pb.incrementNum();
		}
		else
			InputNewContact(pb.getContact(pb.getMaxContact() - 1));
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