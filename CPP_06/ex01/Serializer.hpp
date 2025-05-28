#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <cstdint>
#include <string>

struct Data
{
	std::string title;
	int publishingYear;
};


class Serializer
{
    private:
    Serializer();

    public:
	Serializer(const Serializer &other);
	Serializer& operator=(const Serializer &other);
	~Serializer();
    uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);

};





#endif