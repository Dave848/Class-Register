#include "Database.h"
#include "Function.h"
#include <fstream>
#include <string>
#include <sstream>

// Get functions
vector<Student> Database::getStudents() 
{
	return students;
}

vector<Worker> Database::getWorkers() 
{
	return workers;
}

vector<Teacher> Database::getTeachers()
{
	return teachers;
}

// Insert functions 
void Database::InsertStudent(Student s) 
{
	students.push_back(s);
}

void Database::InsertWorker(Worker w)
{
	workers.push_back(w);
}

void Database::InsertTeacher(Teacher t) 
{
	teachers.push_back(t);
}

// Remove functions
void Database::RemoveStudent(Student stud)
{
	students.erase(remove(students.begin(), students.end(), stud), students.end());
}

void Database::RemoveWorker(Worker work)
{
	workers.erase(remove(workers.begin(), workers.end(), work), workers.end());
}

void Database::RemoveTeacher(Teacher teach)
{
	teachers.erase(remove(teachers.begin(), teachers.end(), teach), teachers.end());
}

Database::Database(const string FileName) 
{
	ifstream in(FileName);
	if (in)
	{
		string lane;
		while (getline(in, lane)) 
		{
			stringstream ss(lane);
			string type, name, surname, PlaceOfResidence,
					DOB, pass, pesel, job, _class, subject;
			int ID;
			vector<pair<string, vector<int>>> grad;

			if (!(ss >> type))  continue;
			if (!(ss >> name))  continue;
			if (!(ss >> surname))  continue;
			if (!(ss >> PlaceOfResidence))  continue;
			if (!(ss >> DOB))  continue;
			if (!(ss >> pass))  continue;
			if (!(ss >> pesel))  continue;
			if (!(ss >> ID))  continue;

			if (type == "student")
			{
				if (!(ss >> _class))  continue;
				pair<string, vector<int>> subject_grades;
				vector<int> grades;
				
				while (ss >> subject) 
				{
					bool found0 = true;
					subject_grades.first = subject;
					while (found0)
					{
						int var;
						if (!(ss >> var))  continue;
						if (var != 0)
						{
							grades.push_back(var);
						}
						else
						{
							found0 = 0;
						}
					}

					subject_grades.second = grades;
					grad.push_back(subject_grades);
					grades.clear();
				}
				Student student = Student(type, name, surname, PlaceOfResidence, DOB, pass, pesel, ID, _class, grad);
				InsertStudent(student);
			}

			else if (type == "teacher")		
			{
				if (!(ss >> job))  continue;
				if (!(ss >> subject))  continue;
				Teacher teacher = Teacher(type, name, surname, PlaceOfResidence, DOB, pass, pesel, ID, job, subject);
				InsertTeacher(teacher);
			}

			else if (type == "worker")
			{
				if (!(ss >> job))  continue;
				Worker worker = Worker(type, name, surname, PlaceOfResidence, DOB, pass, pesel, ID, job);
				InsertWorker(worker);
			}

			else
			{
				std::cout << "Data Error. Database.cpp";
			}

		}
		in.close();
	}
}

void Database::AddGrades(Teacher user) 	//TODO: Add grades
{
	int id;
	std::cout << "Insert student's id: ";
	std::cin >> id;

	for (auto student : students)
	{
		if (id == student.getID())
		{	
			vector<pair<string, vector<int>>> grades = student.getGrades();
			RemoveStudent(student);
			for (auto pair : grades)
			{
				if (pair.first == user.getSubject())
				{
					grades.erase(remove(grades.begin(), grades.end(), pair), grades.end());
					int degree;
					std::cout << "\nWhat grade do you want to add? ";
					std::cin >> degree;

					if (degree < 1 or degree > 6)
					{
						std::cout << "Wrong value." << endl;
					}
					else
					{
						pair.second.push_back(degree);
					}
					grades.push_back(pair);
					student.setGrades(grades);
					InsertStudent(student);
					return;
				}
			}
			std::cout << "You are not teaching this student!" << endl;
			return;
		}
	}
	std::cout << "There's no student with id: " << id << endl;
	return;
	
} 

