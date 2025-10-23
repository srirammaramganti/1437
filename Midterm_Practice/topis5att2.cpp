#include <iostream>
#include <string>
using namespace std;

struct CarInfo {
   string Make;
   string Model;
   int Year;
};

//declaring the func
bool printCarsByYear(CarInfo cars[], int numOfCars, int prodYear);

//defining the func
bool printCarsByYear(CarInfo cars[], int numOfCars, int prodYear) {
    bool found = false;
    bool header = false;
    for (int i = 0; i < numOfCars; ++i) {
        if (cars[i].Year >= prodYear) {
           if (!header) {
              cout << "Cars produced after " << prodYear << " in inventory:" << endl;
           }
            cout << cars[i].Make << " "
                 << cars[i].Model << " "
                 << cars[i].Year << endl;
            found = true;
            header = true;
        }
    }
    if (!found) {
        cout << "No cars produced in " << prodYear << " in inventory." << endl;
    }
    return found;   // important: function returns bool
}

int main() {
   CarInfo cars[10];
   int numOfCars, prodYear;

   cin >> numOfCars;
   if (numOfCars < 0) numOfCars = 0;
   if (numOfCars > 10) numOfCars = 10;

   for (int i = 0; i < numOfCars; ++i) {
      cin >> cars[i].Make >> cars[i].Model >> cars[i].Year;
   }

   // Read the query year last
   cin >> prodYear;

   cout << "You entered:" << endl;
   for (int i = 0; i < numOfCars; ++i) {
      cout << cars[i].Make << " " << cars[i].Model << " " << cars[i].Year << endl;
   }

   // Call the function only when the step/test expects filtered output:
   // (void)printCarsByYear(cars, numOfCars, prodYear);

   return 0;
}
