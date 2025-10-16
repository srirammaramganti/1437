#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Student {
    public:
        string name;
        int age;
        Student(string set_name, int set_age) {
            name = set_name;
            age = set_age;
        }
    private:
        
};

int main() {
    Student s1("Lucas", 17);
    cout << s1.name << " " << s1.age << endl;

    return 0;
}