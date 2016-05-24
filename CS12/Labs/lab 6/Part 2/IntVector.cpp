#include <iostream>
#include "IntVector.h"
#include <stdexcept>

using namespace std;

IntVector::IntVector():sz(0), cap(0), data(0)
{
    return;
}

//IMPORTANT: Only need to have int value = 0 in decleration in .h file! NOT HERE!!!!!!!
IntVector::IntVector (unsigned size, int value)
{
    sz = size;
    cap = size;
    data = 0;
    
    //dynamic allocate an array of same size
    data = new int[size];
    
    //Initialize all elements to value
    for(unsigned i = 0; i < size; ++i)
    {
        data[i] = value;
    }
    
    return;
}

IntVector::~IntVector()
{
    if(data != 0)
    {
        //cout << "DESTRUCTOR CALLED!";
        //the bracets delete the entire array
        delete [] data;
    }
    
    return;
}

unsigned IntVector::size() const
{
    return sz;
}

unsigned IntVector::capacity() const
{
    return cap;
}

bool IntVector::empty() const
{
    bool answer = false;
    
    if(sz == 0)
    {
        //it is empty if sz is size zero
        answer = true;
    }
    
    return answer;
    
}

const int & IntVector::at(unsigned index) const
{
    
    if(index >= sz)
    {
        throw out_of_range("IntVector::at_range_check");
    }
    
    return data[index];
    
}

const int & IntVector::front() const
{
    //just use index of 0 because it just wants the front value aka index 0.
    return data[0];

}

const int & IntVector::back() const
{
    //to get the value at the back, just do size - 1 to get correct index.
    return data[sz - 1];
}





