#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_EMPLOYEES = 100;
const int MAX_KEYS = 5;

struct Key {
    string name;
    int id;
};

struct Employee {
    string name;
    int nKeysPossessed;
    Key keys[MAX_KEYS];
};

bool reader(string input_filename, Employee employees[], int& nEmployees);
void writer(string output_filename, Employee employees[], int nEmployees);
bool addKeyForEmployee(Employee employees[], int nEmployees, string emp_name, string newKey, int newID);
bool returnAKey(Employee employees[], int nEmployees, string emp_name, string returnKey);
int replaceAKey(Employee employees[], int nEmployees, string oldKey, string newKey);

// This menu is correct
void printMenu() {
    cout << "Please select from the following options: \n";
    cout << "  1. show all employees and their keys\n";
    cout << "  2. show the keys an employee possesses\n";
    cout << "  3. show which employees possess a specific key by name\n";
    cout << "  4. show which employee possess a specific key by number\n";
    cout << "  5. add a key to an employee\n";
    cout << "  6. return a key by an employee\n";
    cout << "  7. replace a key\n";
    cout << "  8. save the current key status\n";
    cout << "  0. exit the program\n";
}

bool reader(string input_filename, Employee employees[], int& nEmployees) {
    ifstream inputFile(input_filename);
    if (!inputFile)
        return false;

    inputFile >> nEmployees;
    inputFile.ignore();

    for (int i = 0; i < nEmployees; ++i) {
        getline(inputFile, employees[i].name);
        inputFile >> employees[i].nKeysPossessed;
        for (int j = 0; j < employees[i].nKeysPossessed; ++j)
            inputFile >> employees[i].keys[j].name >> employees[i].keys[j].id;
        inputFile.ignore();
    }
    inputFile.close();
    return true;
}

void writer(string output_filename, Employee employees[], int nEmployees) {
    ofstream outputFile(output_filename);
    if (!outputFile) return;
    outputFile << nEmployees << endl;
    for (int i = 0; i < nEmployees; ++i) {
        outputFile << employees[i].name << endl;
        outputFile << employees[i].nKeysPossessed;
        for (int j = 0; j < employees[i].nKeysPossessed; ++j)
            outputFile << " " << employees[i].keys[j].name << " " << employees[i].keys[j].id;
        outputFile << endl;
    }
    outputFile.close();
}

bool addKeyForEmployee(Employee employees[], int nEmployees, string emp_name, string newKey, int newID) {
    for (int i = 0; i < nEmployees; ++i) {
        if (employees[i].name == emp_name) {
            if (employees[i].nKeysPossessed >= MAX_KEYS) {
                cout << "This employee already has 5 keys!" << endl;
                return false;
            }
            for (int j = 0; j < employees[i].nKeysPossessed; ++j)
                if (employees[i].keys[j].name == newKey) {
                    cout << "This employee already has this key!" << endl;
                    return false;
                }
            employees[i].keys[employees[i].nKeysPossessed].name = newKey;
            employees[i].keys[employees[i].nKeysPossessed].id = newID;
            employees[i].nKeysPossessed++;
            return true;
        }
    }
    cout << "Cannot find the specified employee!" << endl;
    return false;
}

bool returnAKey(Employee employees[], int nEmployees, string emp_name, string returnKey) {
    for (int i = 0; i < nEmployees; ++i) {
        if (employees[i].name == emp_name) {
            for (int j = 0; j < employees[i].nKeysPossessed; ++j)
                if (employees[i].keys[j].name == returnKey) {
                    for (int k = j; k < employees[i].nKeysPossessed - 1; ++k)
                        employees[i].keys[k] = employees[i].keys[k + 1];
                    employees[i].nKeysPossessed--;
                    return true;
                }
            cout << "This employee does not have the specified key!" << endl;
            return false;
        }
    }
    cout << "Cannot find the specified employee!" << endl;
    return false;
}

