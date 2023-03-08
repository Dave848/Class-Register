#ifndef DATABASE_H
#define DATABASE_H

#include "Student.h"
#include "Worker.h"
#include "Teacher.h"

class Database 
{
	vector<Student> students;
	vector<Worker> workers;
	vector<Teacher> teachers;
public:
	Database(const string);

	vector<Student> getStudents();
	vector<Worker> getWorkers();
	vector<Teacher> getTeachers();

	void InsertStudent(Student);
	void InsertWorker(Worker);
	void InsertTeacher(Teacher);

	void RemoveStudent(Student);
	void RemoveWorker(Worker);
	void RemoveTeacher(Teacher);

	void NewStudent();
	void NewWorker();
	void NewTeacher();

	void AddGrades(Teacher);
	void DeleteGrades(Teacher);

	Database ChangeData();
	void SaveToFile(const string);
};


#endif