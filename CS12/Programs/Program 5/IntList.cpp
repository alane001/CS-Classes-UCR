#include <iostream>
#include <algorithm>
#include "IntList.h"

using namespace std;

IntList::IntList()
{
    //just want an empty list, so just set the pointer to zero
    head = 0;
    tail = 0;
    
    return;
}

IntList::~IntList()
{
    //empty list
    if(head == 0)
    { 
        //do nothing
    }
    else if(head == tail)
    {
        //just delete first node
        pop_front();
        //Or could have done delete head;
    }
    //Need to delete all of the nodes, not just head and tail
    else
    {
        IntNode* temp = 0;
        temp = head;
        while(head != 0)
        {
            temp = head;
            delete head;
            head = temp -> next;
        }
    }
}

void IntList::push_front(int value)
{
    // IntNode* newNode = 0;
    
    // newNode = new IntNode(value);
    
    if(empty())//tail == 0 && head == 0)
    {
        //head = new IntNode(value);
        tail = new IntNode(value);
        head = tail;
        //cout << "Original: " << tail -> data << "   address: " << tail -> next << endl; 
    }
    else
    {
        IntNode* temp = 0;
        temp = new IntNode(value);
        
        temp -> next = head;
        
        head = temp;
        
    }
    
    return;
}

void IntList::pop_front()
{
    //repetative code doing tail == 0 and head == 0 if empty function already does that
    if(empty())//tail == 0 && head == 0)
    {
        //Do nothing is the list is empty
    }
    else
    {
        IntNode* temp = 0;
        
        //so we don't lose access to the rest of the list
        temp = head;
        
        //this is so that head is now pointing to the next IntNode
        head = temp -> next;
        
        //dont cause memory leaks
        delete temp;
        
        
        //This changes it so that the pointer points to the next position instead of the original
        //Had to change to tail because changed to tail in display
        //head = head -> next;
        //This next if must happen or will cause the empty() function to read false when you pop_front the very last node
        if(head == 0)
        {
            //this makes sure that head = 0 and tail = 0 so that empty() will read true
            tail = 0;
        }
        
    }
    
    return;
}

bool IntList::empty() const
{
    //if the list is empty then the pointer will be zero, this will return true if head = 0
    //Had to change b/c it was evaluating to true even when a value was in it. must add && tail ==0
    return head == 0 && tail == 0;
}


void IntList::display() const
{
    //MUST USE THE -> operator!

    //cout << tail -> data;
    //cout << head -> data << " " << tail -> data << " ";
    //Must set current to tail because that will be the one with the correct -> next value to 0
    
    //This works for both = head and = tail
    //this is b/c it is const, so we can not change head and do head = head -> next;
    IntNode* current = head;
    while(current != 0)
    {
        if(current -> next == 0)
        {
           
            cout << current -> data;
            
        }
        else
        {
            cout << current -> data << " ";
        }
        //must update so that it will get the next value
        current = current -> next;
        
    }
    
        
}

//EVERYTHING NEW BELOW-----------------------------------------------

IntList::IntList(const IntList &cpy)
{
    head = tail = 0;
    for(IntNode* temp = cpy.head; temp != 0; temp = temp -> next)
    {
        push_back(temp -> data);
    }
    
    return;
}

IntList & IntList::operator=(const IntList &rhs)
{
    if(rhs.empty())
    {
        head = 0;
        tail = 0;
    }
    else
    {
        //We must loop though to see if it is the same list being copied. aka list1 = list1
        //if this is the case we need to NOT clear it and do nothing
        bool sameList = false;
        //must make separate temp pointers to that the head and rhs.head dont change for later
        IntNode* temp2 = head;
        IntNode* temp3 = rhs.head;
        while(temp2 != 0)
        {
            if(temp2 -> data == temp3 -> data)
            {
                //will keep it saying true if everything is the same in the list
                sameList = true;
            }
            
            temp2 = temp2 -> next;
        }
        
        //must clear the list when assigning lists that are not empty, if not then one list will push back on the other! bad!
        if(sameList == false)
        {
            //if not the same list and has more than 1 node then need to clear first
            clear();
        
            for(IntNode* temp = rhs.head; temp != 0; temp = temp -> next)
            {
                //listCopy.push_back(temp -> data);
                push_back(temp -> data);
       
            }
        }
        
    }


    
    return *this;
}

void IntList::clear()
{
    //Must handle the case where it is an empty list, so do nothing
    if(head == 0 && tail == 0)
    {
        //Do nothing
        
    }
    else
    {
        delete head;
    }
    //This sets the appropriate values of head and tail for an empty list
    head = 0;
    tail = 0;
    
    
}


void IntList::push_back(int value)
{
    if(empty())
    {
        head = new IntNode(value);
        tail = head;
    }
    else
    {
        IntNode* temp = 0;
        temp = new IntNode(value);
        
        tail -> next = temp;
        
        tail = temp;
        
        
    }
    
    return;
}


