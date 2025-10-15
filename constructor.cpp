#include <iostream>
using namespace std;
#include <string>

class Car {
    public:
        string make;
        string model;
        int year;
        string color;

        void printAll() {
            cout << color << " " << year << " " << make << " " << model << endl;
        }

        Car(string make, string model, int year, string color) {
            this->make = make;
            this->model = model;
            this->year = year;
            this->color = color;
        }
    private:

};

int main() {
    Car car1("Ford", "Mustang", 2018, "Blue");
    car1.printAll();

    return 0;
}