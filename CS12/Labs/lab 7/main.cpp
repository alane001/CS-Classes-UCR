//----------------------------------------------------------------------------------------------
//DESCRIPTION

//You will begin the implementation of the singly-linked list.

//IntList Lab Specifications

//You are required to come up with a single header file (IntList.h) that declares and implements the IntNode class (just copy
//it exactly as it is below) as well as declares the IntList Class interface only. You are also required to come up with a
//separate implementation file (IntList.cpp) that implements the member functions of the IntList class. While developing your
//IntList class you must write your own test harness (within a file named main.cpp). Never implement more than 1 or 2 member
//functions without fulling testing them with your own test harness.

//IntNode struct

//I am providing the IntNode struct you are required to use. Place this class definition within the IntList.h file exactly as is.
//Make sure you place it above the definition of your IntList class. Notice that you will not code an implementation file for
//the IntNode class. The IntNode constructor has been defined "inline" (i.e. within the class declaration). Do not write any
//other functions for the IntNode class. Use as is.

//struct IntNode {
//    int data;
//    IntNode *next;
//   IntNode(int data) : data(data), next(0) {}
//};

//----------------------------------------------------------------------------------------------


#include <iostream>

using namespace std;

#include "IntList.h"


int main() {

  //tests constructor, destructor, push_front, pop_front, display

//MY TEST BELOW ----------------------------------
    // IntList list1;

    // cout << "Is empty? 1 if true 0 if false: " << list1.empty() << endl;

    // list1.push_front(10);

    // cout << "Is empty? 1 if true 0 if false: " << list1.empty() << endl;
    // list1.push_front(20);
    // list1.push_front(30);
    // list1.display();
//-------------------------------------------------------


  {
      cout << "\nlist1 constructor called";
      IntList list1;
      cout << "\npushfront 10";
      list1.push_front(10);
      cout << "\npushfront 20";
      list1.push_front(20);
      cout << "\npushfront 30";
      list1.push_front(30);
      cout << "\nlist1: ";
      list1.display();
      cout << "\npop";
      list1.pop_front();
      cout << "\nlist1: ";
      list1.display();
      cout << "\npop";
      list1.pop_front();
      cout << "\nlist1: ";
      list1.display();
      cout << "\npop";
      list1.pop_front();
      cout << "\nlist1: ";
      list1.display();
      cout << endl;
  }
  cout << "list1 destructor called" << endl;

   return 0;
}