void Database::DeleteGrades(Teacher user) 	
{
	int id;
	std::cout << "Insert student's id: ";
	std::cin >> id;
	
	for (auto student : students)
	{
		if (id == student.getID())
		{
			vector<pair<string, vector<int>>> grades = student.getGrades();
			RemoveStudent(student);
			for(auto pair : grades)
			{
				if (pair.first == user.getSubject())
				{	
					grades.erase(remove(grades.begin(), grades.end(), pair), grades.end());
					std::cout << "\nStudent's " << pair.first << " grades: ";

					int i = 0;
					for (auto elem: pair.second)
					{
						std::cout << elem << " ";
						i++;
					}

					std::cout << endl << "Which grade do you want to delete?\nChoose position (1 - " << i << "): ";
					int choice;
					std::cin >> choice;
					choice--;
					pair.second.erase(pair.second.begin()+choice);

					grades.push_back(pair);
					student.setGrades(grades);
					InsertStudent(student);
					return;
				}
			}
			std::cout << "You are not teaching this student!" << endl;
			return;
		}
	}
	std::cout << "There's no student with id: " << id << endl;
	return;
}

void Database::NewStudent() 
{
	delay(600);
	system("CLS");

	string type, name, surname, PlaceOfResidence,
		DOB, pass, pesel, _class;
	int ID;
	string subj;
	pair<string, vector<int>> temp;
	vector<pair<string, vector<int>>> grad;

	type = "student";
	std::cout << "Insert student's: " << endl;
	std::cout << "- Name: ";
	std::cin >> name;
	std::cout << "- Surname: ";
	std::cin >> surname;
	std::cout<< "- Place of residence: ";
	std::cin>> PlaceOfResidence;
	std::cout<< "- Date of birth: ";
	std::cin >> DOB;
	std::cout << "- ID: ";
	std::cin >> ID;
	std::cout << "- Password: ";
	std::cin >> pass;
	std::cout << "- Pesel: ";
	std::cin >> pesel;
	std::cout << "- Class: ";
	std::cin >> _class;

	std::cout << "\nWhich subjects is the student studying? (type in 'stop' to finish inserting)\n";
	while (true)
	{
		int i = 0;
		std::cin >> subj;

		if (subj == "stop") { break;}
		if (subj != "Physics") { i++; }
		if (subj != "Maths") { i++; }
		if (subj != "English") { i++; }
		if (subj != "Polish") { i++; }
		if (subj != "Spanish") { i++; }
		if (subj != "Chemistry") { i++; }

		for (auto el: grad)
		{
			if(subj == el.first)
			{
				std::cout << "You have already added this subject.\n";
			}
		}

		if (i == 6) 
		{
			std::cout << "Wrong subject. Please try again.\n";
		}
		else
		{
			temp.first = subj;
			grad.push_back(temp);
		}
	}
	Student student = Student(type, name, surname, PlaceOfResidence, DOB, pass, pesel, ID, _class, grad);
	InsertStudent(student);
}

void Database::NewWorker()
{
	delay(600);
	system("CLS");

	string type, name, surname, PlaceOfResidence,
		DOB, pass, pesel, job;
	int ID;

	type = "worker";
	std::cout << "Insert worker's: " << endl;
	std::cout << "- Name: ";
	std::cin >> name;
	std::cout << "- Surname: ";
	std::cin >> surname;
	std::cout << "- Place of residence: ";
	std::cin >> PlaceOfResidence;
	std::cout << "- Date of birth: ";
	std::cin >> DOB;
	std::cout << "- ID: ";
	std::cin >> ID;
	std::cout << "- Password: ";
	std::cin >> pass;
	std::cout << "- Pesel: ";
	std::cin >> pesel;
	std::cout << "- Job: ";
	std::cin >> job;

	Worker worker = Worker(type, name, surname, PlaceOfResidence, DOB, pass, pesel, ID, job);
	InsertWorker(worker);
}

