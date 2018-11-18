
#ifndef UML_STUDENT_H
#define UML_STUDENT_H

#pragma once

using namespace std;

#include <string>
#include <iostream>

#include "course.h"

class Student{
public:
    Student( string stID="",string fNa="", string Na="",string logID="", string logPSD=""){studentID=stID;Name = Na; firstName=fNa; loginID=logID ;nbCoursesChosen=0; loginPSD=logPSD;}
    void printChosenCourses()const;
    void addCourses(Course* chosenCourse);
    void removeCourses(string IDtoRemove);
    string getName()const{return firstName;}
    string getloginID()const{return loginID;}
    string getloginPSD()const{return loginPSD;}
    bool courseIdInCourseChosen(string courseID);
private:
    string studentID;
    string Name;
    string firstName;
    string loginID;
    string loginPSD;
    Course *coursesChosen[4];
    int nbCoursesChosen;
};

#endif
