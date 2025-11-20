#include "employee.h"

string Employee::getEmployeeInfo()
{
   return name + ", SSN: " + ssn;
}

Employee::~Employee()
{
   cout << "Employee data destroyed." << endl;
}

Employee::Employee()
{
   name = "";
   ssn = "00000";
};

Employee::Employee(string _name, string _ssn):name(_name),ssn(_ssn) {};