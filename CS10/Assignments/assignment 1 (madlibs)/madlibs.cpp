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
#include <string>
using namespace std;
int main() {
    string name, noun1, noun2, pverb, iverb, verb1, adjective, noun3, number1;
    string number2, number3, animal, verb2, noun4, verb3;
    // Paragraph 1 start
    cout << "Please, enter a name: ";
    cin >> name;
    cout << endl << "Please, enter a noun: ";
    cin >> noun1;
    cout << endl << "Please, enter a noun: ";
    cin >> noun2;
    cout << endl << "Please, enter a plural verb: ";
    cin >> pverb;
    cout << endl << "Please, enter a verb ending in -ing: ";
    cin >> iverb;
    // Paragraph 2 start
    cout << endl << "Please, enter a verb: ";
    cin >> verb1;
    cout << endl << "Please, enter an adjective: ";
    cin >> adjective;
    cout << endl << "Please, enter a noun: ";
    cin >> noun3;
    cout << endl << "Please, enter a single digit number: ";
    cin >> number1;
    cout << endl << "Please, enter a single digit number: ";
    cin >> number2;
    // Paragraph 3 start
    cout << endl << "Please, enter a single digit number: ";
    cin >> number3;
    cout << endl << "Please, enter a type of animal: ";
    cin >> animal;
    cout << endl << "Please, enter a verb: ";
    cin >> verb2;
    cout << endl << "Please, enter a noun: ";
    cin >> noun4;
    cout << endl << "Please, enter a verb: ";
    cin >> verb3;
    cout << endl;
    
    string measuringStick(80, '-');
    cout << measuringStick << endl;
    
    cout << "Hello, " << name << " here to bring you the " << noun1;
    cout << ". This is the best " << noun2;
    cout << endl << "on the market. It " << pverb << " all without ever ";
    cout << iverb << "." << endl << endl;
    
    cout << "Check out what happens when I " << verb1 << " it. Look at that ";
    cout << adjective << " " << noun3 << ".";
    cout << endl << "Call now to receive it for " << number1 << " payments of ";
    cout << number2 << ".99." << endl << endl;
    
    cout << "But wait, if you call in the next " << number3;
    cout << " minutes, we'll throw in a ";
    cout << endl << animal << ". If you ever find a better product we will ";
    cout << verb2 << " you. So pick up";
    cout << endl << "your " << noun4 << " and " << verb3 << " now." << endl;

    cout << measuringStick << endl;
    
    return 0;   
}