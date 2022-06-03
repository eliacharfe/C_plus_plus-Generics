#include "Sort.h"

void myQuickSort(void* base, int low, int high, size_t size , int (*compare)(const void*, const void*))
{ // recursive function that sort according to the parametters given (generic)
	if (low < high)
	{
		int pivot = partition(base, low, high, size, compare);
		myQuickSort(base, low, pivot - 1, size, compare); // call recursively
		myQuickSort(base, pivot + 1, high, size, compare);// call recursively
	}
}
//------------------------------------------------
int partition(void* base, int low, int high, size_t size, int (*compare)(const void*, const void*))
{// function that do the partition part according to quicksort algorithm
    char* charArray = (char*)base; // convert to a char array
    int middle = (low + high) / 2;

    int i = compare(&charArray[low * size], &charArray[middle * size]) < 0 ? middle : low;

    if (compare(&charArray[i * size], &charArray[high * size]) >= 1) 
        i = high;
    swap(&charArray[i * size], &charArray[low * size], size); // call swap to switch places 

    i = low;
    for (low; low < high; low++) {
        if (compare(&charArray[low * size], &charArray[high * size]) <= 0)
        {
            swap(&charArray[i * size], &charArray[low * size], size);// call swap to switch places 
            i++;
        }
    }

    swap(&charArray[i * size], &charArray[high * size], size);// call swap to switch places 
    return i;
}
