#include <iostream>
#include "IntList.h"

IntList::IntList()
{
    //Initializes to an empty list
    head = 0;
    
    return;
}


void IntList::push_front(int value)
{
    if(head == 0)//tail == 0 && head == 0)
    {
        //head = new IntNode(value);
        head = new IntNode(value);
        //tail = new IntNode(value);
        //head = tail;
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


ostream & operator<<(ostream & out, const IntList & list)
{
    IntNode* temp = list.head;
    
    out << temp;
    
    return out;
}

//Helper function
ostream & operator<<(ostream & out2, IntNode * node)
{
    //Checks to make sure that list is not empty, if not empty then it goes through "loop"
    if(node != 0){
        //this makes sure no space at the end
        if(node -> next == 0)
        {
            out2 << node -> data;
        }
        //this outputs the space, and node -> next is a node! so it recalls the same function again!
        else
        {
            //the node next is the important part!
            out2 << node -> data << " " << node->next;
            
        }
    
    }
    return out2;
    
}



bool IntList::exists(int value) const
{
    // bool answer = false;
    
    // if(head != 0)
    // {
    //     answer = exists(head, value);
    // }
    // else
    // {
    //     answer = false;    
    // }
    
    // return answer;
    return exists(head, value);
}

//helper function
bool IntList::exists(IntNode * node, int value2) const
{
    bool answer2 = false;
    //stop if empty list
    // if(node != 0)
    // {
    //     if(node -> data == value2)
    //     {
    //         //answer2 = true;
    //         return true;
            
    //     }
    //     // if(answer2 != true)
    //     // {
    //     exists(node -> next, value2); 
    //     //}
    // }
    // else
    // {
    //     return false;
    // }
    
    if(node != 0)
    {
        if(node -> data == value2)
        {
            answer2 = true;
            //return true;
            
        }
        if(answer2 != true)
        {
            //had to put return here!
            return exists(node -> next, value2); 
        }
    }
    else
    {
        answer2 = false;
        //return false;
    }
    return answer2;
}





