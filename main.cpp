#include <iostream>
#include <string>
using namespace std;

#include "interface.h"
#include "student.h"
#include "course.h"
#include "lists.h"

int main(){

  Lists L;
  Interface myInterface(&L);

  myInterface.log_in();
  myInterface.selectOpt();

  return 0;
}
