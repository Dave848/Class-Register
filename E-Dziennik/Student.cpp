#include "Student.h"

Student::Student(string typ, string nam, string sur, string pla, string dob, string pas, string pes, int id, string cla, vector<pair<string, vector<int>>> grad)
	:Person(typ, nam, sur, pla, dob, pas, pes, id)
{
	_class = cla;
	grades = grad;
	for (auto el: grades)
	{
		if (el.second.size() != 0) 
		{
			average_grade = CountAverageGrade(); 
			return;
		}
	}
	average_grade = 0;
}

string Student::getClass() 
{
	return _class;
}

double Student::getAveGrade() 
{
	return average_grade;
}

vector<pair<string, vector<int>>> Student::getGrades()
{
	return grades;
}

double Student::CountAverageGrade()
{
	vector<double> AveragePerSubject;
	double sum = 0;
	double avg;
	int i = 0;
	for (auto ele : grades)
	{
		for (auto grade : ele.second)
		{
			sum += grade;
			i++;
		} 
		avg = sum / i;
		sum = 0;
		i = 0;
		AveragePerSubject.push_back(avg);
	}

	sum = 0;
	i = 0;
	for (auto el: AveragePerSubject)
	{
		i++;
		sum += el;
	}
	return (sum / i);
}

void Student::CheckGrades()
{
	vector<pair<string, vector<int>>> grades = getGrades();
	cout << "Grades:" << endl;
	for (auto el : grades) 
	{
		cout << "- " << el.first << ": ";
		for (auto ll : el.second) 
		{
			cout << ll << " ";
		}
		cout << endl;
	}
	cout << "Average grade: " << average_grade << endl << endl;
}

void Student::CheckStudentInfo() 
{
	cout << "ID: " << getID() << endl;
	cout << "Name: " << getName() << endl;
	cout << "Surname: " << getSurname() << endl;
	cout << "Place of residence: " << getPlaceOfResidence() << endl;
	cout << "Date of birth: " << getDOB() << endl;
	cout << "Pesel: " << getPesel() << endl;
	cout << "Class: " << _class << endl;
	cout << endl;
}

void Student::CheckSchedule()
{
	cout << "Schedule is not available yet.\n\n";
}

void Student::CheckMails()
{
	cout << "You don't have new mails.\n\n";
}

void Student::setGrades(vector<pair<string, vector<int>>> grad)
{
	grades = grad;
	for (auto el : grades)
	{
		if (el.second.size() != 0)
		{
			average_grade = CountAverageGrade();
			return;
		}
	}
	average_grade = 0;
}

Student Student::ChangeData()
{
	int option;
	string var;
	cout << "\nWhich parameter do you want to change? Choose from 1-8."<< endl;
	cout << "Select 0 to leave data changing module. ";
	cin >> option;
	cout << endl;
	
	switch(option)
	{
	case 0:
	{
		return *this;
	}
	case 1:
	{
		cout << "Type can't be changed!";
		return *this;
	}
	case 2:
	{
		cout << "ID can't be changed!";
		return *this;
	}
	case 3:
	{
		cout << "Insert new name: ";
		cin >> var;
		setName(var);
		return *this;
	}
	case 4:
	{
		cout << "Insert new surname: ";
		cin >> var;
		setSurname(var);
		return *this;
	}
	case 5:
	{
		cout << "Insert new place of residence: ";
		cin >> var;
		setPlaceOfResidence(var);
		return *this;
	}
	case 6:
	{
		cout << "Insert new date of birth: ";
		cin >> var;
		setDOB(var);
		return *this;
	}
	case 7:
	{
		cout << "Insert new pesel: ";
		cin >> var;
		setPesel(var);
		return *this;
	}
	case 8:
	{
		cout << "Insert new class: ";
		cin >> var;
		_class = var;
		return *this;
	}
	default:
	{
		cout << "Wrong value.";
		return *this;
	}
	}
}

void Student::CheckInfo()
{
	Person::CheckInfo();
	cout << "8. Class: " << _class << endl;
}

bool Student::operator==(Student s) {
	if (s.getName() != getName()) { return 0; }
	else if (s.getType() != getType()) { return 0; }
	else if (s.getSurname() != getSurname()) { return 0; }
	else if (s.getPlaceOfResidence() != getPlaceOfResidence()) { return 0; }
	else if (s.getDOB() != getDOB()) { return 0; }
	else if (s.getPass() != getPass()) { return 0; }
	else if (s.getPesel() != getPesel()) { return 0; }
	else if (s.getID() != getID()) { return 0; }
	else if (s.getClass() != getClass()) { return 0; }
	else if (s.getAveGrade() != getAveGrade()) { return 0; }
	else if (s.getGrades() != getGrades()) { return 0; }
	else { return 1; }
}
