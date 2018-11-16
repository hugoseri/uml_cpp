#include <iostream>
#include <string>
using namespace std;

#include "interface.h"

Student* Interface::log_in(){
  student = NULL;
  while(student == NULL){
    cout<<"Please enter your login and password.\n"<<endl;
    cout<<"login : ";
    string login;
    cin>>login;
    cout<<"password : ";
    string pwd;
    cin>>pwd;
    student = checkIn(login,pwd);
  }
}

int Interface::selectOpt(int opt){
  switch (opt) {
    case 0: //home
      opt = home();
      selectOpt(opt);

    case 1: //Logout
      logout();
      break;

    case 2: //available courses
      opt = browse();
      selectOpt(opt);

    case 3: //current planning
      opt = check();
      selectOpt(opt);

    default:
      selectOpt(opt);
  }
}

int Interface::home(){
  cout<<"*****Welcome "<<student->getName()<<" !*****"<<endl;
  cout<<"Choose what you want to do :\n"<<endl;
  cout<<"1 : Logout"<<endl;
  cout<<"2 : Browse available courses"<<endl;
  cout<<"3 : Check my current planning"<<endl;
  cout<<"\n Select your action [1-3] : "<<endl;
  cin>>opt;
  return opt;
}

int Interface::logout(){
  cout<<"*****Goodbye "<<student->getName()<<" !*****"<<endl;
}

int Interface::check(){
  cout<<"Chosen courses : \n"endl;
  student.printChosenCourses();
  cout<<"\nChoose what you want to do :\n"<<endl;
  cout<<"0 : Go to home page"<<endl;
  cout<<"1 : Logout"<<endl;
  cout<<"2 : Add a new course"<<endl;
  cout<<"3 : Delete a selected course"<<endl;
  cout<<"\n Select your action [0-3] : "<<endl;
  cin>>opt;
  if (opt == 3){
    removeCourse();
  }
  return opt;
}

int Interface::browse(){
  courses.print()
  cout<<"Choose what you want to do :\n"<<endl;
  cout<<"0 : Go to home page"<<endl;
  cout<<"1 : Logout"<<endl;
  cout<<"2 : Add a new course"<<endl;
  cout<<"\n Select your action [0-3] : "<<endl;
  cin>>opt;
  if (opt == 2){
    addCourse();
  }
  return opt;
}

void Interface::addCourse(){
  cout<<"Course to add [ID]: ";
  string id_course_add;
  cin>>id_course_add;
  student->addCourse(id_course_add);
}

void Interface::removeCourse(){
  cout<<"Course to delete [ID]: ";
  string id_course_del;
  cin>>id_course_del;
  student->deleteCourse(id_course_del);
}
