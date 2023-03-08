#include "Teacher.h"

Teacher::Teacher(string typ, string nam, string sur, string pla, string dob, string pas, string pes, int id, string jo, string sub)
	:Worker(typ, nam, sur, pla, dob, pas, pes, id, jo)
{
	subject = sub;
}

void Teacher::SendMail()
{
	cout << "Mail system is not yet implemeted!\n\n";
}

string Teacher::getSubject()
{
	return subject;
}

Teacher Teacher::ChangeData()
{
	int option;
	string var;
	cout << "\nWhich parameter do you want to change? Choose from 1-9." << endl;
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
		cout << "You can't change job of a teacher!";
		return *this;
	}
	case 9:
	{
		cout << "Insert new subject: ";
		cin >> var;
		subject = var;
		return *this;
	}
	default:
	{
		cout << "Wrong value.";
		return *this;
	}
	}
}

void Teacher::CheckInfo() 
{
	Worker::CheckInfo();
	cout << "9. Subject: " << subject << endl;
}

bool Teacher::operator==(Teacher t) {
	if (t.getName() != getName()) { return 0; }
	else if (t.getType() != getType()) { return 0; }
	else if (t.getSurname() != getSurname()) { return 0; }
	else if (t.getPlaceOfResidence() != getPlaceOfResidence()) { return 0; }
	else if (t.getDOB() != getDOB()) { return 0; }
	else if (t.getPass() != getPass()) { return 0; }
	else if (t.getPesel() != getPesel()) { return 0; }
	else if (t.getID() != getID()) { return 0; }
	else if (t.getJob() != getJob()) { return 0; }
	else if (t.getSubject() != getSubject()) { return 0; }
	else { return 1; }
}

