//  =============== BEGIN ASSESSMENT HEADER ================
/// @file madlibs.cpp 
/// @brief Madlibs
///
/// @author Test Student [alane001@ucr.edu]
/// @date April 6, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
using namespace std;
int main() {
    int isbn;
    cout << "Please enter the first 9 digits of the ISBN: ";
    cin >> isbn;
    // Obtain each individual number here (starting from right to left)
    int first, second, third, fourth, fifth, sixth, seventh, eighth, ninth;
    first=isbn%10;
    second=(isbn%100)/10;
    third=(isbn%1000)/100;
    fourth=(isbn%10000)/1000;
    fifth=(isbn%100000)/10000;
    sixth=(isbn%1000000)/100000;
    seventh=(isbn%10000000)/1000000;
    eighth=(isbn%100000000)/10000000;
    ninth=(isbn%1000000000)/100000000;
    
    // Since did right to left, program (instructions) wants it the other way
    // So instead of 1*first it will be 1*ninth!!! Big difference in output
    // Could just switch variables around (first becomes ninth ect..)
    // but it all works the same
    int checkSum, checkSum2, convertCheckSum;
    checkSum=((1*ninth)+(2*eighth)+(3*seventh)+(4*sixth)+(5*fifth)+(6*fourth));
    checkSum2= (checkSum+(7*third)+(8*second)+(9*first));
    convertCheckSum=checkSum2%11;
    cout << endl << "Checksum: " << convertCheckSum << endl;
    
    return 0;
}