void IntList::selection_sort()
{
    IntNode* swap = 0;
    
    //need nested for loop in order to get it to go through enough times
    //the second loop needs to stop 1 short to allow for current->next -> data
    for (IntNode* current = head; current != 0; current = current -> next){
        for (IntNode* current = head; current -> next != 0; current = current -> next){
            if (current -> data > (current -> next) -> data){
                //need a new node to hold the data, tried swap -> data = current -> data but that caused swap to be changed later in the code
                swap = new IntNode(current -> data);
                // cout << endl << "swap data: " << swap -> data << endl;
                // cout << endl << "current next data: " << (current -> next) -> data << endl;
                //swap -> data = current -> data;
                current -> data = (current -> next) -> data;
                // cout << endl << "swap data: " << swap -> data << endl;
                // cout << "1: " << current -> data << endl;
                (current -> next) -> data = swap -> data;
                // cout << "2: " << (current -> next) -> data << endl;
                
                //Must clean up!
                delete swap;
            }
        }
    }
    return;
}


ostream& operator<<(ostream &out, const IntList &rhs)
{
    IntNode* current = rhs.head;
    while(current != 0)
    {
        if(current -> next == 0)
        {
            out << current -> data;
            
        }
        else
        {
            out << current -> data << " ";
        }
        //must update so that it will get the next value
        current = current -> next;
        
    }
    
    return out;
    
}

void IntList::insert_ordered(int value)
{
    //use similar code that was used for sorting
    IntNode* newNode = new IntNode(value);
    // cout <<"1st time: " << newNode -> data << endl;
    //MUST HANDLE the case where the list is empty!
    if(empty())
    {
        push_back(newNode -> data);
    }
    //kept causing problem when this below was an if statement instead of else if
    //both if empty and this below would execute, so need an else if statement instead
    //ALSO must handle the case where there is only one value!
    else if(head == tail && tail != 0 && head != 0)
    {
        //this is if the new data is larger, so it should go on the end!
        if(newNode -> data > head -> data)
        {
            head -> next = newNode;
        }
        //this is if newdata is less than prev, so needs to go on the front
        else
        {
            //cout << endl << "YES" << newNode -> data << endl << endl;
            push_front(newNode -> data);
        }
    }
    else
    {
        //This handels the case of determining where to put the new value in the list if it is less and larger than prev values
        for (IntNode* current = head; current -> next != 0; current = current -> next){
            if ((newNode -> data < (current -> next) -> data) && (newNode -> data > current -> data))
            {
                //Problem came from putting this first statement below the current -> next statement
                //Also was trying newNode -> next = current -> next -> next which was always zero! BAD!
                //since this was changing current, needed to supply the next address first to newNode THEN change current's address
                newNode -> next = current -> next;
                current -> next = newNode;
                //Must have break here too.
                break;
                
            }
            //Need to handle the case where the inserted value is the SAME value as one of the others BUT
            //DO NOT PUT it in this loop, the previous things alter it
            if(newNode -> data == current -> data)
            {
                newNode -> next = current -> next;
                current -> next = newNode;
                //With out this break it caused the code to not work properly! MUST HAVE HERE!
                break;
            }
            //This handles the case where if the ending value is equal to newNodes value and is at the END of the list!
            if(newNode -> data == tail -> data)
            {
                push_back(newNode -> data);
                break;
            }
            
        }
        
        //Need this to handel the case where the new value is larger than all the other previous values
        if(newNode -> data > tail -> data)
        {
            push_back(newNode -> data);
        }
        //Need this to handle the case where the new value is less than all the other previous values
        if(newNode -> data < head -> data)
        {
            push_front(newNode -> data);
        }
    }
    return;
}

void IntList::remove_duplicates()
{
    //IntNode* p = head;
    IntNode* p = 0;
    IntNode* n = 0;
    IntNode* before = 0;
    
    if(head == 0)
    {
        //do nothing
    }
    else if (head == tail)
    {
        //do nothing again because only one value
    }
    else
    {
        //THIS IS THE UNTOUCHED ONE ------------------
        // p = head;
        // while(p != tail)
        // {
        //     n = p -> next;
        //     before = p;
        //     while(n != 0)
        //     {
        //         if(p -> data == n -> data)
        //         {
        //             before -> next = n -> next;
        //             delete n;
                    
        //         }
        //         before = n;
        //         n = n -> next;
        //     }
        //     p = p -> next;
        
        // }
        //---------------------------------------
        p = head;
        while(p != tail)
        {
            n = p -> next;
            before = p;
            while(n != 0)
            {
                // cout << "p data: " << p -> data << endl;
                // cout << "before: " << before -> data << endl;
                // cout << "n: " << n-> data << endl;
                // cout << "n next: " << n-> next << endl << endl;
                if(p -> data == n -> data)
                {
                    // //cout << "GOT HERE" << endl;
                    if(n -> next == 0)
                    {
                        // delete n;
                        // n = 0;
                        
                    }
                    else
                    {
                        before -> next = n -> next;
                        delete n;
                        n = before -> next;
                    }
                }
                else
                {
                    before = n;
                    n = n -> next;
                }
            }
            p = p -> next;
        
        }
        
        
    }
}



