#include<iostream>
#include "StudentClass.h"
using namespace std;

// include the StudentClass.h


int main(){
    Student student1;
    student1.setFirstName("Sandy");
    student1.setLastName("Santos");
    student1.setStudentID(6337130);
    /*create a student object using the overloaded constructor */
    cout << student1.getFirstName() << " " << student1.getLastName() << " " << student1.getStudentID() << endl;
    /*print out the student information using the individual accessor functions */
    
    return 0;
}