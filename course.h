
#ifndef UML_COURSE_H
#define UML_COURSE_H

#pragma once

using namespace std;

#include <string>
#include <iostream>

#include "student.h"

class Course{
public:
    Course(string ident="",string til="", int capa=0, string descript=""){ID=ident;title=til;capacity=capa;description=descript;nbRegisterStudent=0;}
    void printCourse()const;
    void updatePlaces();
    string getID(){return ID;}
private:
    string ID;
    string title;
    int capacity;
    string description;
    int nbRegisterStudent;
};

#endif
