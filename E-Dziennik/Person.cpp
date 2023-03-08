#include "Person.h"

string Person::getName() 
{
	return name;
}

string Person::getSurname() 
{
	return surname;
}

string Person::getPlaceOfResidence() 
{
	return PlaceOfResidence;
}

string Person::getDOB() 
{
	return DOB;
}

string Person::getPass()
{
	return pass;
}

string Person::getPesel() 
{
	return pesel;
}

string Person::getType() 
{
	return type;
}


int Person::getID() 
{
	return ID;
}

void Person::setName(string n) 
{
	name = n;
}

void Person::setSurname(string s) 
{
	surname = s;
}

void Person::setPlaceOfResidence(string p) 
{
	PlaceOfResidence = p;
}

void Person::setDOB(string dob)
{
	DOB = dob;
}

void Person::setPass(string p) 
{
	pass = p;
}

void Person::setID(int id) 
{
	ID = id;
}

void Person::setPesel(string pes)
{
	pesel = pes;
}

void Person::setType(string typ)
{
	type = typ;
}

Person::Person(string typ, string nam, string sur, string pla, string dob, string pas, string pes, int id)
{
	type = typ;
	name = nam;
	surname = sur;
	PlaceOfResidence = pla;
	DOB = dob;
	pass = pas;
	ID = id;
	pesel = pes;
}

void Person::CheckInfo()
{
	cout << "1. type: " << type << endl;
	cout << "2. ID: " << ID << endl;
	cout << "3. Name: " << name << endl;
	cout << "4. Surname: " << surname << endl;
	cout << "5. Place of residence: " << PlaceOfResidence << endl;
	cout << "6. Date of birth: " << DOB << endl;
	cout << "7. Pesel: " << pesel << endl;
}
