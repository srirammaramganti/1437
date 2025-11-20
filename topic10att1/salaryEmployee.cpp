#include "salaryEmployee.h"

//TODO: Add destructor
SalaryEmployee::~SalaryEmployee() {
    cout << "Salary data destroyed." << endl;
}
//TODO: Add getTaxes()
double SalaryEmployee::getTaxes() {
    return 0.25 * yearSalary;
}
//TODO: Complete getEmployeeInfo()
string SalaryEmployee::getEmployeeInfo()
{
   stringstream ss;
   ss << fixed << setprecision(2) << Employee::getEmployeeInfo() << ", year salary: " << yearSalary;
   return ss.str();
}

// ----- Do not modify code below this line -----

SalaryEmployee::SalaryEmployee():Employee()
{
   yearSalary = 50000;
}

SalaryEmployee::SalaryEmployee(string _name, string _ssn, double s):Employee(_name, _ssn)
{
   yearSalary = s;
}