#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct district {
    string name;
    string type;
    int num_resident;
    double power;
    bool has_power;
    int num_technician;
    string technicians[10];
};

void load(string fname, district districts[], int &num, int &power) {
    ifstream input(fname);
    if(!input.is_open()) {
        cout << "File not found" << endl;
    }
    input >> power;
    input >> num;

    for (int i = 0; i < num; i++) {
        input >> districts[i].name
            >> districts[i].type
            >> districts[i].num_resident
            >> districts[i].power
            >> districts[i].has_power
            >> districts[i].num_technician;
            //>> districts[i].technicians[];
    }
    for (int i = 0; i < num; i++) {
        cout << districts[i].name << " "
             << districts[i].type << " "
             << districts[i].num_resident << " "
             << districts[i].power << " "
             << districts[i].has_power << " "
             << districts[i].num_technician;// << " "
             //<< districts[i].technicians[];
        cout << endl;
    } 
}

int main() {
    district districts[100];
    int num = 0;
    int power = 0;

    load("input.txt", districts, num, power);

    return 0;
}