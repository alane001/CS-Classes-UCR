#include <iostream>
#include <cmath>

//This file must contain the header as well!!!
#include "Distance.h"

using namespace std;

Distance::Distance()
{
    feet = 0;
    inches = 0.0;
    
    return;
}

Distance::Distance(unsigned ft, double in)
{
    Distance newobj;
    
    newobj.feet = ft;
    newobj.inches = in;
    
    newobj.init();
    
    feet = newobj.feet;
    inches = newobj.inches;
    
    //BELOW is the algorithm for init before I changed it into its own function
    
    // unsigned newFeet = 0;
    // double newInches = 0.0;
    
    // if (in >= 12)
    // {
    //     newInches = in;
        
    //     while(newInches >= 12)
    //     {
    //         newFeet += 1;
    //         newInches = newInches - 12;
            
    //     }
        
    //     //must include the ft value given
    //     feet = newFeet + ft;
    //     inches = newInches;
    // }
    // else
    // {
    //     feet = ft;
    //     inches = in;
    // }
    
    
    return;
}

Distance::Distance(double in)
{
    
    Distance newobj;
    
    newobj.feet = 0;
    newobj.inches = in;
    
    newobj.init();
    
    feet = newobj.feet;
    inches = newobj.inches;
    
    
    
    // unsigned newFeet = 0;
    // double newInches = 0.0;
    
    
    // if (in >= 12)
    // {
    //     newInches = in;
        
    //     while(newInches >= 12)
    //     {
    //         newFeet += 1;
    //         newInches = newInches - 12;
            
    //     }
        
    //     feet = newFeet;
    //     inches = newInches;
    // }
    // else
    // {
    //     inches = in;
    //     feet = 0;
    // }
    
    
    return;
}


unsigned Distance::getFeet() const
{
    return feet;
}

double Distance::getInches() const
{
    return inches;
}

double Distance::distanceInInches() const
{
    unsigned changeFeet = feet;
    double changeInch = inches;
    
    while(changeFeet > 0)
    {
        changeInch = changeInch + 12;
        changeFeet -= 1;
    }
    
    return changeInch;
}

double Distance::distanceInFeet() const
{
    unsigned chFeet = feet;
    double chInch = inches;
    
    chInch = chInch / 12.0;
    
    return chFeet + chInch;
    
}

double Distance::distanceInMeters() const
{
    unsigned newfeet = feet;
    double newinch = inches;
    double meter = 0.0;
    
    while(newfeet > 0)
    {
        newinch = newinch + 12;
        newfeet -= 1;
    }
    
    //Convert the inch measure into meters with this conversion
    meter = newinch * 0.0254;
    
    return meter;
    
}

const Distance Distance::operator+(const Distance &rhs) const
{
    //This is the operator overloading portion
    
    
    //make object
    Distance sum;
    double inch2 = inches + rhs.inches;
    unsigned feet2 = feet + rhs.feet;
    
    
    //fixed problem of converting extra inches to feet first with this if statement
    if (inch2 >= 12)
    {
        while(inch2 >= 12)
        {
            feet2 += 1;
            inch2 = inch2 - 12;
        }
        sum.feet = feet2;
        sum.inches = inch2;
        
    }
    else
    {
        //allows the two objects to be added together
        sum.feet = feet2;
        sum.inches = inch2;
    }
    
    return sum; 
}


const Distance Distance::operator-(const Distance &rhs) const
{
    //This is the operator overloading portion
    
    //make object
    Distance sub;
    
    //had to save as an int to handel the odd negative values that pop out
    //this was causing quite a large problem at the end, kept getting a value of 45364300 or something like that
    //this was caused by sending a negative value to an unsigned private data member variable (feet)
    int ft = 0;
    ft = feet - rhs.feet;
    
    //this takes care of the weird steps with the subtraction
    //the parentheses were causing a problem b/c of the || and && order, this fixed it though
    if(((rhs.inches > inches && feet > rhs.feet) || (inches > rhs.inches && feet < rhs.feet)) && inches != 0.0)
    {
        sub.feet = abs(ft) - 1;
        sub.inches = 12 - abs(inches - rhs.inches);
        
    }
    //This else if below is for the same algorithm above if it was to be included without the || statement above
    
    // else if(inches > rhs.inches && feet < rhs.feet)
    // {
    //     // cout << "feet: " << feet << " rhs.feet: " << rhs.feet << endl;
    //     // cout << "feet - rhs.feet: " << feet - rhs.feet << endl;
    //     // cout << "HEREREREE";
    //     // sub.feet = abs(ft);
    //     // sub.inches = abs(inches - rhs.inches);
    //     sub.feet = abs(ft) - 1;
    //     sub.inches = 12 - abs(inches - rhs.inches);
    // }
    else
    {

        sub.feet = abs(ft);
        sub.inches = abs(inches - rhs.inches);
    }

    return sub; 
}

//NO FRIEND WHEN DEFINING FUNCTION ..... ALSO NO DISTANCE:: because it is not a function, just a friend
ostream& operator<<(ostream &out, const Distance &rhs)
{
    //this was an odd one, use parameter out as cout basically
    //the \" was needed to put a quote character in the string
    return out << rhs.feet << "' " << rhs.inches << "\"";
    
}

void Distance::init()
{
    unsigned newFeet = 0;
    double newInches = 0.0;
    
    if(inches < 0)
    {
        inches = abs(inches);
        
    }
    if (inches >= 12)
    {
        newInches = inches;
        
        while(newInches >= 12)
        {
            newFeet += 1;
            newInches = newInches - 12;
            
        }
        
        //must include the ft value given
        feet = feet + newFeet;
        inches = newInches;
    }
    
    
    return;
    
    
}



