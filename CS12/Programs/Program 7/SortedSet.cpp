#include <iostream>
#include "IntList.h"
#include "SortedSet.h"

using namespace std;

SortedSet::SortedSet() : IntList()
{
    //empty set
    //before had head = tail = 0 BUT not necessary!
    // the : IntList() calls the constructor from intlist that DOES THE SAME THING!
    
    return;
}

SortedSet::SortedSet(const SortedSet &cpy) : IntList(cpy)
{
   //same idea as the one above! already does the same thing!
    
    return;
}


SortedSet::SortedSet(const IntList &cpy) : IntList(cpy)
{
    //DONT set head = tail = 0 here ALSO dont use temp = cpy.head! caused error
    //to fix just allow temp to be head, not cpy.head! IGNORE THIS AS WELL
    //the copy constructor IntList(cpy) does all of this already!
   
    
    //Since IntLists do not have to be sorted AND allows duplicates we must sort and remove duplicates
    remove_duplicates();
    selection_sort();
    
    return;
}

SortedSet::~SortedSet()
{
    //This destructor does not need to do anything because everything relies on head and tail
    //with no other new memory being created. All heads and tail are deleted from memory using the IntList destructor!
    
    return;
}


//ACCESSORS---------------------------------------------------------------------------------------------------------------------------------------

//this was int data, but changed to indata to prevent confusion when using head -> data
bool SortedSet::in(int indata)
{
    bool answer = false;
    
    //this was causing problems, had to make sure it was not changing HEAD so make new variable
    IntNode* current = head;
    
    while(current != 0)
    {
        if(current -> data == indata)
        {
            answer = true;
        }
        current = current -> next;
    }
    
    return answer;
    
}

const SortedSet SortedSet::operator|(const SortedSet rhs) const
{
    //since it is const const const then DONT DO *this, define a new set!
    SortedSet setreturn;
    
    //make pointer to both heads of each list
    IntNode* current = head;
    IntNode* current2 = rhs.head;
    
    //now do loops to fill in using push_back (or push_front), can do for both because of the push_back using add function that will not add duplicates
    //only do loop if the list is not empty
    if(empty())
    {
        //do nothing
    }
    else
    {
        while(current != 0)
        {
            setreturn.push_back(current -> data);
            //push_back(current -> data);
            current = current -> next;
        }
         
    }
    if(rhs.empty())
    {
        //do nothing
    }
    else
    {
        while(current2 != 0)
        {
            setreturn.push_back(current2 -> data);
            //push_back(current2 -> data);
            current2 = current2 -> next;
        }
    }
    
    return setreturn;
    
}


const SortedSet SortedSet::operator&(const SortedSet rhs) const
{
    //this is the intersection of the two sets, meaning only make a new set that is composed of the elements that are in BOTH passed in sets!
    SortedSet setreturn;
    
    
    IntNode* current2 = rhs.head;
    IntNode* current = head;
    
    if(empty() || rhs.empty())
    {
        //do nothing! because if either is empty then they will never have one in common with another
    }
    else
    {
        //this will do a loop to compare the data between the two sets
        while(current != 0)
        {
            //cout << "current data: " << current -> data << endl;
            //need to reset current2 everytime or else it only goes through once! e.g.: it only worked when the duplicate was the first value in the implicit set
            current2 = rhs.head;
            while(current2 != 0)
            {
                //cout << "current2 data: " << current2 -> data << endl;
                
                //once one value is in common between the two then it adds it to the set to return
                if(current -> data == current2 -> data)
                {
                    setreturn.push_back(current -> data);
                }
                
                current2 = current2 -> next;
            }
            current = current -> next;
        }
    }
    
    return setreturn;
}


//MUTATORS --------------------------------------------------------------------------------------------------------------------------------------------
        
