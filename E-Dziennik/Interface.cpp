#include "Person.h"
#include "Worker.h"
#include "Student.h"
#include "Teacher.h"
#include "Database.h"
#include "Function.h"
#include "Interface.h"


int MenuAdmin(Database& data)
{
	separate();
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "1. Add person." << std::endl;
	std::cout << "2. Remove person." << std::endl;
	std::cout << "3. Check info about person." << std::endl;
	std::cout << "4. Change person's data." << std::endl;
	std::cout << "5. Insert schedule." << std::endl;
	std::cout << "0. Quit application. " << std::endl;
	separate();

	int option;
	std::cout << "Choose option (0-5): ";
	std::cin >> option;
	std::cout << std::endl;

	switch (option)
	{
	case 0:
	{
		data.SaveToFile("Data.txt");
		return 0;
	}
	case 1:
	{
		WhoAreWeAdding(data);
		system("pause");
		system("CLS");
		return 1;
	}
	case 2:
	{
		WhoAreWeRemoving(data);
		system("pause");
		system("CLS");
		return 1;
	}
	case 3:
	{
		WhoAreWeChecking(data);
		system("pause");
		system("CLS");
		return 1;
	}
	case 4:
	{
		data = data.ChangeData();
		system("pause");
		system("CLS");
		return 1;
	}
	case 5:
	{
		InsertSchedule();
		system("pause");
		system("CLS");
		return 1;
	}
	default:
	{
		std::cout << "Wrong value. Try again." << std::endl;
		system("pause");
		system("CLS");
	}
	}
	return 1;
}

int MenuStudent(Student user)
{
	separate();
	std::cout << "What do you want to check?" << std::endl;
	std::cout << "1. Grades." << std::endl;
	std::cout << "2. User info." << std::endl;
	std::cout << "3. Mails." << std::endl;
	std::cout << "4. Class Schedule." << std::endl;
	std::cout << "0. Quit application. " << std::endl;
	separate();

	int option;
	std::cout << "Choose option (0-4): ";
	std::cin >> option;
	std::cout << std::endl;

	switch (option)
	{
	case 0:
	{
		return 0;
	}
	case 1:
	{
		user.CheckGrades();
		system("pause");
		system("CLS");
		return 1;
	}
	case 2:
	{
		user.CheckStudentInfo();
		system("pause");
		system("CLS");
		return 1;
	}
	case 3:
	{
		user.CheckMails();
		system("pause");
		system("CLS");
		return 1;
	}
	case 4:
	{
		user.CheckSchedule();
		system("pause");
		system("CLS");
		return 1;
	}
	default:
	{
		std::cout << "Wrong value. Try again." << std::endl;
		system("pause");
		system("CLS");
	}
	}
	return 1;
}

int MenuTeacher(Teacher user, Database& data)
{
	separate();
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "1. Add grades." << std::endl;
	std::cout << "2. Delete grades." << std::endl;
	std::cout << "3. Check information about student." << std::endl;
	std::cout << "4. Send mail." << std::endl;
	std::cout << "0. Quit application. " << std::endl;
	separate();

	int option;
	std::cout << "Choose option (0-4): ";
	std::cin >> option;

	switch (option)
	{
	case 0:
	{
		data.SaveToFile("Data.txt");
		return 0;
	}
	case 1:
	{
		data.AddGrades(user);
		system("pause");
		system("CLS");
		return 1;
	}
	case 2:
	{
		data.DeleteGrades(user);
		system("pause");
		system("CLS");
		return 1;
	}
	case 3:
	{
		GetStudentsInfo(data);
		system("pause");
		system("CLS");
		return 1;
	}
	case 4:
	{
		user.SendMail();
		system("pause");
		system("CLS");
		return 1;
	}
	default:
	{
		std::cout << "Wrong value. Try again." << std::endl;
		system("pause");
		system("CLS");
	}
	}
	return 1;
}