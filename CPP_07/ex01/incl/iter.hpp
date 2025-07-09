#pragma once

#include <aio.h>
#include <string>

template <typename T>
void iter(T* array, size_t arraylen, void (*func)(T&));
