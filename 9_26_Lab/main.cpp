#include<iostream>
#include "StudentClass.h"
using namespace std;

// include the StudentClass.h


int main(){
    Student students[3];

    for (int i = 0; i < 3; i++) {
        cin >> students[i].setFirstName() >> students[i].setLastName() >> students[i].setStudentID();
    }
    
    students.printAll();

    return 0;
}