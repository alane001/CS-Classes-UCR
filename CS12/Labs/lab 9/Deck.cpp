#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
//#include <stdlib.h>

#include "Deck.h"

//Uses functions from Card.h so need to include it
#include "Card.h"

using namespace std;

Deck::Deck()
{
    // theDeck.push_back(Card('s', 13));
    // theDeck.push_back(Card('h', 13));
    // theDeck.push_back(Card('d', 13));
    // theDeck.push_back(Card('c', 13));
    
    // theDeck.push_back(Card('s', 12));
    // theDeck.push_back(Card('h', 12));
    // theDeck.push_back(Card('d', 12));
    // theDeck.push_back(Card('c', 12));
    
    // theDeck.push_back(Card('s', 11));
    // theDeck.push_back(Card('h', 11));
    // theDeck.push_back(Card('d', 11));
    // theDeck.push_back(Card('c', 11));
    
    // theDeck.push_back(Card('s', 10));
    // theDeck.push_back(Card('h', 10));
    // theDeck.push_back(Card('d', 10));
    // theDeck.push_back(Card('c', 10));
    
    // theDeck.push_back(Card('s', 9));
    // theDeck.push_back(Card('h', 9));
    // theDeck.push_back(Card('d', 9));
    // theDeck.push_back(Card('c', 9));
    
    // theDeck.push_back(Card('s', 8));
    // theDeck.push_back(Card('h', 8));
    // theDeck.push_back(Card('d', 8));
    // theDeck.push_back(Card('c', 8));
    
    // theDeck.push_back(Card('s', 7));
    // theDeck.push_back(Card('h', 7));
    // theDeck.push_back(Card('d', 7));
    // theDeck.push_back(Card('c', 7));
    
    // theDeck.push_back(Card('s', 6));
    // theDeck.push_back(Card('h', 6));
    // theDeck.push_back(Card('d', 6));
    // theDeck.push_back(Card('c', 6));
    
    // theDeck.push_back(Card('s', 5));
    // theDeck.push_back(Card('h', 5));
    // theDeck.push_back(Card('d', 5));
    // theDeck.push_back(Card('c', 5));
    
    // theDeck.push_back(Card('s', 4));
    // theDeck.push_back(Card('h', 4));
    // theDeck.push_back(Card('d', 4));
    // theDeck.push_back(Card('c', 4));
    
    // theDeck.push_back(Card('s', 3));
    // theDeck.push_back(Card('h', 3));
    // theDeck.push_back(Card('d', 3));
    // theDeck.push_back(Card('c', 3));
    
    // theDeck.push_back(Card('s', 2));
    // theDeck.push_back(Card('h', 2));
    // theDeck.push_back(Card('d', 2));
    // theDeck.push_back(Card('c', 2));
    
    // theDeck.push_back(Card('s', 1));
    // theDeck.push_back(Card('h', 1));
    // theDeck.push_back(Card('d', 1));
    // theDeck.push_back(Card('c', 1));
    
    //DIFFERENT VERSION OF DECK
    
    // theDeck.push_back(Card('c', 1));
    // theDeck.push_back(Card('d', 1));
    // theDeck.push_back(Card('h', 1));
    // theDeck.push_back(Card('s', 1));
    
    // theDeck.push_back(Card('c', 2));
    // theDeck.push_back(Card('d', 2));
    // theDeck.push_back(Card('h', 2));
    // theDeck.push_back(Card('s', 2));
    
    // theDeck.push_back(Card('c', 3));
    // theDeck.push_back(Card('d', 3));
    // theDeck.push_back(Card('h', 3));
    // theDeck.push_back(Card('s', 3));
    
    // theDeck.push_back(Card('c', 4));
    // theDeck.push_back(Card('d', 4));
    // theDeck.push_back(Card('h', 4));
    // theDeck.push_back(Card('s', 4));
    
    // theDeck.push_back(Card('c', 5));
    // theDeck.push_back(Card('d', 5));
    // theDeck.push_back(Card('h', 5));
    // theDeck.push_back(Card('s', 5));
    
    // theDeck.push_back(Card('c', 6));
    // theDeck.push_back(Card('d', 6));
    // theDeck.push_back(Card('h', 6));
    // theDeck.push_back(Card('s', 6));
    
    // theDeck.push_back(Card('c', 7));
    // theDeck.push_back(Card('d', 7));
    // theDeck.push_back(Card('h', 7));
    // theDeck.push_back(Card('s', 7));
    
    // theDeck.push_back(Card('c', 8));
    // theDeck.push_back(Card('d', 8));
    // theDeck.push_back(Card('h', 8));
    // theDeck.push_back(Card('s', 8));
    
    // theDeck.push_back(Card('c', 9));
    // theDeck.push_back(Card('d', 9));
    // theDeck.push_back(Card('h', 9));
    // theDeck.push_back(Card('s', 9));
    
    // theDeck.push_back(Card('c', 10));
    // theDeck.push_back(Card('d', 10));
    // theDeck.push_back(Card('h', 10));
    // theDeck.push_back(Card('s', 10));
    
    // theDeck.push_back(Card('c', 11));
    // theDeck.push_back(Card('d', 11));
    // theDeck.push_back(Card('h', 11));
    // theDeck.push_back(Card('s', 11));
    
    // theDeck.push_back(Card('c', 12));
    // theDeck.push_back(Card('d', 12));
    // theDeck.push_back(Card('h', 12));
    // theDeck.push_back(Card('s', 12));
    
    // theDeck.push_back(Card('c', 13));
    // theDeck.push_back(Card('d', 13));
    // theDeck.push_back(Card('h', 13));
    // theDeck.push_back(Card('s', 13));
    
    // A DIFFERENT VERSION OF THE DECK BELOW
    
    // theDeck.push_back(Card('c', 1));
    // theDeck.push_back(Card('c', 2));
    // theDeck.push_back(Card('c', 3));
    // theDeck.push_back(Card('c', 4));
    // theDeck.push_back(Card('c', 5));
    // theDeck.push_back(Card('c', 6));
    // theDeck.push_back(Card('c', 7));
    // theDeck.push_back(Card('c', 8));
    // theDeck.push_back(Card('c', 9));
    // theDeck.push_back(Card('c', 10));
    // theDeck.push_back(Card('c', 11));
    // theDeck.push_back(Card('c', 12));
    // theDeck.push_back(Card('c', 13));
    
    // theDeck.push_back(Card('d', 1));
    // theDeck.push_back(Card('d', 2));
    // theDeck.push_back(Card('d', 3));
    // theDeck.push_back(Card('d', 4));
    // theDeck.push_back(Card('d', 5));
    // theDeck.push_back(Card('d', 6));
    // theDeck.push_back(Card('d', 7));
    // theDeck.push_back(Card('d', 8));
    // theDeck.push_back(Card('d', 9));
    // theDeck.push_back(Card('d', 10));
    // theDeck.push_back(Card('d', 11));
    // theDeck.push_back(Card('d', 12));
    // theDeck.push_back(Card('d', 13));
    
    // theDeck.push_back(Card('h', 1));
    // theDeck.push_back(Card('h', 2));
    // theDeck.push_back(Card('h', 3));
    // theDeck.push_back(Card('h', 4));
    // theDeck.push_back(Card('h', 5));
    // theDeck.push_back(Card('h', 6));
    // theDeck.push_back(Card('h', 7));
    // theDeck.push_back(Card('h', 8));
    // theDeck.push_back(Card('h', 9));
    // theDeck.push_back(Card('h', 10));
    // theDeck.push_back(Card('h', 11));
    // theDeck.push_back(Card('h', 12));
    // theDeck.push_back(Card('h', 13));
    
    // theDeck.push_back(Card('s', 1));
    // theDeck.push_back(Card('s', 2));
    // theDeck.push_back(Card('s', 3));
    // theDeck.push_back(Card('s', 4));
    // theDeck.push_back(Card('s', 5));
    // theDeck.push_back(Card('s', 6));
    // theDeck.push_back(Card('s', 7));
    // theDeck.push_back(Card('s', 8));
    // theDeck.push_back(Card('s', 9));
    // theDeck.push_back(Card('s', 10));
    // theDeck.push_back(Card('s', 11));
    // theDeck.push_back(Card('s', 12));
    // theDeck.push_back(Card('s', 13));
    
    //A Different version of the deck below
    
    //THIS IS THE CORRECT VERSION OF THE DECK BELOW
    
    theDeck.push_back(Card('s', 13));
    theDeck.push_back(Card('s', 12));
    theDeck.push_back(Card('s', 11));
    theDeck.push_back(Card('s', 10));
    theDeck.push_back(Card('s', 9));
    theDeck.push_back(Card('s', 8));
    theDeck.push_back(Card('s', 7));
    theDeck.push_back(Card('s', 6));
    theDeck.push_back(Card('s', 5));
    theDeck.push_back(Card('s', 4));
    theDeck.push_back(Card('s', 3));
    theDeck.push_back(Card('s', 2));
    theDeck.push_back(Card('s', 1));
    
    theDeck.push_back(Card('h', 13));
    theDeck.push_back(Card('h', 12));
    theDeck.push_back(Card('h', 11));
    theDeck.push_back(Card('h', 10));
    theDeck.push_back(Card('h', 9));
    theDeck.push_back(Card('h', 8));
    theDeck.push_back(Card('h', 7));
    theDeck.push_back(Card('h', 6));
    theDeck.push_back(Card('h', 5));
    theDeck.push_back(Card('h', 4));
    theDeck.push_back(Card('h', 3));
    theDeck.push_back(Card('h', 2));
    theDeck.push_back(Card('h', 1));
    
    theDeck.push_back(Card('d', 13));
    theDeck.push_back(Card('d', 12));
    theDeck.push_back(Card('d', 11));
    theDeck.push_back(Card('d', 10));
    theDeck.push_back(Card('d', 9));
    theDeck.push_back(Card('d', 8));
    theDeck.push_back(Card('d', 7));
    theDeck.push_back(Card('d', 6));
    theDeck.push_back(Card('d', 5));
    theDeck.push_back(Card('d', 4));
    theDeck.push_back(Card('d', 3));
    theDeck.push_back(Card('d', 2));
    theDeck.push_back(Card('d', 1));
    
    theDeck.push_back(Card('c', 13));
    theDeck.push_back(Card('c', 12));
    theDeck.push_back(Card('c', 11));
    theDeck.push_back(Card('c', 10));
    theDeck.push_back(Card('c', 9));
    theDeck.push_back(Card('c', 8));
    theDeck.push_back(Card('c', 7));
    theDeck.push_back(Card('c', 6));
    theDeck.push_back(Card('c', 5));
    theDeck.push_back(Card('c', 4));
    theDeck.push_back(Card('c', 3));
    theDeck.push_back(Card('c', 2));
    theDeck.push_back(Card('c', 1));
    
}


