//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab4.cpp
/// @brief Lab 4
///
/// @author Test Student [alane001@ucr.edu]
/// @date April 19, 2014
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int ex;
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;
    if ( ex == 1 )
    {
  
        // All exercise 1
        string word;
        int positionOfLetter;
        cout << "Enter a string: ";
        cin >> word;
        cout << endl;
        char c1 = word.at(0);
        // Now find where that letter is located
        // Alphabet 1-26 a-z
        int range='z'-'a'+1;
        // Find position of letter in that range
        int c2;
        c2='z'-c1;
        positionOfLetter= range-c2;
        cout << c1 << " is letter " << positionOfLetter << " of the alphabet";
        cout << endl;
    }
    else if ( ex == 2 )
    {
  
        // All Exercise 2 code
        char single;
        cout << "Enter a character: ";
        cin >> single;
        cout << endl;
        if ((single>='a')&&(single<='z')){
            cout << "You entered a lowercase letter." << endl;
        }
        else if ((single>='A')&&(single<='Z')){
            cout << "You entered an uppercase letter." << endl;
        }
        else if ((single>='0')&&(single<='9')){
            cout << "You entered a numeric digit." << endl;
        }
        else {
            cout << "You entered an unknown character type." << endl;
        }
    } 
    return 0;
}