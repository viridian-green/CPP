#ifndef SERIALIZER_H
# define SERIALIZER_H

class Serializer
{
    private;
    Serializer();

    public:
    uintptr_t serialize(Data* ptr);
    Data* deserialize(uintptr_t raw);

};





#endif