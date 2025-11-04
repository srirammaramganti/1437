#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
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

void load(string fname, district districts[], int& num, int& power) {
  ifstream input(fname);
  if (!input.is_open()) {
    cout << "File not found" << endl;
    exit(1);
  }
  input >> power;
  input >> num;
  input.ignore();
  for (int i = 0; i < num; i++) {
    getline(input, districts[i].name);
    input >> districts[i].type;
    input >> districts[i].num_resident;
    input >> districts[i].power;
    input >> districts[i].has_power;
    input >> districts[i].num_technician;
    input.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int g = 0; g < districts[i].num_technician; g++) {
      getline(input, districts[i].technicians[g]);
    }
  }
  for (int i = 0; i < num - 1; i++) {
    for (int j = i + 1; j < num; j++) {
      if (districts[i].num_resident > districts[j].num_resident) {
        district temp = districts[i];
        districts[i] = districts[j];
        districts[j] = temp;
      }
    }
  }
  input.close();
}
void save(string fname, district districts[], int num, int power) {
  ofstream output(fname);
  if (!output.is_open()) {
    cout << "File not found" << endl;
    exit(1);
  }

  output << power << endl;
  output << num << endl;
  for (int i = 0; i < num; i++) {
    output << districts[i].name << endl;
    output << districts[i].type << endl;
    output << districts[i].num_resident << endl;
    output << districts[i].power << endl;
    output << districts[i].has_power << endl;
    output << districts[i].num_technician << endl;
    for (int g = 0; g < districts[i].num_technician; g++) {
      output << districts[i].technicians[g] << endl;
    }
  }
}

void printAll(district districts[], int& num, int& power) {
  cout << "The current power supply is " << power << "MW." << endl;
  for (int i = 0; i < num; i++) {
    cout << districts[i].name << endl;
    cout << "District type: " << districts[i].type << endl;
    cout << "Number of residents: " << districts[i].num_resident << endl;
    if (districts[i].has_power == false) {
        cout << "Power use: 0MW" << endl;
    } else {
        cout << "Power use: " << districts[i].power << "MW" << endl;
    }
    cout << "Has power: " << districts[i].has_power << endl;
    if (districts[i].num_technician > 0) {
      cout << "Technicians: ";
      for (int g = 0; g < districts[i].num_technician; g++) {
        cout << districts[i].technicians[g];
        if (g < districts[i].num_technician - 1) {
          cout << ", ";
        }
      }
      cout << endl;
    }
    /*cout << "Technicians: ";
    for (int g = 0; g < districts[i].num_technician; g++) {
      cout << districts[i].technicians[g];
      if (g < districts[i].num_technician - 1) {
        cout << ", ";
      }
    }
    cout << endl;*/
    cout << "---" << endl;
  }
  double totalPower = 0;
  for (int i = 0; i < num; i++) {
    if(districts[i].has_power) {
        totalPower += districts[i].power;
    }
  }
  if (totalPower > power) {
    cout << "Critical Error! The current power supply of " << power
         << "MW is insufficient to supply " << totalPower
         << "MW of power demand. Please shut off one or more districts."
         << endl;
    cout << "---" << endl;
  }
}

void cut_power(string name, district districts[], int& num) {
  for (int i = 0; i < num; i++) {
    if (districts[i].name == name) {
      districts[i].has_power = false;
      //districts[i].power = 0;
    }
  }
}

void restore_power(string name, district districts[], int& num) {
  for (int i = 0; i < num; i++) {
    if (districts[i].name == name) {
      districts[i].has_power = true;
    }
  }
}

void assign_technician(string technicianName, string districtName, district districts[], int& num) {
  bool found;
  for (int i = 0; i < num; i++) {
    if (districts[i].name == districtName) {
      districts[i].num_technician += 1;
      districts[i].technicians[districts[i].num_technician - 1] = technicianName;
      found = true;
      cout << "Technician assigned!" << endl;
    }
  }
  if (!found) {
    cout << "technician name not updated!" << endl;
  }
}

int main() {
  district districts[100];
  int num = 0;
  int power = 0;
  int newPower;
  string districtNameShutOff;
  string districtName1;
  string newTechName;
  string whatDistrictAssign;
  string outputFileName;

  string inputFileName;
  cout << "Please enter the name of the file to load:" << endl;
  cin >> inputFileName;
  load(inputFileName, districts, num, power);
  printAll(districts, num, power);

  int option = 0;
  while (true) {
    cout << "Main Menu" << endl;
    cout << "1- Status" << endl;
    cout << "2- Set Power Supply" << endl;
    cout << "3- Shutoff Power" << endl;
    cout << "4- Restore Power" << endl;
    cout << "5- Assign Technician" << endl;
    cout << "6- Save" << endl;
    cout << "7- Load" << endl;
    cout << "8- Exit" << endl;
    cout << "Please enter your choice:" << endl;

    if(!(cin >> option)) {
       return 0;
    }
    switch (option) {
      case 1:
        printAll(districts, num, power);
        break;
      case 2:
        cout << "Enter the updated power supply in megawatts:" << endl;
        cin >> newPower;
        power = newPower;
        break;
      case 3:
        cout << "Enter the name of the district:" << endl;
        cin.ignore();
        getline(cin, districtNameShutOff);
        bool changed;
        for (int i = 0; i < num; i++) {
          if (districts[i].name == districtNameShutOff) {
            districts[i].has_power = false;
            //districts[i].power = 0;
            cout << "The district's power has been successfully turned off." << endl;
            changed = true;
          }
        }
        if (!changed) {
          cout << "Error! The district with that name doesn't exist." << endl;
        }
        break;
      case 4:
        bool restored;
        cout << "Enter the name of the district:" << endl;
        cin.ignore();
        getline(cin, districtName1);
        for (int i = 0; i < num; i++) {
          if (districts[i].name == districtName1) {
            if (districts[i].has_power == false) {
              districts[i].has_power = true;
              cout << "The district's power has been successfully turned back on." << endl;
              restored = true;
            }
          }
        }
        if (!restored) {
        cout << "Error! The district with that name doesn't exist." << endl;
        }
        break;
      case 5:
        cout << "Enter the name of the technician:" << endl;
        cin.ignore();
        getline(cin, newTechName);
        cout << "Enter the name of the district to assign them to:" << endl;
        getline(cin, whatDistrictAssign);
        
        assign_technician(newTechName, whatDistrictAssign, districts, num);
        break;
      case 6:
        cout << "Enter the file name to save to: " << endl;
        cin >> outputFileName;
        save(outputFileName, districts, num, power);
        break;
      case 7:
        cout << "Enter the file name to load from: " << endl;
        cin >> inputFileName;
        load(inputFileName, districts, num, power);
        break;
      case 8:
        // cout << "Exiting program" << endl;
        return 0;
      default:
        cout << "Invalid option" << endl;
        break;
    }
  }

  return 0;
}