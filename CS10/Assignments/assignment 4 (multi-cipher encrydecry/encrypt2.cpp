//  =============== BEGIN ASSESSMENT HEADER ================
/// @file encrypt2.cpp 
/// @brief Cipher Multiple
///
/// @author Test Student [alane001@ucr.edu]
/// @date April 27, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <string>
using namespace std;
int main() {
    string encrDecr;
    cout << "What is the method (encryption or decryption)? ";
    cin >> encrDecr;
    cout << endl;
    if (encrDecr == "encryption"){
        string userMap, singleWord;
        string defaultUserMap="zyxwvutsrqponmlkjihgfedcba";
        cout << "What is the translation map (type 'default' to use default): ";
        cin >> userMap;
        // Using default or own map
        if (userMap=="default"){
            userMap=defaultUserMap;
        }
        else {
            userMap=userMap;
        }
        // User map size check
        int userMapCharacters=userMap.size();
        if (userMapCharacters==26){
         
        }
        else {
            cout << endl << "Error: invalid translation map size." << endl;
            return 0;
        }
        cout << endl << "What is the single word to translate: ";
        cin >> singleWord;
        cout << endl;
        for (int cnt = 0; cnt < singleWord.size(); ++cnt){
            char c1=singleWord.at(cnt);
            // Lower case letter check
            if (c1>='a'&&c1<='z'){
            }
            else {
                cout << "Error: encryption cannot be performed." << endl;
                return 0;
            }
        }
        // Getting position of letter in the alphabet
        for (int cnt = 0; cnt < singleWord.size(); ++cnt){
            char c1 = singleWord.at(cnt);
            int positionOfLetter;
            int c2='z'-c1;
            int range='z'-'a';
            positionOfLetter=range-c2;
            // Using position of letter in alphabet now convert to position in userMap
            char c3= userMap.at(positionOfLetter);
            singleWord.at(cnt) = c3;
            //cout << "Encrypted word: " << singleWord << endl;
        }
        cout << "Encrypted word: " << singleWord << endl;
    }
    else if (encrDecr == "decryption"){
        string userMap, singleWord;
        string defaultUserMap="zyxwvutsrqponmlkjihgfedcba";
        cout << "What is the translation map (type 'default' to use default): ";
        cin >> userMap;
        // Using default or own map
        if (userMap=="default"){
            userMap=defaultUserMap;
        }
        else {
            userMap=userMap;
        }
        // User map size check
        int userMapCharacters=userMap.size();
        if (userMapCharacters==26){
         
        }
        else {
            cout << endl << "Error: invalid translation map size." << endl;
            return 0;
        }
        cout << endl << "What is the single word to translate: ";
        cin >> singleWord;
        cout << endl;
        // Start decryption here:
        for (int cnt = 0; cnt < singleWord.size(); ++cnt){
            // Single character in input word at count position
            char c1=singleWord.at(cnt);
            // Decryption ability check, if character is in map
            // if find is string::npos means not found
            if (userMap.find(c1) == string::npos){
                cout << "Error: decryption cannot be performed." << endl;
                return 0;
            }
            else {
            }
        }
        for (int cnt = 0; cnt < singleWord.size(); ++cnt){
            char c2=singleWord.at(cnt);
            int positionOfLetter2 = c2 -'a';
            //cout << positionOfLetter2 << endl;
            char c3=userMap.at(positionOfLetter2);
            singleWord.at(cnt)=c3;
        }
        cout << "Decrypted word: " << singleWord << endl;
    }
    else {
        cout << "Error: invalid method choice." << endl;
        return 0;
    }
    return 0;
    }
