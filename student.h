
#ifndef UML_STUDENT_H
#define UML_STUDENT_H

#pragma once

using namespace std;

#include <string>
#include <iostream>

#include "course.h"

class Student{
public:
Student(string Na="", string fNa="", string logID=""){Name = Na; firstName=fNa; loginID=logID ;nbCoursesChosen=0;}
    void printChosenCourses()const;
    void addCourses(Course *newCourse);
    void removeCourses(string IDtoRemove);
    string getName()const{return Name;}
private:
    string Name;
    string firstName;
    string loginID;
    Course *coursesChosen[4];
    int nbCoursesChosen;
};

#endif