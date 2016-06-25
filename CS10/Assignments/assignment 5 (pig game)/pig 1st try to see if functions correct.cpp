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
    return addedTurn;
    
}

int main() {
    // CHANGE BEFORE RSUB!!!!!!!!!!!!!!!!!!!! to time
    srand(333);
    int valueHold, valueHoldNTurn; 
    cout << "What value should we hold at? ";
    cin >> valueHold;
    cout << endl << "Hold-at-N turn simulations? ";
    cin >> valueHoldNTurn;
    cout << endl;
    cout << "Score\t" << "Estimated Probability" << endl;
    for (int i = 1; i <= 4; ++i){
        cout << singleTurn(valueHold) << endl;
    }
    
    
    return 0;
    }
