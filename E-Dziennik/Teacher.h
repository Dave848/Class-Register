#ifndef TEACHER_H
#define TEACHER_H

#include "Worker.h"

class Teacher : public Worker 
{
	string subject;						// jakiego przedmiotu uczy nauczyciel
public:
	Teacher(string, string, string, string, string, string, string, int, string, string);

	void SendMail();
	string getSubject();

	Teacher ChangeData();
	void CheckInfo();
	bool operator==(const Teacher);
};
#endif
