#include "Person.h"
#include "Worker.h"
#include "Student.h"
#include "Teacher.h"
#include "Database.h"
#include "Function.h"
#include "Interface.h"

int main()
{
    Database data("Data.txt");

    int space = 45;
    cout.width(space);
    cout << "Welcome in E-School Register!" << endl;
    separate();  

    int id;
    string pass;
    cout << "Enter your ID: ";
    cin >> id;
    cout << "Enter your password: ";
    cin >> pass;

    if(id == 123456)
    {
        if (pass == "admin")
        {
            delay(400);
            cout << "Logging in as an admin...";
            delay(600);
            system("cls");

            while (MenuAdmin(data));

            cout << "Saving Changes..." << endl;
            delay(200);
            cout << "Quitting program..." << endl;
            delay(400);
            return 0;
        }
    }

    for (auto el : data.getStudents()) 
    {
        if (el.getID() == id) 
        {
            if (el.getPass() == pass)
            {
                Student user = el;
                delay(400);
                cout << "Logged in successfully!";
                delay(600);
                system("cls");

                cout << "Welcome " << el.getName() << " " << el.getSurname() << "!" << endl;
                while (MenuStudent(user));
               
                cout << "Quitting program..." << endl;
                delay(400);
                return 0;
            }
            else 
            {
                cout << "Password does not match your ID!" << endl;
                return 0;
            }
        }
    }

    for (auto el : data.getTeachers()) 
    {
        if (el.getID() == id)
        {
            if (el.getPass() == pass)
            {
                Teacher user = el;
                delay(400);          
                cout << "Logged in successfully!";
                delay(600);
                system("cls");

                cout << "Welcome " << el.getName() << " " << el.getSurname() << "!" << endl;
                while (MenuTeacher(user, data));

                cout << "Saving Changes..." << endl;
                delay(200);
                cout << "Quitting program..." << endl;
                delay(400);
                return 0;
            }
            else
            {
                cout << "Password does not match your ID!" << endl;
                return 0;
            }
        }
    }

    for (auto el : data.getWorkers())
    {
        if (el.getID() == id)
        {
            if (el.getPass() == pass)
            {
                cout << endl;
                cout << "Welcome " << el.getName() << " " << el.getSurname() << "." << endl;
                cout << "You have no access to register." << endl;
                cout << "Quitting program..." << endl;

                delay(400);
                return 0;
            }
            else
            {
                cout << "Password does not match your ID!" << endl;
                return 0;
            }
        }
    }

    cout << "There's no user with id: " << id;
    return 0;    
}