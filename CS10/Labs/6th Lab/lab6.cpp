//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab6.cpp
/// @brief Lab 6
///
/// @author Test Student [alane001@ucr.edu]
/// @date May 6, 2014
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
        // Part 1 code
        int number1, number2;
        cout << "Enter beginning and ending numbers, separated by space: ";
        cin >> number1 >> number2;
        cout << endl;
        for (int i = number1; i <= number2; ++i) {
            if (i+1 <= number2) {
                cout << i << ", ";    
            }
            else if (i+1 > number2) {
                cout << i;
            }
        }
        cout << endl << endl;
        // Part 2 code
        int number3, number4;
        cout << "Enter beginning and ending numbers, separated by space: ";
        cin >> number3 >> number4;
        cout << endl;
        for (int j = number3; j <= number4; j= j + 2) {
            // This allows for the final number to not have a comma
            if (j+2 <= number4){
                cout << j << ", "; 
            }
            else if (j+2 > number4){
                cout << j;
            }
        }
        cout << endl << endl;
        // Part 3 code
        int number5, number6;
        cout << "Enter the beginning and largest positive numbers, ";
        cout << "separated by space: ";
        cin >> number5 >> number6;
        cout << endl;
        for (int l = number5; l <= number6; l= l * (-2)) {
            // This allows for the final number to not have a comma
            if (l*(-2) <= number6){
                cout << l << ", "; 
            }
            else if (l*(-2) > number6){
                cout << l;
            }
        }
        cout << endl << endl;
    }
    else if ( ex == 2 )
    {
        // All exercise 2
        int gradeValue = 0, numA = 0, numB = 0, numC = 0;
        int numD = 0, numF = 0;
        cout << "Enter one or more grades, or -1 to stop: " << endl;
        while (gradeValue != -1){
            cin >> gradeValue;
            if (gradeValue >= 90 && gradeValue <= 100){
                ++numA;
            }
            else if (gradeValue >= 80 && gradeValue < 90){
                ++numB;
            }
            else if (gradeValue >= 70 && gradeValue < 80){
                ++numC;
            }
            else if (gradeValue >= 60 && gradeValue < 70){
                ++numD;
            }
            else if (gradeValue >= 0 && gradeValue < 60){
                ++numF;
            }
        }
        cout << endl << "The grades breakdown is: " << endl;
        cout << "As: " << numA << endl;
        cout << "Bs: " << numB << endl;
        cout << "Cs: " << numC << endl;
        cout << "Ds: " << numD << endl;
        cout << "Fs: " << numF << endl;
    }
    
    return 0;
}