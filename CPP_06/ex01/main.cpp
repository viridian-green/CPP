#include "Serializer.hpp"
#include "Data.hpp"

// Forward declarations if not included in Serializer.hpp
// uintptr_t serialize(Data* ptr);
// Data* deserialize(uintptr_t raw);

//Serialization is the step that prepares data to be sent
//by converting an object into a format that can easily be saved to a file


//Converting a data struct pointer to an int in order to store it or print it 
int main()
{
	Data *OscarWilde = new Data;
	OscarWilde->title = "The Importance of Being Earnest";
	OscarWilde->publishingYear = 1895;

	uintptr_t rawData = Serializer::serialize(OscarWilde);
	Data *object = Serializer::deserialize(rawData);

	std::cout << OscarWilde << std::endl;
	std::cout << object << std::endl;
	if (OscarWilde == object)
		std::cout << "Same pointer!" << std::endl;
	else
		std::cout << "Different pointers!" << std::endl;

}