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

//Constant version of at
const int & IntVector::at(unsigned index) const
{
    
    if(index >= sz)
    {
        throw out_of_range("IntVector::at_range_check");
    }
    
    return data[index];
    
}

//Non-constant version | This function does exactly the same thing the accessor (const) version of at does.
int & IntVector::at(unsigned index)
{
    if(index >= sz)
    {
        throw out_of_range("IntVector::at_range_check");
    }
    
    return data[index];
    
}

//Constant version of front
const int & IntVector::front() const
{
    //Added this to both front and back so a segmentation fault does not happen when size of zero is used!
    if(sz == 0)
    {
        throw out_of_range("IntVector::at_range_check");
    }
    
    //just use index of 0 because it just wants the front value aka index 0.
    return data[0];

}

//Non-Constant version of front | This function does exactly the same thing the accessor (const) version of front does.
int & IntVector::front()
{
    if(sz == 0)
    {
        throw out_of_range("IntVector::at_range_check");
    }
    //just use index of 0 because it just wants the front value aka index 0.
    return data[0];
}

//Constant version of back
const int & IntVector::back() const
{
    if(sz == 0)
    {
        throw out_of_range("IntVector::at_range_check");
    }
    //to get the value at the back, just do size - 1 to get correct index.
    return data[sz - 1];
}

