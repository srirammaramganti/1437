#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Employee {
 
public:
   Employee();
   Employee(string _name, string _ssn);
   string getName() { return name; };
   string getSSN() { return ssn; };
   void setName(string _name) { name = _name; };
   void setSSN(string _ssn) { ssn = _ssn; };
   string getEmployeeInfo();
   ~Employee();
   
   //TODO: Add pure virtual function getTaxes
   virtual double getTaxes();

private:
   string name;
   string ssn;
};



#endif