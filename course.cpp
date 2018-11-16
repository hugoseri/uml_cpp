#include "course.h"


void Course::printCourse() const {
    cout<<"ID :"<<ID<<endl;
    cout<<"Title : "<< title<<endl;
    cout<<"Capacity : "<<capacity<<endl;
    cout<<"Student(s) registered : "<< nbRegisterStudent<<endl;
    cout<<"Description : "<<description<<endl;
}

void Course::updatePlaces() {
    if (nbRegisterStudent < capacity) {
        nbRegisterStudent++;
    } else cout << "This course is full." << endl;
}