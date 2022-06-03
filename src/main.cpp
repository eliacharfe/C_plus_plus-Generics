#include <iostream>
#include "Sort.h"

#define SIZEOF_T(type) (unsigned __int64)(((type*)0 + 1))
#define SIZEOF_V(var) (char *)(&var + 1) - (char*)(&var)

#define sizeofCheck 0  // 0 will turn it off / 1  will turn it on
#define swapCheck 0 // 0 will turn it off / 1  will turn it on
#define qsortFunc 0 // 0 will turn it off / 1  will turn it on
#define myQuickSortFunc 0 // 0 will turn it off / 1  will turn it on

void fillArr(int* arr, int& num);
void print(int* arr);
//------------------------------------
// Program in C++
int main()
{
	srand((int)time(NULL)); // for random numbers

	Person* persons = new Person[ARR_SIZE];
	fillPersons(persons); // initiates some persons with data

#if sizeofCheck
	int i;
	char c;
	double d;
	float f;
	unsigned int ui;
	long long l;
	bool bo;
	Person p;

	cout << "sizeof(c): " << sizeof(c) << ",\t sizeof(char): " << sizeof(char) << endl <<
		"SIZEOF_V(c): " << SIZEOF_V(c) << ",\t SIZEOF_T(char): " << SIZEOF_T(char) << endl;

	cout << "sizeof(i): " << sizeof(i) << ",\t sizeof(int): " << sizeof(int) << endl <<
		"SIZEOF_V(i): " << SIZEOF_V(i) << ",\t SIZEOF_T(int): " << SIZEOF_T(int) << endl;

	cout << "sizeof(d): " << sizeof(d) << ",\t sizeof(double): " << sizeof(double) << endl <<
		"SIZEOF_V(d): " << SIZEOF_V(d) << ",\t SIZEOF_T(double): " << SIZEOF_T(double) << endl;

	cout << "sizeof(f): " << sizeof(f) << ",\t sizeof(float): " << sizeof(float) << endl <<
		"SIZEOF_V(f): " << SIZEOF_V(f) << ",\t SIZEOF_T(float): " << SIZEOF_T(float) << endl;

	cout << "sizeof(ui): " << sizeof(ui) << ",\t sizeof(unsigned int): " << sizeof(unsigned int) << endl <<
		"SIZEOF_V(x): " << SIZEOF_V(ui) << ",\t SIZEOF_T(unsigned int): " << SIZEOF_T(unsigned int) << endl;

	cout << "sizeof(l): " << sizeof(l) << ",\t sizeof(long long): " << sizeof(long long) << endl <<
		"SIZEOF_V(l): " << SIZEOF_V(l) << ",\t SIZEOF_T(long long): " << SIZEOF_T(long long) << endl;

	cout << "sizeof(bo): " << sizeof(bo) << ",\t sizeof(bool): " << sizeof(bool) << endl <<
		"SIZEOF_V(bo): " << SIZEOF_V(bo) << ",\t SIZEOF_T(bool): " << SIZEOF_T(bool) << endl;

	cout << "sizeof(p):" << sizeof(p) << ",\tsizeof(Person): " << sizeof(Person) << endl <<
		"SIZEOF_V(p):" << SIZEOF_V(p) << ",\tSIZEOF_T(Person):" << SIZEOF_T(Person) << endl << endl << endl;
#endif

#if swapCheck
	// Swap check (int* / generic)
	int* a = new int[ARR_SIZE];
	int* b = new int[ARR_SIZE-2];
	a[ARR_SIZE] = NULL;
	b[ARR_SIZE-2] = NULL;

	int num = 1;
	fillArr(a, num);
	fillArr(b, num);
	print(a);
	print(b);

	cout << "after swap (int*): \n";
	swap(a, b); // swap the 2 int* arrays
	print(a);
	print(b);

	printf("=======================================\nPersons:\n");
	printPersons(persons, "before swap");

	swapGeneric(persons[0], persons[1]); // template just in C++
	//swap(&persons[0], &persons[1], sizeof(Person)); // call the generic func - in pure C
	printPersons(persons, "swap (generic) persons[0] and persons[1]");

	swapGeneric(persons[2], persons[3]); // template just in C++
	//swap(&persons[2], &persons[3], sizeof(Person)); // call the generic func - in pure C
	printPersons(persons, "swap (generic) persons[2] and persons[3]");

#endif

#if qsortFunc 
	// using qsort func
	qsort(persons, ARR_SIZE, sizeof(Person), cmpById); // sort by id
	printPersons(persons, "Sorted by ID's (qsort)");

	qsort(persons, ARR_SIZE, sizeof(Person), cmpByAge); // sort by age
	printPersons(persons, "Sorted by ages (qsort)");

	qsort(persons, ARR_SIZE, sizeof(Person), cmpByName); // sort by names
	printPersons(persons, "Sorted by names (qsort)");
#endif


#if myQuickSortFunc
	// my generic sort implemntation
	myQuickSort(persons, 0, ARR_SIZE - 1, sizeof(Person), cmpById); // sort by id
	printPersons(persons, "Sorted by ID's (my quickSort)");

	myQuickSort(persons, 0, ARR_SIZE - 1, sizeof(Person), cmpByAge); // sort by age
	printPersons(persons, "Sorted by ages (my quickSort)");

	myQuickSort(persons, 0, ARR_SIZE - 1, sizeof(Person), cmpByName); // sort by names
	printPersons(persons, "Sorted by names (my quickSort)");

#endif

	delete[] persons;

	return EXIT_SUCCESS;
}
//--------------------------


//--------------------------
// functions for testing swap of int*
void fillArr(int* arr, int& num)
{
	for (int i = 0; arr[i] != NULL; i++) {
		arr[i] = num;
		num++;
	}
}
//-------
void print(int* arr)
{
	cout << "arr: ";
	for (int i = 0; arr[i] != NULL; i++) 
		cout << arr[i] << " ";
	cout << endl;
}
