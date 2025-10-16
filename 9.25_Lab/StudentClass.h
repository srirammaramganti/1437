#ifndef STUDENTCLASS_H
#define STUDENTCLASS_H
#include <iostream>
using namespace std;
//include the necessary headers

//declare the Student class as instructed
class Student {
    public:
        //constructor
        Student();
        Student(string firstName, string lastName, int studentID);
        //mutator
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setStudentID(int studentID);
        //accessors
        string getFirstName();
        string getLastName();
        int getStudentID();
    private:
        string firstName;
        string lastName;
        int studentID;
};

#endif