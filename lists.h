#ifndef UML_LIST_H
#define UML_LIST_H

#pragma once

using namespace std;


#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <map>
#include <algorithm>


#include "student.h"
#include "course.h"

class Lists{
public:
    Lists(){lireFichierAccount(); lireFichierCourses();}
    Student* checkIn(string login, string pswd);
    Course* getCourse(string courseID);
    void printCourses(Student* stdLogged);

private:
    void lireFichierAccount();
    void lireFichierCourses();

    vector<Student> listStudents;
    vector<Course> listCourses;
};

#endif