Card Deck::dealCard()
{
    Card topCard;
    unsigned top = 0;
    
    // dealtCards.push_back(theDeck.at(theDeck.size() - 1))
    // theDeck.pop_back();
    
    //OR
    // top = theDeck.size() - 1;
    // topCard = theDeck.at(0);
    // dealtCards.push_back(topCard);
    // for(unsigned i = 0; i < top; ++i)
    // {
    //     theDeck.at(i) = theDeck.at(i + 1);    
    // }
    // theDeck.pop_back();
    
    
    //OR
    //cout << "From function: " << theDeck.size() << endl;
    
    top = theDeck.size() - 1;
    topCard = theDeck.at(top);
    dealtCards.push_back(topCard);
    theDeck.pop_back();
    
    
    return topCard;
    
}

void Deck::shuffleDeck()
{
    //This resets the deck so that it can be reused for each simulation
    //WRONG, caused the deck to be 0 when standard deck is used
    //theDeck = dealtCards;
    
    unsigned size1 = dealtCards.size();
    
    if(size1 == 0)
    {
       random_shuffle (theDeck.begin(), theDeck.end()); 
    }
    else
    {
        for(unsigned i = 0; i < size1; ++i)
        {
            //cout << "i: " << i << endl;
            theDeck.push_back(dealtCards.at(i));
            
        }
        
        // for(unsigned i = (dealtCards.size() - 1); i > 0; --i)
        // {
        //     cout << "i: " << i << endl;
        //     theDeck.push_back(dealtCards.at(i));
        // }
        dealtCards.clear();
    
        random_shuffle (theDeck.begin(), theDeck.end());
    }
    
    return;
}

unsigned Deck::deckSize() const
{
    unsigned size = 0;
    
    size = theDeck.size();
    
    return size;
}







