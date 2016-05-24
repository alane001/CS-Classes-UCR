#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt (string filename, char ch);

int main() {
   ifstream inFS;
   string filename;
   char ch;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   if (!inFS.is_open()) {
      cout << "Error opening " << filename << endl;
      return 1; // 1 indicates error
   }
   cout << "Enter a character: ";
   cin >> ch;

   cout << "# of " << ch << "'s: " << charCnt(filename, ch) << endl;

   return 0;
}

// Place charCnt implementation here
int charCnt (string filename, char ch){
   ifstream inFS;
   char input;
   int count = 0;
   //Opens file
   inFS.open(filename.c_str());

   //adds first input of character
   inFS >> input;
   //doesnt stop until the end of the file is reached
   while (!inFS.eof()){
       //updates only if the letter input is the character we search for
      if (input == ch){
         count += 1;
      }
      //adds another char into the file
      inFS >> input;
   }
   //closes the file
   inFS.close();
   //returns the count
   return count;
}
