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

/// @brief Replaces the dashes with the guessed character.
/// @param phrase the phrase to be solved
/// @param unsolved the phrase with dashes for all unsolved characters
/// @param guess the char containing the current guessed character
/// @return the new unsolved string with dashes replaced by new guess
string updateUnsolved(string phrase, string unsolved, char guess) {
    string returnUnsolved;
    // This loop runs through each letter in the begining phrase, it checks if
    // the character is equal to your guessed character and replaces it in
    // the unsolved string with the guessed character, the loop allows for 
    // multiple letters to be replaced and not just one like using .find
    for (int i = 0; i < phrase.size(); ++i) {
        if (phrase.at(i) == guess) {
            unsolved.at(i) = guess;
            returnUnsolved = unsolved;
        }
    }
    // returns the updated unsolved string with the correct guess letter.
    return returnUnsolved;
}


/// @brief Gets input until a valid input occurs, returns the valid input.
///
///    A guess is taken as input as a character. Do not use getline.
///    The guess is valid if:
///    1) the guess is an alphabetic character; and
///    2) the character has not already been guessed
///
/// @param prevGuesses the string containing all characters guessed so far
/// @return a valid guess and only a valid guess as a character
char getGuess(string prevGuesses) {
    char guess, correctGuess;
    cout << "Enter a guess: ";
    cin >> guess;
    cout << endl;
    // This loop will continue until correct guess is made
    while (correctGuess != guess) {
        // Checks if guess is a alphabetic character and checks to make sure
        // that not same character is guessed that has already been used
        if (isalpha(guess) && prevGuesses.find(guess) == string::npos) {
            correctGuess = guess;
        }
        else {
            // Has user reguess if invalid input used
            cout << "Invalid guess! Please re-enter a guess: ";
            cin >> guess;
            cout << endl;
        }
    }
    //returns the character only if it was a correct guess
    return correctGuess;
}

int main() {
    string usersPhrase, puzzle, letterGuessed;
    int guessesLeft = 7, initiation = 0, clearScr = 1;
    // Initialze char so that it wont output garbage value, this is what was 
    // messing up Rsub when I submitted it
    char guess = '0';
    // The gets begining phrase to be guessed, use getline to include spaces
    cout << "Enter phrase: ";
    getline(cin, usersPhrase);
    // it wants new lines between each input/output
    cout << endl;
    clearScreen();
    cout << endl;
    // This causes puzzle to be equal to all characters '-''s
    puzzle = setupUnsolved(usersPhrase);
    // move inside as below --> cout << "Phrase: " << puzzle << endl << endl;
    // This while executes as long as puzzle includes a - or as long as the 
    // user has not used up all of the guesses they are allowed (7)
    while (puzzle.find('-') != string::npos && guessesLeft != 0 ) {
        cout << "Phrase: " << puzzle << endl << endl;
        // use concatenation to add each new char into string, this allows
        // the orginal letter to stay and add new one on
        
        // By intializing it to '0' it allows this to skip so it wont add
        // garbage value to my output, once it goes past once then guess
        // is updated with correct character so it goes into the if statement
        // then and everything works
        if (guess != '0') {
            letterGuessed += guess;
        }
        // This if: so that it wont appear before entering a guess first
        if (isalpha(guess)){
            cout << "Guessed so far: " << letterGuessed << endl;
        }
        // This if: so that it wont appear before entering a guess first
        if (initiation == 1) {
            cout << "Wrong guesses left: " << guessesLeft;
            cout << endl << endl;
        }
        // This causes the if statement above to initiate, once a guess entered
        initiation = 1;
        guess = getGuess(puzzle);
        if (usersPhrase.find(guess) != string::npos) {
            // This causes an update to puzzle to reflect char change from - to
            // guessed char correct
            puzzle = updateUnsolved(usersPhrase, puzzle, guess);
        }
        else {
            // this lowers guess limit if an incorrect char guessed
            --guessesLeft;
        }
        if (guessesLeft == 0){
            // this causes the last clear screen below in if clearscr to not
            // execute, without this it would clear your final results
            clearScr = 0;
            // this adds the last letter entered, w/o it it wouldnt put last
            letterGuessed += guess;
            clearScreen();
            cout << endl;
            // Must add all output again just like in begining, this allows
            // for everything to be taken into account even after last clear
            cout << "Phrase: " << puzzle << endl << endl;
            cout << "Guessed so far: " << letterGuessed << endl;
            cout << "Wrong guesses left: " << guessesLeft << endl << endl;
            cout << "You lost!" << endl;
        }
        if (puzzle.find('-') == string::npos) {
            // this causes the last clear screen below in if clearscr to not
            // execute, without this it would clear your final results
            clearScr = 0;
            // this adds the last letter entered, w/o it it wouldnt put last
            letterGuessed += guess;
            // clears screen before last output
            clearScreen();
            cout << endl;
            // Must add all output again just like in begining, this allows
            // for everything to be taken into account even after last clear
            cout << "Phrase: " << puzzle << endl << endl;
            cout << "Guessed so far: " << letterGuessed << endl;
            cout << "Wrong guesses left: " << guessesLeft << endl << endl;
            cout << "Congratulations!!" << endl;
        }
        // This only executes through body, once it gets to end it doesnt exec
        if (clearScr == 1){
            clearScreen();
        }
        // Added here new line, rsub wanted a new line after clearscreen
        cout << endl;
    }
    
    
    return 0;
}
