#pragma once
#include "Utilities.h"

typedef struct Person
{
	unsigned int m_id;
	char m_name[16];
	unsigned char m_age;
} Person;


void fillPersons(Person* persons);
void fillPerson(Person& person, unsigned int id, unsigned char age);
void printPersons(Person* persons, string str);