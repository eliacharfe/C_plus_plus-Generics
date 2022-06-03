#include "Person.h"

void fillPersons(Person* persons)
{   // initiate all persons

	for (int i = 0; i < ARR_SIZE; i++) {  // empty char arrays on names
		memset(persons[i].m_name, ' ', 15);
		persons[i].m_name[15] = '\0';
	}

	fillPerson(persons[0], 302278338, '2');
	fillPerson(persons[1], 204455676, '5');
	fillPerson(persons[2], 391116872, '1');
	fillPerson(persons[3], 436489555, '7');
	fillPerson(persons[4], 236489515, '9');
}
//-------------------------------------
void fillPerson(Person& person, unsigned int id, unsigned char age)
{ // initiate 1 person
	person.m_id = id;
	person.m_age = age;

	int r = rand() % (15) ;
	for (int i = 0; i < r; i++) {
		r = rand() % 26;
		char c = 'a' + r;
		if (i == 0)
			c = toupper(c);
		person.m_name[i] = c;
	}
}
//-------------------------------
void printPersons(Person* persons, string str)
{ // print all persons
	cout << str << ": " << endl << endl;;
	for (int i = 0; i < ARR_SIZE; i++) {
		std::cout << "ID: " << persons[i].m_id << std::endl
			      << "Age: " << persons[i].m_age << std::endl
		      	  << "Name: ";

		for (int j = 0; j < 16; j++)
			std::cout << persons[i].m_name[j];

		std::cout << std::endl << std::endl;
	}

	std::cout << "=================================================" << std::endl;
}
