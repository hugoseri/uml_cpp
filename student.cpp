#include "student.h"


void Student::printChosenCourses() const {
    for(int i =0; i<nbCoursesChosen; i++){
        coursesChosen[i]->printCourse();
        cout<<endl;
    }
}

void Student::addCourses(Course *newCourse) {
    if(nbCoursesChosen<4){
        coursesChosen[nbCoursesChosen]=newCourse;
        nbCoursesChosen++;
    }
    else{
        cout<<"Error :  You already have 4 courses."<<endl;
        cout<<"You cannot register to more than 4 courses"<<endl;
    }
}

void Student::removeCourses(string IDtoRemove) {
    int indice = -1;
    for(int i=0; i<nbCoursesChosen; i++){
            if(coursesChosen[i]->getID()==IDtoRemove){
                indice = i;
            }
    }
    if(indice!=-1){
        for(int i=indice; i<nbCoursesChosen-1; i++){
            coursesChosen[i]=coursesChosen[i+1];
        }
        nbCoursesChosen--;
    }
}