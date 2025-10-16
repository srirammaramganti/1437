#include "StudentClass.h"

// Default constructor
Student::Student() : firstName(""), lastName(""), studentID(0) {}

// Overloaded constructor
Student::Student(const std::string& inputFirstName,
                 const std::string& inputLastName,
                 int inputID)
    : firstName(inputFirstName), lastName(inputLastName), studentID(inputID) {}

// Setters
void Student::setFirstName(const std::string& fn) { firstName = fn; }
void Student::setLastName(const std::string& ln)  { lastName  = ln; }
void Student::setStudentID(int id)                { studentID = id; }

// Getters
std::string Student::getFirstName() const { return firstName; }
std::string Student::getLastName()  const { return lastName;  }
int         Student::getStudentID() const { return studentID; }
a//include the StudentClass.h
#include "StudentClass.h"
//provide the definition of the member functions of the Student class
//constructor
Student::Student() : firstName(""), lastName(""), studentID(0) { }
Student::Student(string firstName, string lastName, int studentID) : firstName(firstName),
                                                            lastName(lastName),
                                                            studentID(studentID) { }
//mutator
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
void Student::setStudentID(int studentID) {
    this->studentID = studentID;
}
//accessors
string Student::getFirstName() {
    return firstName;    
}
string Student::getLastName() {
    return lastName;
}
int Student::getStudentID() {
    return studentID;
}
void printAll() {
    for (int i = 0; i < 3; i++) {
        cout << firstName << " " << lastName << " " << studentID << endl;
    }
}