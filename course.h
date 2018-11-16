
#ifndef UML_COURSE_H
#define UML_COURSE_H

#pragma once

using namespace std;

#include <string>
#include <iostream>

class Course{
public:
    Course(string ident="",string til="", int capa=0, string teach="", string loca=""){ID=ident;title=til;capacity=capa;teacher=teach;location=loca;nbRegisterStudent=0;}
    void printCourse()const;
    void updatePlaces();
    string getID(){return ID;}
private:
    string ID;
    string title;
    string teacher;
    string location;

    int capacity;
    int nbRegisterStudent;
};

#endif
