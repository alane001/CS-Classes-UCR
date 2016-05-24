#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
double fileSum (string filename);

int main() {
   ifstream inFS;
   string filename;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   // causes error prompt saying that the filename does not exist
   if (!inFS.is_open()) {
      cout << "Error opening " << filename << endl;
      return 1; // 1 indicates error
   }
   cout << "Sum: " << fileSum(filename) << endl;

   return 0;
}

// Place fileSum implementation here
double fileSum (string filename){
   ifstream inFS;
   int filenum = 0;
   int sum = 0;
   inFS.open(filename.c_str());

   // DONT PLACE IN FUNCTION kept causing return of 1 to sum
   //if (!inFS.is_open()) {
   //   cout << "Error opening " << filename << endl;
   //   return 1; // 1 indicates error
   //}
   //else{
   inFS >> filenum;
   while (!inFS.eof()){
      sum += filenum;
      inFS >> filenum;
   }
   inFS.close();

   return sum;
   //}

}