void Database::NewTeacher()
{
	delay(600);
	system("CLS");

	string type, name, surname, PlaceOfResidence,
		DOB, pass, pesel, job, subject;
	int ID;

	type = "teacher";
	std::cout << "Insert teacher's: " << endl;
	std::cout << "- Name: ";
	std::cin >> name;
	std::cout << "- Surname: ";
	std::cin >> surname;
	std::cout << "- Place of residence: ";
	std::cin >> PlaceOfResidence;
	std::cout << "- Date of birth: ";
	std::cin >> DOB;
	std::cout << "- ID: ";
	std::cin >> ID;
	std::cout << "- Password: ";
	std::cin >> pass;
	std::cout << "- Pesel: ";
	std::cin >> pesel;
	std::cout << "- Job: ";
	std::cin >> job;
	std::cout << "- Subject: ";
	std::cin >> subject;


	Teacher teacher = Teacher(type, name, surname, PlaceOfResidence, DOB, pass, pesel, ID, job, subject);
	InsertTeacher(teacher);
}

void Database::SaveToFile(const string FileName)
{
	ofstream file(FileName);
	for (Student student : students)
	{
		if (file.is_open()) 
		{
			file << student.getType() << " " << student.getName() << " " << student.getSurname();
			file << " " << student.getPlaceOfResidence();
			file << " " << student.getDOB() << " " << student.getPass() << " " << student.getPesel();
			file << " " << student.getID() << " " << student.getClass() << " ";
			for (auto pair : student.getGrades())
			{
				file << pair.first << " ";
				for (auto grade : pair.second) 
				{
					file << grade << " ";
				}
				file << 0 << " ";
			}
			file << endl;
		}
	}
	
	for (Worker worker : workers)
	{
		if (file.is_open())
		{
			file << worker.getType() << " " << worker.getName() << " " << worker.getSurname();
			file << " " << worker.getPlaceOfResidence();
			file << " " << worker.getDOB() << " " << worker.getPass() << " " << worker.getPesel();
			file << " " << worker.getID() << " " << worker.getJob() << endl;
		}
	}

	for (Teacher teacher: teachers)
	{
		if (file.is_open())
		{
			file << teacher.getType() << " " << teacher.getName() << " " << teacher.getSurname();
			file << " " << teacher.getPlaceOfResidence();
			file << " " << teacher.getDOB() << " " << teacher.getPass() << " " << teacher.getPesel();
			file << " " << teacher.getID() << " " << teacher.getJob() << " " << teacher.getSubject();
			file << endl;
		}
	}

	file.close();
}

Database Database::ChangeData()
{
	int id;
	std::cout << "Insert ID of person whose data you want to change: ";
	std::cin >> id;

	for (Student el : students)
	{
		if (el.getID() == id)
		{
			RemoveStudent(el);
			std::cout << endl;
			el.CheckInfo();
			el = el.ChangeData();
			std::cout << endl;
			InsertStudent(el);
			return *this;
		}
	}

	for (auto el : teachers)
	{
		if (el.getID() == id)
		{
			RemoveTeacher(el);
			std::cout << endl;
			el.CheckInfo();
			el = el.ChangeData();
			std::cout << endl;
			InsertTeacher(el);
			return *this;
		}
	}
	;
	for (auto el : workers)
	{
		if (el.getID() == id)
		{
			RemoveWorker(el);
			std::cout << endl;
			el.CheckInfo();
			el = el.ChangeData();
			std::cout << endl;
			InsertWorker(el);
			return *this;
		}
	}
	std::cout << "There's no user with id: " << id << endl << endl;
	return *this;
}