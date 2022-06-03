#pragma once
#include "Utilities.h"

void swap(int* a, int* b);
void swap(void* a, void* b, size_t size); // in pure C works

template <class T>
void swapGeneric(T& x, T& y) // only in C++
{
    T temp = x;
    x = y;
    y = temp;
}
