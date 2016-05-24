#include <iostream>
#include "Card.h"

using namespace std;

Card::Card()
{
    suit = 'c';
    rank = 2;
    
    return;
}

Card::Card(char s, int r)
{
    if(s == 'c' || s == 'd' || s == 'h' || s == 's' || s == 'C' || s == 'D' || s == 'H' || s =='S')
    {
        suit = s;
    }
    else
    {
        suit = 'c';
    }
    
    if(r > 0 && r < 14)
    {
        rank = r;
    }
    else
    {
        rank = 2;
    }
    
    return;
}

char Card::getSuit() const
{
    return tolower(suit);
}

int Card::getRank() const
{
    return rank;
}

//ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
ostream& operator<<(ostream &out, const Card &rhs)
{
    string outSuit, outRank;
    
    if(rhs.getSuit() == 'c' || rhs.getSuit() == 'C')
    {
        outSuit = "Clubs";
    }
    else if(rhs.getSuit() == 'd' || rhs.getSuit() == 'D')
    {
        outSuit = "Diamonds";
    }
    else if(rhs.getSuit() == 'h' || rhs.getSuit() == 'H')
    {
        outSuit = "Hearts";
    }
    else if(rhs.getSuit() == 's' || rhs.getSuit() == 'S')
    {
        outSuit = "Spades";
    }
    if(rhs.getRank() == 1)
    {
        outRank = "Ace";
    }
    else if(rhs.getRank() == 2)
    {
        outRank = "2";
    }
    else if(rhs.getRank() == 3)
    {
        outRank = "3";
    }
    else if(rhs.getRank() == 4)
    {
        outRank = "4";
    }
    else if(rhs.getRank() == 5)
    {
        outRank = "5";
    }
    else if(rhs.getRank() == 6)
    {
        outRank = "6";
    }
    else if(rhs.getRank() == 7)
    {
        outRank = "7";
    }
    else if(rhs.getRank() == 8)
    {
        outRank = "8";
    }
    else if(rhs.getRank() == 9)
    {
        outRank = "9";
    }
    else if(rhs.getRank() == 10)
    {
        outRank = "10";
    }
    else if(rhs.getRank() == 11)
    {
        outRank = "Jack";
    }
    else if(rhs.getRank() == 12)
    {
        outRank = "Queen";
    }
    else if(rhs.getRank() == 13)
    {
        outRank = "King";
    }
    
    return out << outRank << " of " << outSuit;
}





