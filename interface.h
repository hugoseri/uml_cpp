#include <iostream>
using namespace std;

#pragma once

#include "student.h"
#include "lists.h"

class Interface{
public:

  Interface(Lists* lists){myLists = lists;}
  Student* log_in(); //function to log in the app
  int selectOpt(int opt = 0); //function to choose the adapted menu
  int home(int opt);  //function to show home menu
  void logout(); //function to logout
  int check(int opt); //function to show current planning
  int browse(int opt); //function to show available courses
  void addCourse(); //function to add a course to the planning
  void removeCourse(); //function to remove a course to the planning

private:
  Student* student;
  Lists* myLists;
};
