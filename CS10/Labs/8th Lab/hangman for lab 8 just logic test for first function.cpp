//  =============== BEGIN ASSESSMENT HEADER ================
/// @file hangman.cpp 
/// @brief Hangman Game
///
/// @author Test Student [alane001@ucr.edu]
/// @date May 17, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <string>
#include "assn.h"
#include <cctype>
using namespace std;

/// @brief Puts dashes in place of alphabetic characters in the phrase.
/// @param phrase the phrase to be solved
/// @return the phrase with all alphabetic characters converted to dashes
string setupUnsolved(string phrase) {
    for (int i = 0; i < phrase.size(); ++i) {
        if (isalpha(phrase.at(i))) {
            // make sure to have single quotes not double here, its a char
            phrase.at(i) = '-';
        }
    }
    return phrase;
}
/* do this first for lab, get working REMOVEEEEEEEEEEEEEEEEEEEEEEE*/

/// @brief Replaces the dashes with the guessed character.
/// @param phrase the phrase to be solved
/// @param unsolved the phrase with dashes for all unsolved characters
/// @param guess the char containing the current guessed character
/// @return the new unsolved string with dashes replaced by new guess
// string updateUnsolved(string phrase, string unsolved, char guess);


/// @brief Gets input until a valid input occurs, returns the valid input.
///
///    A guess is taken as input as a character. Do not use getline.
///    The guess is valid if:
///    1) the guess is an alphabetic character; and
///    2) the character has not already been guessed
///
/// @param prevGuesses the string containing all characters guessed so far
/// @return a valid guess and only a valid guess as a character
// char getGuess(string prevGuesses);

int main() {
    string usersPhrase;
    cout << "Phrase: ";
    getline(cin, usersPhrase);
    clearScreen();
    cout << "Phrase: " << setupUnsolved(usersPhrase) << endl;
    
    return 0;
}
