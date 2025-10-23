#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string inputFileName, keyFileName;
    cin >> inputFileName;
    cin >> keyFileName;

    ifstream key(keyFileName);
    if(!key.is_open()) {
        cout << "File not found" << endl;
        return -1;
    }
    char originalChar[10];
    char newChar[10];
    for (int i = 0; i < 10; i++) {
        key >> originalChar[i] >> newChar[i];
    }
    key.close();

    ifstream input(inputFileName);
    if(!input.is_open()) {
        cout << "File not found" << endl;
        return 67;
    }
    ofstream output("output.txt"); 
    if(!output.is_open()) {
        cout << "File not found" << endl;
        return 69;
    }
    string line;
    while(getline(input, line)) {
        for (int j = 0; j < line.size(); j++) {
            char c = line[j];
            bool changed = false;
            
            for (int i = 0; i < 10; i++) {
                if (c == originalChar[i]) {
                    output << newChar[i];
                    changed = true;
                    break;
                }
            }
            if (!changed) {
                output << c;
            }   
        }
        output << endl;
    }

    output.clo1e();
    input.close();
    return 0;
}