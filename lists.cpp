#include "lists.h"

void Lists::printCourses(Student* stdLogged) {
    vector<Course>::iterator it;
    for(it = listCourses.begin(); it!=listCourses.end(); it++){
      cout<<" "<<endl;
        if(stdLogged->courseIdInCourseChosen((it->getID())) ){
            cout<<"(Course already chosen)"<<endl;
        }
        it->printCourse();
    }
}

Student* Lists::checkIn(string login, string pswd) {
    Student *S=NULL;
    vector<Student>::iterator it;
    int indice=0;
    for(it = listStudents.begin(); it!=listStudents.end(); it++){

        if(it->getloginID()==login){
            if(it->getloginPSD()==pswd){
                S=&listStudents[indice];
            }
        }
        indice++;
    }
    return S;
}

Course* Lists::getCourse(string courseID){
  Course* wantedCourse = NULL;
  vector<Course>::iterator it;
  int indice = 0;
  for(it = listCourses.begin(); it!=listCourses.end(); it++){
    if (it->getID() == courseID){
      wantedCourse = &listCourses[indice];
    }
    indice++;
  }
  return wantedCourse;
}


void Lists::lireFichierAccount() {
    ifstream fichier("Account.txt");
    bool test = true;
    string studentID, Name, firstName, loginID, loginPSD;

    if (fichier) {
        fichier >> studentID >> firstName >> Name  >> loginID>>  loginPSD ;//reading title line (useless)
        //cout<<studentID<<" "<<firstName<<" " << Name<< " "<< loginID <<" "<<loginPSD<<endl;

        while (test) {
            fichier >> studentID >> firstName >> Name  >> loginID>>  loginPSD ;
            if (!fichier.eof()) {
                Student S(studentID, firstName, Name, loginID, loginPSD);
                listStudents.push_back(S);
            } else test = false;
        }
    } else {
        cout << "Account.txt file didn't opened correctly"<<endl;
    }
}


void Lists::lireFichierCourses() {
    ifstream fichier("Course.txt");
    bool test = true;
    string CourseID, Title, Teacher, Location, CapaciteF;
    int Capacite;

    if (fichier) {
        fichier >> CourseID >> Title >> Teacher >> Location >> CapaciteF;//reading title line (useless)
        //cout<<CourseID<<" "<<Title<<" " << Teacher<< " "<< Location <<" "<<loginPSD<<endl;

        while (test) {
            fichier >> CourseID >> Title >> Teacher >> Location >> Capacite;
            if (!fichier.eof()) {
                Course C(CourseID, Title, Capacite, Teacher, Location);
                listCourses.push_back(C);
            } else test = false;
        }
    } else {
        cout << "Course.txt file didn't opened correctly"<<endl;
    }
}
