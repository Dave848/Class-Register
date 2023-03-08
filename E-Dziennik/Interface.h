#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "Database.h"

int MenuAdmin(Database&);
int MenuStudent(Student);
int MenuTeacher(Teacher, Database&);

#endif