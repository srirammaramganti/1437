#include <iostream>
#include <string>
using namespace std;

struct CarInfo {
   string Make;
   string Model;
   int Year;
};

bool printCarByYear(CarInfo cars[], int numOfCars, int prodYear) {
    //const string& firstName, const string& lastName, int newSalary) {
    bool check = false;
    bool header = false;
    for (int i = 0; i < numOfCars; i++) {
      if (cars[i].Year >= prodYear) {
        if (!header) {
            cout << "Cars produced after " << prodYear << " in inventory:" << endl;
        }
         cout << cars[i].Make << " "
              << cars[i].Model << " "
              << cars[i].Year << endl;
        check = true;
        header = true;
        }
    }
    if (!check){
        cout << "No car produced after " << prodYear << " in inventory." << endl;
    }
    return check;
}

int main() {
   CarInfo cars[10];
   int numOfCars, prodYear;

   cin >> numOfCars;
   string Make, Model;
   int Year;
   //cin >> Make >> Model >> year;
   for (int i = 0; i < numOfCars; ++i) {
        cin >> cars[i].Make
            >> cars[i].Model
            >> cars[i].Year;
    }
   cin >> prodYear;

   cout << "You entered:" << endl;
   for (int i = 0; i < numOfCars; ++i) {
      cout << cars[i].Make << " "
           << cars[i].Model << " "
           << cars[i].Year;
      cout << endl;
   }
   bool isItPrinted = printCarByYear(cars, numOfCars, prodYear);
   

   return 0;
}