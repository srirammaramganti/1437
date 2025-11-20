#include "employee.h"

#ifndef HOURLY_EM_H
#define HOURLY_EM_H

class HourlyEmployee : public Employee {

private: 
   double hours;
   double wage;
   
public:
   HourlyEmployee();
   HourlyEmployee(string _name, string _ssn, double h, double w);
   void setHours(double h) { hours = h; };
   double getHours() { return hours; };
   void setWage(double w) { wage = w; };
   double getWage() { return wage; };
   
   //TODO: Add destructor
   ~HourlyEmployee() override;
   //TODO: Add getTaxes()
   double getTaxes() override;
   //TODO: Add getEmployeeInfo()
   string getEmployeeInfo() override;
};


#endif