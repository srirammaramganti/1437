#include <iostream>
#include <string>
using namespace std;

class Car {
    public:
        Car(string brand, int year);
        string getBrand();
        int getYear();
        void setBrand(string brand);
        void setYear(int year);
        void printAll();
    private:
        string brand;
        int year;
};
//defining constructor out of class
Car::Car(string brand = "", int year = 0) {
    //DO NOT include the variable type in the calling of the member functions
    Car::setBrand(brand);
    Car::setYear(year);
}
string Car::getBrand() {
    //returning the brand from the setter
    return brand;
}
int Car::getYear() {
    //returing the year from the setter
    return year;
}
void Car::setBrand(string brand) {
    this->brand = brand;
}
void Car::setYear(int year) {
    this->year = year;
}
void Car::printAll() {
   cout << getBrand() << " " << getYear() << endl;
}


int main() {
    Car car1("Ford", 67);
    car1.printAll();
    //setter is setter the parameter = to input
    //getter is getting the input from the setter and returns it and prints it
    //because i set the constructor to only take 2 arguments it will always expect a 2 argument call and will give you an error otherwise
    Car car2;
    car2.setBrand("nincompoop");
    car2.setYear(2018);
    car2.printAll();


    return 0;
}