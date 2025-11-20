#include "employee.h"
#include "salaryEmployee.h"
#include "hourlyEmployee.h"

//Implement taxCollector
double taxCollector(Employee* employees[], int size) {
    double totalTaxes;
    for (int i = 0; i < size; ++i) {
        if (employees[i] != nullptr) {
            totalTaxes += employees[i]->getTaxes();
        }
    }
    return totalTaxes;
}
int main() 
{
   //Uncomment for final test (include destructors)
   Employee *e[3];
      
   e[0] = new SalaryEmployee("Jane Watson", "12345", 70000);
   e[1] = new HourlyEmployee("John Doe", "10101", 200, 12);
   
   for(int i = 0; i < 2; i++)
      delete e[i];
   
   return 0;
}