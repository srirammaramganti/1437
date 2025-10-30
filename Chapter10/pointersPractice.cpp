#include <iostream>
using namespace std;

int main() {
    // the * is a dereference operator where it accesses the value stored at the memory addresses
    // pointed to by a pointer variable.
    double* g;
    cout << g;
    
    int size;
    cin >> size;
    // this is the dynamically alloacted array
    int* array = new int[size];


    return 0;
}