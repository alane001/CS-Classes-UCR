//  =============== BEGIN ASSESSMENT HEADER ================
/// @file ciphersingle.cpp 
/// @brief ciphersingle
///
/// @author Test Student [alane001@ucr.edu]
/// @date April 21, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <string>
using namespace std;
int main() {
     string userMap, singleWord;
     string defaultUserMap="zyxwvutsrqponmlkjihgfedcba";
     cout << "What is the translation map (type 'default' to use default): ";
     cin >> userMap;
     // Using default or own map
     if (userMap=="default"){
          userMap=defaultUserMap;
     }
     else {
          userMap=userMap;
     }
     // User map size check
     int userMapCharacters=userMap.size();
     if (userMapCharacters==26){
         
     }
     else {
          cout << endl << "Error: invalid translation map size." << endl;
          return 0;
     }
     cout << endl << "What is the single word to translate: ";
     cin >> singleWord;
     cout << endl;
     char c1=singleWord.at(0);
     // Lower case letter check
     if (c1>='a'&&c1<='z'){
         
     }
     else {
          cout << "Error: encryption cannot be performed." << endl;
          return 0;
     }
     // Getting position of letter in the alphabet
     int positionOfLetter;
     int c2='z'-c1;
     int range='z'-'a';
     positionOfLetter=range-c2;
     // Using position of letter in alphabet now convert to position in userMap
     char c3= userMap.at(positionOfLetter);
     singleWord.at(0) = c3;
     cout << "Encrypted word: " << singleWord << endl;
    
     return 0;
}