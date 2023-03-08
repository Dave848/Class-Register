#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <vector>
using namespace std;

class Person {
    string type, name, surname,                     // typ(student, pracownik) / imie / nazwisko 
           PlaceOfResidence, DOB, pass, pesel;      // miejsce zamieszkania / dzien narodzin / haslo
    int ID;                                         // ID (do wyszukiwania osob w bazie danych/logowania) / nr pesel
public:
    Person(string, string, string, string, string, string, string, int);

    string getName();                               // metody get
    string getSurname();
    string getPlaceOfResidence();
    string getDOB();
    string getPass();
    string getPesel();
    string getType();
    int getID();

    void setName(string);                           // metody SET
    void setSurname(string);
    void setPlaceOfResidence(string);
    void setDOB(string);
    void setPass(string);
    void setPesel(string);
    void setType(string);
    void setID(int);

    virtual void CheckInfo();
};


#endif 
