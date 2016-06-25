//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab5.cpp
/// @brief Lab 5
///
/// @author Test Student [alane001@ucr.edu]
/// @date April 27, 2014
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
        string word;
        char x='x', e='e';
        bool found=false, found2=false;
        cout << "Enter a word: ";
        cin >> word;
        cout << endl;
        for ( int cnt = 0; cnt < word.size(); ++cnt){
            if (word.at(cnt)==e){
                found = true;
            }
            if (word.at(cnt)==x){
                found2 = true;
            }
        }
        if (found2){
            cout << "Your word, " << word << ", contains the character 'x'";
            cout << endl;
        }
        if (found){
            cout << "Your word, " << word << ", contains the character 'e'";
            cout << endl;
        }
    }
    else if ( ex == 2 )
    {
        // All exercise 2
        string word;
        char x='x', e='e', i='i';
        cout << "Enter a word: ";
        cin >> word;
        cout << endl;
        for ( int cnt = 0; cnt < word.size(); ++cnt){
            if (word.at(cnt)==e){
                word.at(cnt)='3';
            }
            if (word.at(cnt)==x){
                word.at(cnt)='*';
            }
            if (word.at(cnt)==i){
                word.at(cnt)='1';
            }
        }
        cout << "Your word transformed is " << word << endl;
    }
    else if ( ex == 3 )
    {
        // All exercise 3
        string word2;
        int period, stop;
        bool q=false, w=false;
        cout << "Enter a word: ";
        cin >> word2;
        cout << endl;
        for (int cnt=0; cnt < word2.size(); ++cnt){
            if (word2.find('.')==string::npos){
                q=false;
            }
            else {
                period=word2.find('.');
                q=true;
            }
            if (word2.find("stop")==string::npos){
                w=false;
            }
            else {
                stop=word2.find("stop");
                w=true;
            }
        }
        if (q){
            cout << "The character '.' is located at index " << period;
            cout << endl;
        }
        else {
            cout << "The entry does not contain the character '.'" << endl;
        }
        if (w){
            cout << "The word \"stop\" starts at index " << stop << endl;
        }
        else {
            cout << "The entry does not contain the word \"stop\"" << endl;
        }
    }
    return 0;
}