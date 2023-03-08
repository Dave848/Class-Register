#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "Database.h"


void separate();
void delay(int);

void WhoAreWeAdding(Database&);
void WhoAreWeRemoving(Database&);
void WhoAreWeChecking(Database);

void GetStudentsInfo(Database);
void InsertSchedule();

#endif