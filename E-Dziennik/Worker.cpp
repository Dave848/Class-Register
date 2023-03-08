#include "Worker.h"

Worker::Worker(string typ, string nam, string sur, string pla, string dob, string pas, string pes, int id, string jo)
	:Person(typ, nam, sur, pla, dob, pas, pes, id)
{
	job = jo;
}

string Worker::getJob()
{
	return job;
}

void Worker::setJob(string j)
{
	job = j;
}

Worker Worker::ChangeData()
{
	int option;
	string var;
	cout << "\nWhich parameter do you want to change? Choose from 1-8." << endl;
	cout << "Select 0 to leave data changing module. ";
	cin >> option;
	cout << endl;

	switch (option)
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
		cout << "Insert new job: ";
		cin >> var;
		job = var;
		return *this;
	}
	default:
	{
		cout << "Wrong value.";
		return *this;
	}
	}
}

void Worker::CheckInfo() 
{
	Person::CheckInfo();
	cout << "8. Job: " << job << endl;
}

bool Worker::operator==(Worker w)
{
	if (w.getName() != getName()) { return 0; }
	else if (w.getType() != getType()) { return 0; }
	else if (w.getSurname() != getSurname()) { return 0; }
	else if (w.getPlaceOfResidence() != getPlaceOfResidence()) { return 0; }
	else if (w.getDOB() != getDOB()) { return 0; }
	else if (w.getPass() != getPass()) { return 0; }
	else if (w.getPesel() != getPesel()) { return 0; }
	else if (w.getID() != getID()) { return 0; }
	else if (w.getJob() != getJob()) { return 0; }
	else { return 1; }
}
