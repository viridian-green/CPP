#pragma once

template <class T>
class Array
{
    private:
    T *array;
    unsigned int arrSize;

    public:
    Array() : array(nullptr), arrSize(0){}
    Array(unsigned int n) : array(new T[n]()), arrSize(n) {}
    T &operator[](unsigned int i)
    {
        return array[i];
    }
    Array(Array const &oth) : array(oth.array), arrSize(oth.arrSize){}
    // Array &operator=(Array const &oth)
    // {
    //     if (this != &oth)
    //     {
            
    //     }
    //     return (*this);
    // }
    ~Array();
    unsigned int getSize()
    {
        return this->arrSize;
    }
    unsigned int size()
    {
        return getSize();
    }
};