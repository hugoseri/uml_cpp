#include "lists.h"

void Lists::printCourses(Student stdLogged) {
    vector<Course>::iterator it;
    for(it = listCourses.begin(); it!=listCourses.end(); it++){
        if(stdLogged.courseIdInCourseChosen((it->getID())) ){
            cout<<"Course already chosen"<<endl;
        }
        it->printCourse();
    }
}


void Lists::lireFichierAccount() {
    ifstream fichier("Account.txt");
    bool test = true;
    string studentID, Name, firstName, loginID, loginPSD;

    if (fichier) {
        fichier >> studentID >> firstName >> Name  >> loginID>>  loginPSD ;//On lis la première ligne (inutile pour l'algo)
        //cout<<studentID<<" "<<firstName<<" " << Name<< " "<< loginID <<" "<<loginPSD<<endl;

        while (test) {
            fichier >> studentID >> firstName >> Name  >> loginID>>  loginPSD ;
            if (!fichier.eof()) {
                Student S(studentID, firstName, Name, loginID, loginPSD);
                listStudents.push_back(S);
            } else test = false;
        }
    } else {
        cout << "Le fichier Account.txt ne s'est pas ouvert"<<endl;
    }
}


void Lists::lireFichierCourses() {
    ifstream fichier("Course.txt");
    bool test = true;
    string CourseID, Title, Teacher, Location, CapaciteF;
    int Capacite;

    if (fichier) {
        fichier >> CourseID >> Title >> Teacher >> Location >> CapaciteF;//On lis la première ligne (inutile pour l'algo)
        //cout<<CourseID<<" "<<Title<<" " << Teacher<< " "<< Location <<" "<<loginPSD<<endl;

        while (test) {
            fichier >> CourseID >> Title >> Teacher >> Location >> Capacite;
            if (!fichier.eof()) {
                Course C(CourseID, Title, Capacite, Teacher, Location);
                listCourses.push_back(C);
            } else test = false;
        }
    } else {
        cout << "Le fichier Course.txt ne s'est pas ouvert"<<endl;
    }
}