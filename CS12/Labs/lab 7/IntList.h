#ifndef INTLIST_H
#define INTLIST_H


struct IntNode {
    int data;
    IntNode *next;
    IntNode(int data) : data(data), next(0) {}
};


class IntList
{
    private:
        IntNode* head;
        IntNode* tail;
        
    public:
        //Initializes an empty list.
        IntList();
        
        // Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
        ~IntList();
        
        //Displays to a single line all of the int values stored in the list, 
        //each separated by a space. This function does NOT output a newline or space at the end.
        void display() const;
        
        // Inserts a data value (within a new node) at the front end of the list.
        void push_front(int value);
        
        // //Removes the value (actually removes the node that contains the value) at the 
        // //front end of the list. Does nothing if the list is already empty.
        void pop_front();
        
        //Returns true if the list does not store any data values (does not have any nodes), otherwise returns false.
        bool empty() const;
    
};


#endif