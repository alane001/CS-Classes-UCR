//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab2.cpp
/// @brief Lab 2
///
/// @author Test Student [alane001@ucr.edu]
/// @date April 5, 2014
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Store User Name
    string name1;
    cout << "Good day, what is your name? ";
    // Enter the Users Name
    cin >> name1;
    cout << endl << endl;
    // Store Number of Days
    int days;
    cout << "How many nice days would you like, " << name1 << "? ";
    // Enter the Number of Days
    cin >> days;
    cout << endl << endl;
    cout << "Hi, " << name1 << ", have ";
    cout << days*2 << " wonderful days!" << endl;
    return 0;
}

