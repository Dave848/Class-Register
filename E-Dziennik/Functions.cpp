#include "Function.h"
#include "Person.h"
#include "Student.h"
#include "Worker.h"
#include "Teacher.h"
#include "Database.h"
#include <thread>
#include <chrono>

void separate() 
{
	std::cout << "-------------------------------------------------------------" << std::endl;
}

void delay(int i)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(i));
}

void GetStudentsInfo(Database data)
{
	int id;
	cout << "Insert student's ID: ";
	cin >> id;
	cout << endl;

	for (auto el : data.getStudents())
	{
		if (el.getID() == id)
		{
			el.CheckInfo();
			el.CheckGrades();
			return;
		}
	}
	cout << "There's no student with id: " << id << endl;
}

void WhoAreWeAdding(Database& data)
{
	separate();
	std::cout << "Who do you want to add?" << std::endl;	
	std::cout << "1. Student." << std::endl;
	std::cout << "2. Worker." << std::endl;
	std::cout << "3. Teacher." << std::endl;
	separate();

	int option;
	std::cout << "Choose option (0-3): ";
	std::cin >> option;

	switch (option)
	{
	case 1:
	{
		data.NewStudent();
		return;
	}
	case 2:
	{
		data.NewWorker();
		return;
	}
	case 3:
	{
		data.NewTeacher();
		return;
	}
	default:
	{
		std::cout << "Wrong value. Try again." << std::endl;
	}
	}
}

void WhoAreWeRemoving(Database& data)
{
	int id;
	cout << "Insert ID of person that you want to remove: ";
	cin >> id;

	for (auto el : data.getStudents())
	{
		if (el.getID() == id)
		{
			string confirm;
			cout << "Confirm removing user with id: " << id << " (Type in confirm)" << endl;
			cin >> confirm;
			if(confirm == "confirm")
			{	
				data.RemoveStudent(el);
				cout << "\nStudent " << el.getName() << " " << el.getSurname() << " has been successfully removed.\n";
				return;
			}
			else
			{
				cout << "\nStudent " << el.getName() << " " << el.getSurname() << " hasn't been removed.\n";
				return;
			}
		}
	}

	for (auto el : data.getTeachers())
	{
		if (el.getID() == id)
		{
			string confirm;
			cout << "Confirm removing user with id: " << id << " (Type in confirm)" << endl;
			if (confirm == "confirm")
			{
				data.RemoveTeacher(el);
				cout << "Teacher " << el.getName() << " " << el.getSurname() << " has been successfully removed.\n";
				return;
			}
			else
			{
				return;
			}
		}
	}

	for (auto el : data.getWorkers())
	{
		if (el.getID() == id)
		{
			string confirm;
			cout << "Confirm removing user with id: " << id << " (Type in confirm)" << endl;
			if (confirm == "confirm")
			{
				data.RemoveWorker(el);
				cout << "Worker " << el.getName() << " " << el.getSurname() << " has been successfully removed.\n";
				return;
			}
			else
			{
				return;
			}
		}
	}
	cout << "There's no user with id: " << id << endl;
	return;
}

void WhoAreWeChecking(Database data) 
{
	int id;
	cout << "Insert ID of person that you want to check: ";
	cin >> id;

	for (auto el : data.getStudents())
	{
		if (el.getID() == id)
		{
			cout << endl;
			el.CheckInfo();
			el.CheckGrades();
			cout << endl;
			return;
		}
	}

	for (auto el : data.getTeachers())
	{
		if (el.getID() == id)
		{
			cout << endl;
			el.CheckInfo();
			cout << endl;
			return;
		}
	}

	for (auto el : data.getWorkers())
	{
		if (el.getID() == id)
		{
			cout << endl;
			el.CheckInfo();
			cout << endl;
			return;
		}
	}
	cout << "There's no user with id: " << id << endl << endl;
	return;
}

void InsertSchedule() {
	cout << "Schedule module is not yet implemented.\n";
}

