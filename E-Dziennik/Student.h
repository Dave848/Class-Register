#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"


class Student : public Person
{
    string _class;                                // klasa
    double average_grade;                         // srednia ocen
    vector<pair<string, vector<int>>> grades;     // oceny (np. matematyka 1 4 3 5 6 itd.)
public:
    Student(string, string, string, string, string, string, string, int, string, vector<pair<string, vector<int>>>);

    string getClass();
    double getAveGrade();
    vector<pair<string, vector<int>>> getGrades();

    void setGrades(vector<pair<string, vector<int>>>);

    double CountAverageGrade();
    void CheckGrades(); 
    void CheckStudentInfo();
    void CheckSchedule();
    void CheckMails();

    Student ChangeData();
    void CheckInfo();
    bool operator==(const Student);
};

#endif
