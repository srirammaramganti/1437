#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Student {
    string name, ID, major;
    float  avg_GPA;
};

void changeMajor(Student students[], string name, string newMajor) {
    for (int i = 0; i < 3; i++) {
        if (students[i].name == name) {
            students[i].major = newMajor;
        } else {
            cout << "Student not found" << endl;
        }
    }
}

void highestGPA(Student students[], int size) {
    int best = 0;
    for (int i = 1; i < size; ++i) {
        if (students[i].avg_GPA > students[best].avg_GPA) {best = i;}
    }

    cout << students[best].name  << ' '
         << students[best].ID    << ' '
         << students[best].major << ' '
         << students[best].avg_GPA << '\n';

}

int main() {
    const int size = 3;
    Student students[size];
    string newMajor;
    string name, ID, major;
    float avg_GPA;

    for (int i = 0; i < size; ++i) {
        cin >> students[i].name;
        cin >> students[i].ID;
        cin >> students[i].major;
        cin >> students[i].avg_GPA;
        //cin.ignore(); // prepare for next getline
    }

    for (int i = 0; i < 3; ++i) {
        cout << students[i].name  << ' '
             << students[i].ID    << ' '
             << students[i].major << ' '
             << students[i].avg_GPA << endl;
    }

    highestGPA(students, size);
    changeMajor(students, name, newMajor);

    return 0;
}
