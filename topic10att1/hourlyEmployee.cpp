#include "hourlyEmployee.h"

//TODO: Add destructor
HourlyEmployee::~HourlyEmployee() {
    cout << "Hourly data destroyed." << endl;
}  
//TODO: Add getTaxes()
double HourlyEmployee::getTaxes() {
    if (hours >= 100) {
        return 0.3 * (hours * wage);
    } else {
        return 0;
    }
}
//TODO: Complete getEmployeeInfo()
string HourlyEmployee::getEmployeeInfo()
{
   stringstream ss;
   ss << fixed << setprecision(2) << Employee::getEmployeeInfo() << ", salary (this month): " << wage * hours;
   return ss.str();
}
   
   
// ----- Do not modify code below this line -----

HourlyEmployee::HourlyEmployee():Employee()
{
   wage = 15;
   hours = 0;
}

HourlyEmployee::HourlyEmployee(string _name, string _ssn, double h, double w):Employee(_name, _ssn)
{
   wage = w;
   hours = h;
}