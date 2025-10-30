#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
using namespace std;

int main() {
    string filename;
    cin >> filename;
    ifstream input(filename);
    if (!input.is_open()) {
        cout << "File not found." << endl;
        return -1;
    }
    string line;
    while(getline(input, line)) {
        if(char = '|') {
            break;
        }
    }

    return 0;
}