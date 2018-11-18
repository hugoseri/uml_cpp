#include <iostream>
#include <string>
using namespace std;

#include "interface.h"
#include "lists.h"

Student* Interface::log_in(){
  student = NULL;
  int compteur = 0;
  while(student == NULL){
    if (compteur>0){
      cout<<"\n****ERROR : Try again.****"<<endl;
    }
    cout<<"\nPlease enter your login and password.\n"<<endl;
    cout<<"login : ";
    string login;
    cin>>login;
    cout<<"password : ";
    string pwd;
    cin>>pwd;
    student = myLists->checkIn(login,pwd);
    compteur++;
  }
}

int Interface::selectOpt(int opt){
  switch (opt) {
    case 0: //home
      opt = home(opt);
      selectOpt(opt);

    case 1: //Logout
      logout();
      break;

    case 2: //available courses
      opt = browse(opt);
      selectOpt(opt);

    case 3: //current planning
      opt = check(opt);
      selectOpt(opt);

    default:
      selectOpt(opt);
  }
}

int Interface::home(int opt){
  cout<<"\n\n*****Welcome "<<student->getName()<<" !*****"<<endl;
  cout<<"\nChoose what you want to do :\n"<<endl;
  cout<<"1 : Logout"<<endl;
  cout<<"2 : Browse available courses"<<endl;
  cout<<"3 : Check my current planning"<<endl;
  cout<<"\n Select your action [1-3] : ";
  cin>>opt;
  return opt;
}

void Interface::logout(){
  cout<<"*****Goodbye "<<student->getName()<<" !*****"<<endl;
}

int Interface::check(int opt){
  cout<<"\n****Chosen courses : *****\n"<<endl;
  student->printChosenCourses();
  cout<<"\nChoose what you want to do :\n"<<endl;
  cout<<"0 : Go to home page"<<endl;
  cout<<"1 : Logout"<<endl;
  cout<<"2 : Add a new course"<<endl;
  cout<<"3 : Delete a selected course"<<endl;
  cout<<"\n Select your action [0-3] : ";
  cin>>opt;
  if (opt == 3){
    removeCourse();
  }
  return opt;
}

int Interface::browse(int opt){
  cout<<"\n*****Courses available :*****\n"<<endl;
  myLists->printCourses(student);
  cout<<"\nChoose what you want to do :\n"<<endl;
  cout<<"0 : Go to home page"<<endl;
  cout<<"1 : Logout"<<endl;
  cout<<"2 : Add a new course"<<endl;
  cout<<"\n Select your action [0-3] : ";
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

  Course * newCourse = myLists->getCourse(id_course_add);
  student->addCourses(newCourse);
}

void Interface::removeCourse(){
  cout<<"Course to delete [ID]: ";
  string id_course_del;
  cin>>id_course_del;
  student->removeCourses(id_course_del);
}
