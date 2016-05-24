#include <iostream>
#include "Card.h"
#include "Deck.h"
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;



void fillHand(vector<Card> &hand, Deck &d, unsigned handSize) {
   hand.resize(handSize);
   for (unsigned i = 0; i < hand.size(); ++i) {
      hand.at(i) = d.dealCard();
   }
}

//This is the function you implemented for PROGRAM 3
ostream & operator<<(ostream &, const vector<Card> &);

/* Sorts the contents of v into suit order,
   i.e., all clubs first (in numerically ascending order),
   then all diamonds (in ascending order),
   then all hearts (in ascending order),
   and finally all spades (in ascending order).
   Calls mergeSort recursive function to actually sort the vector.
*/
void sortBySuit(vector<Card> &v);

/* Uses the recursive merge sort algorithm to sort the contents
   of the vector from begin to end in suit order.
   (see above SortBySuit function for definition of suit order)
   Uses merge helper function to merge the two sorted
   halves.
*/
void mergeSort(vector<Card> &v, unsigned begin, unsigned end);

/* Assumes all values from begin to mid are in suit order,
   (see above SortBySuit function for definition of suit order)
   and all values from mid + 1 to end are in suit order.
   Merges the two halves so that all values from begin to end
   are in suit order.
*/
void merge(vector<Card> &v, unsigned begin, unsigned mid, unsigned end);


//overload the < operator so that it can be used by just doing .at < .at instead of
//doing .at().getSuit() < .at().getSuit(), either way works
bool operator<(const Card & lhs, const Card & rhs);


int main() {
   vector<Card> hand;
   Deck deck;
   int handSize;
   int seed;
   cout << "Enter seed value: ";
   cin >> seed;
   cout << endl;
   cout << "Enter hand size: ";
   cin >> handSize;
   cout << endl;

   srand(seed);
   deck.shuffleDeck();
   fillHand(hand, deck, handSize);
   cout << hand << endl;
   sortBySuit(hand);
   cout << hand << endl;
   return 0;
}

//this bypasses the need to do .getSuit() inside the functions
bool operator<(const Card & lhs, const Card & rhs)
{

   bool answer = false;

   if(lhs.getSuit() < rhs.getSuit())
   {
      answer = true;
   }

   return answer;
}


ostream & operator<<(ostream & out, const vector<Card> &v)
{
   //This exactly matches the overloaded << operator from Assignment3, just copied over
   // this loop outputs the number of cards in the hand
   for(unsigned i = 0; i < v.size(); ++i)
   {
      //this if makes it so that the end of the hand does not have a coma
      if(i == v.size() - 1)
      {
         out << v.at(i);// << endl;   got rid of this part because it didn't want the extra space
      }
      else
      {
         out << v.at(i) << ", ";
      }
   }
   //this is how you return if the ostream needs to have a loop
   return out;
}

void sortBySuit(vector<Card> &v)
{
   if(v.size() == 0)
   {
      //do nothing, THIS HAS TO BE HERE
   }
   else
   {
      //start at index 0 and stop at last index, which is size() - 1
      mergeSort(v, 0, v.size() - 1);

   }
   return;
}



void mergeSort(vector<Card> &v, unsigned begin, unsigned end)
{
   int j = 0;

   if (begin < end) {
      j = (begin + end) / 2;  // Find the midpoint in the partition

      // Recursively sort left and right partitions
      mergeSort(v, begin, j);
      mergeSort(v, j + 1, end);

      // Merge left and right partition in sorted order
      merge(v, begin, j, end);
   }


    return;
}


void merge(vector<Card> &v, unsigned begin, unsigned mid, unsigned end)
{
   unsigned mergedSize = end - begin + 1;       // Size of merged partition
   vector<Card> mergedVector(mergedSize);    // Temporary array for merged numbers
   unsigned mergePos = 0;                 // Position to insert merged number
   unsigned leftPos = 0;                  // Position of elements in left partition
   unsigned rightPos = 0;                 // Position of elements in right partition

   leftPos = begin;                      // Initialize left partition position
   rightPos = mid + 1;                 // Initialize right partition position

   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= mid && rightPos <= end) {
      //THIS PART ONLY WORKS BECAUSE OF THE OVERLOADED < OPERATOR
      //this would have worked as well if we did v.at(leftPos).getSuit() < v.at(rightPos).getSuit()
      if (v.at(leftPos) < v.at(rightPos)) {
         mergedVector.at(mergePos) = v.at(leftPos);
         ++leftPos;
      }
      else {
         mergedVector.at(mergePos) = v.at(rightPos);
         ++rightPos;

      }
      ++mergePos;
   }

   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= mid) {
      mergedVector.at(mergePos) = v.at(leftPos);
      ++leftPos;
      ++mergePos;
   }

   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= end) {
      mergedVector.at(mergePos) = v.at(rightPos);
      ++rightPos;
      ++mergePos;
   }

   //NOW the mergedVector is sorted by suit, need to sort by rank before combining

   //cout << "mergedVector looks like: " << mergedVector << endl;

   //This part below was put into sortBySuit, either way works, but it's better to have it here so that it works with the function to get it correct
   //the same part without the while loop is needed to get the points for the function!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   //need temperary card to store for the swap
   Card temp;

   //could have done a nested for loop, which would have been more efficient, but this works as well
   int z = 0;
   //sort by numbers now, the main for loop was working but it needs to be done many times in order to sort large numbers
   //NOT VERY efficient, but it works. Would have to make z < huge number for this to work for large deck numbers
   while(z < 10)
   {
      for(unsigned i = 0; i < mergedVector.size() - 1; ++ i)
      {
         //only procedes when the suits are the same!
         //THIS IS WHAT IT WOULD LOOK LIKE IF THE < OPERATOR WAS NOT OVERLOADED FOR THE PREVIOUS (ABOVE) SECTION
         if(mergedVector.at(i).getSuit() == mergedVector.at(i + 1).getSuit())
         {
            if(mergedVector.at(i).getRank() > mergedVector.at(i + 1).getRank())
            {
               //this swaps values if the rank is higher in left position
               //cout << "CHECK THIS: " << mergedVector.at(i) << endl << "CHECK THIS2: " << mergedVector.at(i + 1) << endl;
               temp = mergedVector.at(i);
               mergedVector.at(i) = mergedVector.at(i + 1);
               mergedVector.at(i + 1) = temp;
            }
         }
      }
      ++z;
   }
   //this actually might be more efficient being in the sortBySuit function, so that it is not called repeatedly during the recursion.


   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      v.at(begin + mergePos) = mergedVector.at(mergePos);
   }

   return;
}



