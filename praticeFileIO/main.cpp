#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string filename = "input.txt";
    //cin >> filename;
    ifstream input(filename);
    if (!input.is_open()) {
        cout << "File not found." << endl;
        return -1;
    }
    ofstream output("output.txt");
    if (!output.is_open()) {
        cout << "File skibidi found." << endl;
        return -1;
    }
    string line;
    char c;
    while(getline(input, line)) {
        if(c == '|') {
            break;
        }
        output << line << endl;
    }

    input.close();
    output.close();
    return 0;
}