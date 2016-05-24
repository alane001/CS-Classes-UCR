#include <iostream>
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
    
    delete head;
}

void IntList::push_front(int value)
{
    // IntNode* newNode = 0;
    
    // newNode = new IntNode(value);
    
    if(empty())//tail == 0 && head == 0)
    {
        //tail = newNode;
        tail = new IntNode(value);
        //cout << "Original: " << tail -> data << "   address: " << tail -> next << endl; 
    }
    else
    {
        IntNode* prevNode = 0;
        prevNode = tail;
        // cout << "tail: " << tail ->data << endl;
        // cout << "tail address: " << tail -> next << endl;
        
        head = new IntNode(value);
        
        head -> next = prevNode;
        // cout << "tail: " << tail ->data << endl;
        // cout << "tail address: " << tail -> next << endl;
        
        tail = head;
        //prevNode = tail;
        // cout << "head: " << head ->data << endl;
        // cout << "head address: " << head -> next << endl;
        
        
        //THIS IS WHAT WAS CAUSING ALL THE ISSUES! DONT delete the prev node pointer!
        //delete prevNode;
        
    }
    
    return;
}

void IntList::pop_front()
{
    if(empty())//tail == 0 && head == 0)
    {
        //Do nothing is the list is empty
    }
    else
    {
        //This changes it so that the pointer points to the next position instead of the original
        head = head -> next;
        if(head == 0)
        {
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