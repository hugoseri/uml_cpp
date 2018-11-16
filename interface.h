#include <iostream>
using namespace std;

#pragma once

#include "student.h"

class Interface{
public:
  Interface(){login = 0;}

  Student* log_in(); //function to log in the app
  int selectOpt(int opt = 0); //function to choose the adapted menu
  void home();  //function to show home menu
  void logout(); //function to logout
  void check(); //function to show current planning
  void browse(); //function to show available courses
  void addCourse(); //function to add a course to the planning
  void removeCourse(); //function to remove a course to the planning

private:
  Student* student;
};
