//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab7.cpp
/// @brief Lab 7
///
/// @author Test Student [alane001@ucr.edu]
/// @date May 10, 2014
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function for random number generation, don't put srand in here!
// return type int (first int) and parameters are int, the int small and the
// int large, these can match or not match variables in the main function, 
// here they match, but they do have to match eachother in the function as 
// seen in randomNum declaration just below, rand gives random number
int genRandInt (int small, int large) {
    int randomNum;
    // if small =1 and large =2 then 1 + rand gives starting range so if 0
    // it adds one making the lowest number 1 and after % gives highest num
    // 2-1 + 1 so highest is 2 so range of 1-2 for exercise # 2 
    // This is the algorithm
    randomNum = small + rand() % (large - small + 1);
    return randomNum;
}


int main()
{
    int ex;
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;
    if ( ex == 1 )
    {
        // All exercise 1
        // Use srand not rand this gives random number seed, 433 for examples
        // in instructions DO NOT put srand in a loop!!! time gives a random
        // seed in srand in order to always have the seed change
        srand(time(0));
        int small, large;
        // User picks smalles and largest number they want
        cout << "Enter the smallest possible number: ";
        cin >> small;
        cout << endl << "Enter the biggest possible number: ";
        cin >> large;
        cout << endl;
        // Give list of random numbers generated
        for (int i = 0; i <= 2; ++i) {
            int myRandNum = genRandInt(small, large);
            cout << "Random number: " << myRandNum;
            cout << endl;
        }
        
    }
    else if ( ex == 2 )
    {
        // All exercise 2
        // Use srand not rand
        srand(time(0));
        // Forces to go into loop
        string response = "yes";
        // Causes function rand num generation to only give 1 or 2
        int small = 1, large = 2;
        
        while (response != "no"){
            int newResponse;
            // Calls function to give rand 1 or 2
            newResponse = genRandInt(small, large);
            // 1 = heads 2 = tails
            if (newResponse == 1){
                cout << "Flip: heads" << endl;
            }
            else {
                cout << "Flip: tails" << endl;
            }
            cout << "Toss the coin again (yes/no)? ";
            cin >> response;
            cout << endl;
        }
        
    }
    
    return 0;
}