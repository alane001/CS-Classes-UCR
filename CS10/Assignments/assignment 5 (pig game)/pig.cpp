//  =============== BEGIN ASSESSMENT HEADER ================
/// @file pig.cpp 
/// @brief Pig Game
///
/// @author Test Student [alane001@ucr.edu]
/// @date May 13, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
// This is for output manipulation
#include <iomanip>
using namespace std;

int genRandInt (int small, int large) {
    int randomNum;
    // if small =1 and large =2 then 1 + rand gives starting range so if 0
    // it adds one making the lowest number 1 and after % gives highest num
    // 2-1 + 1 so highest is 2 so range of 1-2 for exercise # 2 
    // This is the algorithm
    randomNum = small + rand() % (large - small + 1);
    // returns the value in randomNum when ever function is called
    return randomNum;
}

int singleTurn (int singleHold) {
    int firstTurn = 0, addedTurn = 0, addedTurn2 = 0;
    // This loop keeps going till the hold number is reached or roll a one
    while (addedTurn < singleHold && addedTurn2 != -1){
        
        firstTurn = genRandInt(1, 6);
        if (firstTurn == 1) {
            addedTurn2 = -1;
            addedTurn = 0;
        }
        else {
            addedTurn += firstTurn;
        }
    }
    // returns either the number above hold value or zero if roll one
    return addedTurn;
    
}

int main() {
    srand(time(0));
    int valueHold, valueHoldNTurn, storedValue, zeroCount = 0, valueHoldCount=0;
    int valueHoldCount2 = 0, valueHoldCount3 = 0, valueHoldCount4 = 0;
    int valueHoldCount5 = 0, valueHoldCount6 = 0;
    cout << "What value should we hold at? ";
    cin >> valueHold;
    cout << endl << "Hold-at-N turn simulations? ";
    cin >> valueHoldNTurn;
    cout << endl;
    cout << "Score\t" << "Estimated Probability" << endl;
    for (int i = 1; i <= valueHoldNTurn; ++i){
        storedValue = singleTurn(valueHold);
        if (storedValue == 0) {
            ++zeroCount;
        }
        else if (storedValue == valueHold) {
            ++valueHoldCount;
        }
        else if (storedValue == valueHold + 1) {
            ++valueHoldCount2;
        }
        else if (storedValue == valueHold + 2) {
            ++valueHoldCount3;
        }
        else if (storedValue == valueHold + 3) {
            ++valueHoldCount4;
        }
        else if (storedValue == valueHold + 4) {
            ++valueHoldCount5;
        }
        else if (storedValue == valueHold + 5) {
            ++valueHoldCount6;
        }
    }
    cout << fixed << setprecision(6);
    cout << "0\t" << static_cast <double> (zeroCount) / valueHoldNTurn;
    cout << endl;
    cout << valueHold << "\t"; 
    cout << static_cast <double> (valueHoldCount) / valueHoldNTurn << endl;
    cout << valueHold + 1 << "\t";
    cout << static_cast <double> (valueHoldCount2) / valueHoldNTurn << endl;
    cout << valueHold + 2 << "\t";
    cout << static_cast <double> (valueHoldCount3) / valueHoldNTurn << endl;
    cout << valueHold + 3 << "\t";
    cout << static_cast <double> (valueHoldCount4) / valueHoldNTurn << endl;
    cout << valueHold + 4 << "\t";
    cout << static_cast <double> (valueHoldCount5) / valueHoldNTurn << endl;
    cout << valueHold + 5 << "\t";
    cout << static_cast <double> (valueHoldCount6) / valueHoldNTurn << endl;
    return 0;
    }
