#include <iostream>
#include <string>
using namespace std;

struct Employee {
   string firstName;
   string lastName;
   int age;
   int salary;
};

/*
 * Updates the salary of the employee whose first+last name match.
 * Returns true if someone was updated, false otherwise.
 */
bool givePromotion(Employee employees[], int numOfEmployees,
                   const string& firstName, const string& lastName,
                   int newSalary) {
   for (int i = 0; i < numOfEmployees; ++i) {
      if (employees[i].firstName == firstName &&
          employees[i].lastName  == lastName) {
         employees[i].salary = newSalary;
         return true;
      }
   }
   return false;
}

int main() {
   Employee employees[10];
   int numOfEmployees;

   cin >> numOfEmployees;

   for (int i = 0; i < numOfEmployees; ++i) {
      cin >> employees[i].firstName
          >> employees[i].lastName
          >> employees[i].age
          >> employees[i].salary;
   }

   string firstName, lastName;
   int newSalary;
   cin >> firstName >> lastName >> newSalary;

   cout << "Employees:" << endl;
   for (int i = 0; i < numOfEmployees; ++i) {
      cout << employees[i].firstName << " "
           << employees[i].lastName << ", "
           << employees[i].age << " years old. Salary: $"
           << employees[i].salary << endl;
   }

   // Try to apply the promotion
   bool updated = givePromotion(employees, numOfEmployees, firstName, lastName, newSalary);
   cout << endl;
   if (updated) {
      cout << "Updated Employees:" << endl;
      for (int i = 0; i < numOfEmployees; ++i) {
         cout << employees[i].firstName << " "
              << employees[i].lastName << ", "
              << employees[i].age << " years old. Salary: $"
              << employees[i].salary << endl;
      }
   } else {
      cout << "Employee not found" << endl;
   }

   return 0;
}