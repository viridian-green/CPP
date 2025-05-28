#include "Serializer.hpp"

// Forward declarations if not included in Serializer.hpp
uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

//Serialization is the step that prepares data to be sent
//by converting an object into a format that can easily be saved to a file

int main()
{
	Data *OscarWilde;
	OscarWilde->title = "The Importance of Being Earnest";
	OscarWilde->publishingYear = 1895;

	uintptr_t rawData = serialize(OscarWilde);
	Data *object = deserialize(rawData);


}