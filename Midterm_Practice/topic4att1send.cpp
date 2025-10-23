#include <iostream>
#include <fstream>

using namespace std;

//string decrypt(int decryptShifter) {  

int main() {

  string filename = "input1.txt";
  int decryptShifter;
  int encryptShifter;
  cin >> filename >> decryptShifter >> encryptShifter;
  ifstream input(filename);
  
  if(!input.is_open()) {
     cout << "File not found." << endl;
     exit(1);
  }
  
  ofstream output("decrypted.txt");
  ofstream output1("encrypted.txt");
  string line;
  while(getline(input, line)) {
     cout << line << endl;
     //output << line << endl;
      for(int i = 0; i < line.size(); i++) {
         if (line[i] >= 97 && line[i] <= 122) {
            int intNewChar = line[i] - decryptShifter;//ascii value of new char
            char newChar; //char of new val;
               if ((intNewChar >= 97) && (intNewChar <= 122)) { 
                  newChar = line[i] - decryptShifter;
                  output << newChar;
               } else if (intNewChar < 97) {
                  int overflow = (intNewChar - 97) + 123;
                  char overflowC = overflow;
                  output << overflowC;
               }
         } else {
            output << line[i];
         }
      }
      output << endl;
   }
  output.close();
  
  ifstream out("decrypted.txt");
  string line1;
  while(getline(out, line1)) {
      for(int i = 0; i < line1.size(); i++) {
         if (line1[i] >= 97 && line1[i] <= 122) {
            int intNewChar = line1[i] + encryptShifter;
            char newChar; //char of new val;
               if ((intNewChar >= 97) && (intNewChar <= 122)) { 
                  newChar = line1[i] + encryptShifter;
                  output1 << newChar;
               } else if (intNewChar > 122) {
                  int overflow = (intNewChar - 123) + 97;
                  char overflowC = overflow;
                  output1 << overflowC;
               }
         } else {
            output1 << line1[i];
         }
      }
      output1 << endl;
   }
    
   output1.close();
   input.close();
   return 0;
}
