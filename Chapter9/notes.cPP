//Notes
//pre built data = int, float, double, string
#include <iostream>
using namespace std;
#include <string>

class Employee {
    //access modifiers = private, public and protected(middle of private and public)
    public:
        string name;
        string company;
        int age;

        void introduceYourself() {
            cout << name << " " << company << " " << age << endl;
        }
        //contructor always have same name as class (dont make it private because it doesnt allow any constructor work outside)
        Employee(string name, string company, int age) {
            // say that the variable outside = parameter in the constructor
            this->name = name;
            this->company = company;
            this->age = age;
        }
    //private:

};

int main() {
    //Employee employee1 = Employee("dumbass", "JP morgan", 41);
    Employee employee1("dumbass", "JP morgan", 41);
    employee1.introduceYourself();
    //Employee employee2 = Employee("skibidi", "G MOD", 67);
    Employee employee2("skibidi", "G MOD", 67);
    employee2.introduceYourself();
    
    /*basic func that is run
    employee1.name = "dumbass";
    employee1.company = "JP morgan";
    employee1.age = 41;
    employee1.introduceYourself();

    employee2.name = "skibidi";
    employee2.company = "G MOD";
    employee2.age = 67;
    employee2.introduceYourself();*/


    return 0;
}