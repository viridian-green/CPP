#pragma once

template <class T>

class Array
{
	private:
	T *array;
    unsigned int arr_size;

    public:
    Array() : array(nullptr), arr_size(0){}
    Array(unsigned int n) : array(new T[n]()), arr_size(n) {}

Array(const Array &other) : arr_size(other.arr_size)
{
	array = new int[arr_size];

	for (size_t i = 0; i < arr_size; i++)
		array[i] = other.array[i];
}

Array &operator=(Array const &other)
{
	if (this != &other)
	{
		delete[] array;
		arr_size = other.arr_size;
		array = new int[arr_size];
		for (size_t i = 0; i < arr_size; i++) {
		array[i] = other.array[i];
	}
	}
	return (*this);
}

~Array()
{
	delete [] array;
}

T &operator[](unsigned int index)
{
	if (index > arr_size)
		throw std::out_of_range("Error. Index " + std::to_string(index) + " is out of range.");
	else
		return array[index];
}

unsigned int getSize()
{
	return arr_size;
}
unsigned int size()
{
	return getSize();
}
};