int replaceAKey(Employee employees[], int nEmployees, string oldKey, string newKey) {
    int replaced = 0;
    for (int i = 0; i < nEmployees; ++i)
        for (int j = 0; j < employees[i].nKeysPossessed; ++j)
            if (employees[i].keys[j].name == oldKey) {
                int newID;
                cout << "Enter new ID for " << employees[i].name << ": ";
                cin >> newID;
                employees[i].keys[j].name = newKey;
                employees[i].keys[j].id = newID;
                replaced++;
            }
    cin.ignore();
    return replaced;
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int nEmployees = 0;
    string filename;

    cout << "Please enter key file name to start: ";
    cin >> filename;
    cin.ignore();

    if (!reader(filename, employees, nEmployees)) {
        cout << "File not found, exiting the program..." << endl;
        return 0;
    }   
    printMenu();
   
    int option;
    while (true) {
        if (!(cin >> option)) break;
        cin.ignore();

        if (option == 1) {
            for (int i = 0; i < nEmployees; ++i) {
                cout << "Name: " << employees[i].name << endl;
                cout << "Keys possessed:";
                for (int j = 0; j < employees[i].nKeysPossessed; ++j) {
                    cout << " " << employees[i].keys[j].name << "(" << employees[i].keys[j].id << ")";
                }
                cout << " " << endl;
            }
            cout << endl;
            printMenu();

        } else if (option == 2) {
            string emp_name;
            cout << "Please enter employee's name: ";
            getline(cin, emp_name);
            bool found = false;
            for (int i = 0; i < nEmployees; ++i)
                if (employees[i].name == emp_name) {
                    found = true;
                    cout << emp_name << " possess the following keys:";
                    for (int j = 0; j < employees[i].nKeysPossessed; ++j)
                        cout << " " << employees[i].keys[j].name << " (" << employees[i].keys[j].id << ")";
                    cout << " " << endl;
                    break;
                }
            if (!found) cout << "Cannot find the specified employee!" << endl;
            cout << endl;
            printMenu();

        } else if (option == 3) {
            string keyName;
            cout << "Please enter a key name: ";
            getline(cin, keyName);
            bool foundAny = false;
            for (int i = 0; i < nEmployees; ++i)
                for (int j = 0; j < employees[i].nKeysPossessed; ++j)
                    if (employees[i].keys[j].name == keyName) {
                        cout << employees[i].name << ", ";
                        foundAny = true;
                        break;
                    }
            if (foundAny) cout << "possess this key." << endl;
            else cout << "No one possesses this key." << endl;
            cout << endl;
            printMenu();

        } else if (option == 4) {
            int keyID;
            cout << "Please enter a key number: ";
            cin >> keyID;
            cin.ignore();
            bool foundAny = false;
            for (int i = 0; i < nEmployees; ++i)
                for (int j = 0; j < employees[i].nKeysPossessed; ++j)
                    if (employees[i].keys[j].id == keyID) {
                        cout << employees[i].name << " possess this key." << endl;
                        foundAny = true;
                    }
            if (!foundAny) {
                cout << "No one possesses this key number." << endl;
                cout << endl;
            }
            printMenu();

        } else if (option == 5) {
            string emp_name, newKey;
            int newID;
            cout << "Please enter employee's name: ";
            getline(cin, emp_name);
            cout << "Please enter a new key name and ID: ";
            cin >> newKey >> newID;
            cin.ignore();
            if (addKeyForEmployee(employees, nEmployees, emp_name, newKey, newID))
                cout << "Key added successfully." << endl;
            cout << endl;
            printMenu();

        } else if (option == 6) {
            string emp_name, returnKey;
            cout << "Please enter employee's name: ";
            getline(cin, emp_name);
            cout << "Please enter the returned key name: ";
            getline(cin, returnKey);
            if (returnAKey(employees, nEmployees, emp_name, returnKey))
                cout << "Key returned successfully." << endl;
            cout << endl;
            printMenu();

        } else if (option == 7) {
            string oldKey, newKey;
            cout << "Please enter old key name: ";
            getline(cin, oldKey);
            cout << "Please enter new key name: ";
            getline(cin, newKey);
            int replaced = replaceAKey(employees, nEmployees, oldKey, newKey);
            cout << "Reissued " << replaced << " keys." << endl;
            cout << endl;
            printMenu();

        } else if (option == 8) {
            string outFile;
            cout << "Please enter output file name: ";
            getline(cin, outFile);
            writer(outFile, employees, nEmployees);
            cout << "File saved successfully." << endl;
            cout << endl;
            printMenu();

        } else if (option == 0) {
            writer("keys_updated.txt", employees, nEmployees);
            cout << "Thank you for using the system! Goodbye!" << endl;
            break;

        } else {
            cout << "Not a valid option. Please try again." << endl;
            cout << endl;
            printMenu();
        }
    }
    return 0;
}