void SortedSet::add(int newdata)
{
    IntNode* temp = new IntNode(newdata);
    
    IntNode* current = head;
    IntNode* previous = 0;
    
    //checks if the set is empty
    if(empty())
    {
        //if list is empty then just make head and tail this value
        head = temp;
        tail = head;
    }
    else
    {
        if(in(newdata))
        {
            //DO NOTHING
        }
        else
        {   //this is the case where the list is only one value
            if(head == tail)
            {
                if(head -> data < newdata)
                {
                    tail -> next = temp;
                    tail = temp;
                }
                else
                {
                    previous = head;
                    head = temp;
                    head -> next = previous;
                }
            }
            else
            {
                //only go through ONCE!!!! MUST BREAK IN EVERY CASE OR CAUSES PROBLEMS
                while(current != 0)
                {
                    //this breaks the loop if it goes all the way through and no value has been found larger and smaller, aka it pushes the value to the end
                    if(current -> next == 0)
                    {
                        current -> next = temp;
                        tail = temp;
                        break;
                    }
                    //this handles the case when the newdata is smaller than the rest
                    if(current -> data > newdata)
                    {
                        previous = head;
                        head = temp;
                        head -> next = previous;
                        break;
                    }
                    //this handles the case of putting the value in the middle
                    if(current -> data < newdata && current -> next -> data > newdata)
                    {
                        previous = current -> next;
                        current -> next = temp;
                        temp -> next = previous;
                        break;
                    }
                    current = current -> next;
                }
            }
        }
    }
    
    return;
}

void SortedSet::push_front(int data)
{
    //dont add in if that value of data is already present in the list!
    // if(in(data))
    // {
    //     //do nothing if already in the list
    // }
    // else
    // {
    //    add(data);
    //}
    
    //add already checks this fact, so just need to call add!
    add(data);
    
    return;
}

void SortedSet::push_back(int data)
{
    //same thing as push_front, just call add
    
    add(data);
    
    return;
}

void SortedSet::insert_ordered(int data)
{
    //same as for push_front and push_back
    
    add(data);
    
    return;
    
}

SortedSet& SortedSet::operator|=(const SortedSet &rhs)
{
    //uses a simliar thing as operator| but is like A |= B -> A = A | B;
    
    //make pointer to both heads of each list
    IntNode* current = head;
    IntNode* current2 = rhs.head;
    
    //now do loops to fill in using push_back (or push_front), can do for both because of the push_back using add function that will not add duplicates
    //only do loop if the list is not empty
    if(empty())
    {
        //dont do anything
    }
    else
    {
        while(current != 0)
        {
            //setreturn.push_back(current -> data);
            push_back(current -> data);
            current = current -> next;
        }
    }
    if(rhs.empty())
    {
        //dont add anything
    }
    else
    {
        while(current2 != 0)
        {
            //setreturn.push_back(current2 -> data);
            push_back(current2 -> data);
            current2 = current2 -> next;
        }
    }
    
    return *this;
    
}

SortedSet& SortedSet::operator&=(const SortedSet &rhs)
{
    //very similar to accessor version, just a little more work
    
    //need a temp set to transfer implicit set data on it, so we can clear the implicit set before adding on the intersection values
    //is required when using *this, because without doing it, the implicit set would just be outputted again with nothing changed
    SortedSet tempset;
    
    //pointer to explicit set
    IntNode* current2 = rhs.head;
    
    //pointer to implicit set
    IntNode* current = head;
    
    //fill tempset with values in implicit set
    while(current != 0)
    {
        //cout << current -> data << endl;
        tempset.push_back(current -> data);
        current = current -> next;
    }
    
    //this was causing a problem, without the if statement the self assign would cause the list to be cleared when it shouldn't be
    //when self assigning then everything will match so full set should still be there, if self assigning then rhs.head == head
    if(rhs.head != head)
    {
        clear();
    }
    
    //now tempset is a copy of the implicit set
    //now can clear implicit set, so *this is now empty
    //clear();
    
    //make new pointer to head of tempset
    IntNode* current3 = tempset.head;
    
    if(tempset.empty() || rhs.empty())
    {
        //do nothing! because if either is empty then they will never have one in common with another
    }
    else
    {
        //this will do a loop to compare the data between the two sets (explicit and tempset)
        while(current3 != 0)
        {
            //cout << "current3 data: " << current3 -> data << endl;
            //need to reset current2 everytime or else it only goes through once! e.g.: it only worked when the duplicate was the first value in the implicit set
            current2 = rhs.head;
            while(current2 != 0)
            {
                //cout << "current2 data: " << current2 -> data << endl;
                
                //once one value is in common between the two then it adds it to the set to return
                if(current3 -> data == current2 -> data)
                {
                    //instead of setreturn pushback, just do pushback
                    //setreturn.push_back(current -> data);
                    
                    //this pushes the duplicate data of tempset and explicit set onto the implicit set (*this)
                    push_back(current3 -> data);
                }
                
                current2 = current2 -> next;
            }
            current3 = current3 -> next;
        }
    }
    
    //now this returns the implicit set, which is now full of only duplicate values
    return *this;
    
}


