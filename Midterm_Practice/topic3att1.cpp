#include <iostream>
#include <string>
using namespace std;

//TODO: implement compareDNA

int compareDNA(string dna1, string dna2, int results[]) {
   //int index;
   int counter = 0;

   //int stringSize = dna1.size();
   for (int i = 0; i < 10; i++) {
      if(dna1[i] != dna2[i]) {
         results[counter] = i;
         counter += 1;
         //index = i;
         //cout << i << " ";
         }
   }
   
   return counter;
}

int main() {
   string dna1, dna2;
   int results[10];
    
//TODO: get two strings from user input
   cin >> dna1 >> dna2;
//TODO: call the compareDNA() by passing D1 and D2 and an integer array storing the indices of different characters
   int result = compareDNA(dna1, dna2, results);
//TODO: print out the results
   if (result > 0) {
      cout << "There are " << result << " differences detected." << endl;
      cout << "The indexes are: ";
      for (int i = 0; i < 2; i++) {
      cout << results[i] << " ";
      }
      cout << endl;
   } else {
      cout << "The two DNAs are an exact match!" << endl;
   }
   return 0;
}