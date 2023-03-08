#ifndef WORKER_H
#define WORKER_H

#include "Person.h"


class Worker : public Person 
{
    string job;                     // jako kto pracuje (nauczyciel, dyrektor, sprzataczka)
public:
    Worker(string, string, string, string, string, string, string, int, string);

    void setJob(string);
    string getJob();

    Worker ChangeData();
    void CheckInfo();
    bool operator==(const Worker);
};

#endif