//Non-Constant version of back | This function does exactly the same thing the accessor (const) version of back does
int & IntVector::back()
{
    if(sz == 0)
    {
        throw out_of_range("IntVector::at_range_check");
    }
    //to get the value at the back, just do size - 1 to get correct index.
    return data[sz - 1];
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//ABOVE THIS IS FROM THE LAB THAT WAS ALREADY SUCCESSFUL, added non constant versions of back, front and at for this assignment, since they are the same.
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//PRIVATE MEMEBER FUNCTIONS, to test these I just made them public memeber functions for now
void IntVector::expand()
{
    //must make sure that it doesnt do anything if capacity is zero
    
    
    if(cap == 0)
    {
        //must make the capacity at least one
        cap = 1;
    }
    
    
    //Must declare another new pointer with correct new size
    // int* temp = new int[2*sz];
    // //copies data from previous array
    // for(unsigned i = 0; i < sz; ++i)
    // {
    //     temp[i] = data[i];
    // }
    
    // //updates the new size of the array
    // cap = 2*sz;
    
    // data = temp;
    
    // //delete previous pointer
    // delete [] temp;
    
    //Must make pointer to old data so that it is not lost when we redefine a new block of memeory
    int* temp = data;
    
    //increase capacity
    cap = cap * 2;
    
    //this is the new block of memeory
    data = new int[cap];
    
    //copies data from previous array
    for(unsigned i = 0; i < sz; ++i)
    {
        data[i] = temp[i];
    }
    
    //delete previous pointer so memory leak does not occur
    delete [] temp;
    
}


void IntVector::expand(unsigned amount)
{
    //THIS WAS CAUSING LARGE PROBLEMS WITH FUNCTIONS
    //it was causing the cap to +1 over what we needed. So got rid of it
    // if(cap == 0)
    // {
    //     cap = 1;
    // }
    
    
    //Must make pointer to old data so that it is not lost when we redefine a new block of memeory
    int* temp = data;
    
    //increase capacity
    cap = cap + amount;
    
    //this is the new block of memeory
    data = new int[cap];
    
    //copies data from previous array
    for(unsigned i = 0; i < sz; ++i)
    {
        data[i] = temp[i];
    }
    
    //delete previous pointer so memory leak does not occur
    delete [] temp;
    
}

void IntVector::insert(unsigned index, int value)
{
    //This function relies on the private memeber function expand() in case sz = cap. This is because
    //the function must first increase the capicity in order to increase the size by one.
    
    if(index >= sz)
    {
        throw out_of_range("IntVector::insert_range_check");
    }
    
    if(sz == cap)
    {
        expand();
    }
    
    sz += 1;

    for(unsigned i = sz - 1; i > index; --i)
    {
        data[i] = data[i - 1];
    }
    
    data[index] = value;
    
    return;
    
}

void IntVector::erase(unsigned index)
{
    if(index >= sz)
    {
        throw out_of_range("IntVector::erase_range_check");
    }
    
    //this will be very similar to insert but the for loop will go the other way.
    //do i<sz -1 b/c of the data[i+1]
    for(unsigned i = index; i < sz - 1; ++i)
    {
        data[i] = data[i + 1];
        
    }
    
    //decrease the size by one
    sz -= 1;
    
    
}


void IntVector::push_back(int value)
{
    //Only way to fix the code was to declare a new variable to check if cap = 0 and change to =1 if it did
    unsigned check = 0;
    check = cap;
    
    
    //check to make sure capacity is large enough to increase size by one
    if(sz >= cap)
    {
        expand();
    }
    
    data[sz] = value;
    
    if(check == 0)
    {
        cap = 1;
    }
    
    sz += 1;
    
    return;
}

void IntVector::pop_back()
{
    //Only needs to decrease the size of the array by one
    sz -= 1;
    
    return;
}

void IntVector::clear()
{
    //decrease size of array to 0
    if(sz == 0)
    {
        //leave blank b/c already at size 0
    }
    else
    {
        //this causes size to be 0 no matter what sz is
        sz = sz - sz;
    }
    
    return;
}


void IntVector::resize(unsigned size, int value)
{
    //must expand capacity if the new size is larger than capacity
    if(size > cap)
    {
        //checks which version of expand should be used
        //if doubling the capacity is larger, then do that
        
        //THIS HAS TO BE > size not > size - cap! it caused it to go to the if instead of else like it should when size > cap 
        //b/c before if cap = 40 and size = 100 then 2*cap = 80 > size -cap = 60. This called expand() making cap = 80, instead of the needed 100
        //This same problem happened with the function below: reserve
        if(2 * cap > size)// - cap)
        {
            expand();
        }
        else
        {
            expand(size - cap);
        }
        
    }
    
    //make sure to do case where size = sz, which will be fine for this first statement
    if(size <= sz)
    {
        sz = size;
    }
    //this will take care of the case when size > sz
    else
    {
        //can use a for loop to add the new values to the end of the array to fill the rest of the new size
        //had it as i = sz - 1, but that changed the last intial defined value so changed to i = sz
        for(unsigned i = sz; i < size; ++i)
        {
            //HAD TO ADD THIS IF STATEMENT, without it it kept sending an error
            //*** Error in `./a.out': free(): invalid next size (fast): which caused an abort
            //tried to access an invalid memory location
            if(i == size)
            {
                break;
            }
            else
            {
                data[i] = value;
            }
        }
        
        
        
        //update sz to be the correct size
        sz = size;
    }
    
    return;
}

//NEVER reduce the size of the vector
void IntVector::reserve(unsigned n)
{
    //only do something if cap is less than n, because n is a minimum, so if cap is larger or equal
    //to n then we don't need to do anything
    if(cap < n)
    {
        //checks which version of expand should be used
        //if doubling the capacity is larger, then do that
        
        //DONT do > n - cap! do > n because that is the only way to get the else statement to work properly!
        if(2 * cap > n)// - cap)
        {
            expand();
        }
        else
        {
            expand(n - cap);
        }
        
    }
    
    return;
    
}


void IntVector::assign(unsigned n, int value)
{
    if(n > cap)
    {
        //checks which version of expand should be used
        //if doubling the capacity is larger, then do that
        
        //DONT do > n - cap! do > n because that is the only way to get the else statement to work properly!
        if(2 * cap > n)// - cap)
        {
            expand();
        }
        else
        {
            expand(n - cap);
        }    
        
    }
    
    //n is the new size
    sz = n;
    
    //loop to fill in vector with new chosen values
    for(unsigned i = 0; i < sz; ++i)
    {
        data[i] = value;
    }
    
    return;
}












