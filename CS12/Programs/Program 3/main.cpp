#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
//#include <stdlib.h>
//in order to write to a file
#include <fstream>

//include header files
#include "Deck.h"
#include "Card.h"

using namespace std;

/* Passes in a vector Cards and returns true if any 2 Cards have the same rank.
   Otherwise returns false.
*/
bool hasPair(const vector<Card> &);


/* Passes in a vector of Cards and outputs to the stream each Card
   separated by a comma and a space, 
   with no comma, space, or newline at the end.
*/
ostream & operator<<(ostream &, const vector<Card> &);

int main()
{
   srand(2222);
   string answer, fileName;
   unsigned cardsPerHand, numDeals;
   vector<Card> userDeck;
   
   //for use later with monte carlo method
   int count = 0;
   
   //Deck();
   
   Deck deck1;
   
   //shuffles the deck
   //deck1.shuffleDeck();
   
   
   cout << "Do you want to output all hands to a file?(Yes/No) ";
   cin >> answer;
   cout << endl;
   
   if(answer == "Yes" || answer == "yes")
   {
      cout << "Enter name of output file: ";
      cin >> fileName;
      cout << endl;
   }
   
   cout << "Enter number of cards per hand: ";
   cin >> cardsPerHand;
   cout << endl;
   
   cout << "Enter number of deals (simulations): ";
   cin >> numDeals;
   cout << endl;
   
   
   if(answer == "Yes" || answer == "yes")
   {
      //prepare to write to a file.
      ofstream file;
      //opens file to be written with c standard name (.c_str()) portion
      file.open(fileName.c_str());
      //now to write to the file just do file << "    wtv    "
      
      //shuffle the deck before hand
      deck1.shuffleDeck();
      for(unsigned i = 0; i < numDeals; ++i)
      {
         
         for(unsigned j = 0; j < cardsPerHand; ++j)
         {
            userDeck.push_back(deck1.dealCard());
         
         }
         
         if(hasPair(userDeck))
         {
            // use file instead of cout to get it to write to the file
            file << "Found Pair!! " << userDeck;
         
            //to incerement count to find percentage
            ++count;
         
         }
         else
         {
            file << "             " << userDeck;
         
         }
         //Must clear the vector after each time!
         userDeck.clear();
         
         deck1.shuffleDeck();
      
      }
      //these comments out below were to test the overloaded ostream << operator
      // with it overloaded now can just do cout << userDeck instead of loop needed
   
      //for(unsigned i = 0; i < userDeck.size(); ++i)
      //{
      //   cout << userDeck.at(i) << ", ";
      
      //}
      //file << userDeck;
   
      file.close();
   
   }  
   else
   {
      //cout << "NUMDEALS: " << numDeals << endl;
      deck1.shuffleDeck();
      for(unsigned i = 0; i < numDeals; ++i)
      {
         //cout << "i: " << i;
         for(unsigned j = 0; j < cardsPerHand; ++j)
         {
            //cout << "     j: " << j;
            userDeck.push_back(deck1.dealCard());
         
         }
         if(hasPair(userDeck))
         {
            //NO OUTPUT HERE
         
            //to incerement count to find percentage
            ++count;
         
         }
         
         //Must clear the vector after each time!
         userDeck.clear();
      
         deck1.shuffleDeck();
      
      }
   }
   
   
   
   cout << "Chances of receiving a pair in a hand of " << cardsPerHand << " cards is: " << setprecision(4) << (static_cast<double>(count) / numDeals) * 100 << "%";
   
   cout << endl;
    
    
   return 0;
}

ostream & operator<<(ostream &out, const vector<Card> &pass)
{
   // this loop outputs the number of cards in the hand
   for(unsigned i = 0; i < pass.size(); ++i)
   {
      //this if makes it so that the end of the hand does not have a coma
      if(i == pass.size() - 1)
      {
         out << pass.at(i) << endl;
      }
      else
      {
         out << pass.at(i) << ", ";
      }
   }
   //this is how you return if the ostream needs to have a loop
   return out;
   
}

bool hasPair(const vector<Card> &pass1)
{
   bool pair = false;
   int value = 0;
   
   for(unsigned i = 0; i < pass1.size(); ++i)
   {
      value = pass1.at(i).getRank();
      // cout << "i: " << i << endl;
      // cout << "Value: " << value << endl;
      for(unsigned j = i; j < pass1.size() - 1; ++j)
      {
         // cout << "j: " << j << endl;
         // cout << "Other value: " << pass1.at(j + 1).getRank() << endl << endl;
         if(pass1.at(j + 1).getRank() == value)
         {
            // cout << "FOUND!!!!!!!!!!!!!!!!!" << endl;
            pair = true;
         }
         
      
      }
      
   }
   
   //ALGORITHM below is the one I used first, it was incorrect since it only returned true if the two values were next to eachother.
   
   // for(unsigned i = 0; i < pass1.size() - 1; ++i)
   // {
   //    int value = pass1.at(i).getRank();
   //    for(unsigned j = 0; j < )
   //    if(pass1.at(i).getRank() == pass1.end().getRank())//pass1.at(i).getRank() == pass1.at(i + 1).getRank())
   //    {
   //       pair = true;
   //    }
      
   // }
   
   return pair;
}






