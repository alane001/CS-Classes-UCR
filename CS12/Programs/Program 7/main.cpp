//----------------------------------------------------------------------------------------------
//DESCRIPTION
//see header file for member function explanations


//Implement a SortedSet class that is a specialization of the IntList class you
//implemented for PROGRAM 5.


//IntList class

//The only change to the IntList class from PROGRAM 5 is to change the access privileges of
//the data fields from private to protected. You may not change or add anything else to the
//IntList class. If you did not get 100% on the IntList class, you should fix this class first
//so that you do get 100% on it before going on to the SortedSet class.


//SortedSet class

//A set is a collection of unique values. That is, a list that does not have any duplicates.
//In our case, we will also keep the list sorted (ascending order), so our type will be SortedSet.
//Our SortedSet is a specialization of the IntList you designed for PROGRAM 5, so your SortedSet
//class will inherit from the IntList class.

//You are required to come up with a separate header file (.h) and separate implementation file
//(.cpp) for the SortedSet class. You should also come up with your own test harness to test just
//the functions you are currently working on while you are developing the SortedSet class.
//Never implement more than 1 or 2 member functions without fulling testing them with your own
//test harness. You can comment out tests once you have verified your function(s) work, but do not
//delete these tests.


//----------------------------------------------------------------------------------------------


#include<iostream>
#include "IntList.h"
#include "SortedSet.h"

using namespace std;

int main()
{
    //MY TESTS -----------------------------------------------------------------------------------------

    //this first test is to make sure my previous problem was still fixed when I transfer things over from assignment5

    // IntList list1;

    // list1.push_back(10);
    // list1.push_back(10);
    // list1.push_back(30);
    // list1.push_back(20);
    // list1.push_back(10);
    // cout << "List1: " << list1 << endl;

    // list1.remove_duplicates();

    // cout << "List1 after remove: " << list1 << endl;

    // list1.push_back(99);
    // list1.push_back(100);

    // cout << list1 << endl;



    // TEST 1: Constructor
    //SortedSet set1;
    //worked, no error



    //TEST 2: ADD mutator test!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ (uses the in function as well)
    //SortedSet set1;

    //test with just one value
    //set1.add(120); //works

    //test with two values with the last one being larger
    //set1.add(10);
    //set1.add(15); //works

    //test with two values with the last one being smaller
    //set1.add(10);
    //set1.add(5); //works

    //now test with more than two values with already ascending
    // set1.add(5);
    // set1.add(15);
    // set1.add(30);
    // set1.add(40);//this works

    //now test when values are NOT ascending and adding to the middle and end!
    // set1.add(5);
    // set1.add(15);
    // set1.add(10);
    // set1.add(13);
    // set1.add(20);//works

    //now test when value are NOT ascending and adding to the begining
    // set1.add(5);
    // set1.add(15);
    // set1.add(10);
    // set1.add(13);
    // set1.add(20);
    // set1.add(4); // this is the part that tests it. works now
    // set1.add(1);

    // set1.display();
    // cout << endl;

    //now lets make a loop so we can input values and see if we can get it to break
    // int i = 1;
    // int input = 0;
    // while(i != 0)
    // {
    //     cout << "Enter a value to be put into the set: ";
    //     cin >> input;
    //     set1.add(input);

    //     cout << endl << "Set1: ";
    //     set1.display();
    //     cout << endl;

    //     cout << "Enter 0 to stop: ";
    //     cin >> i;
    //     cout << endl;
    // }

    //everything seems to be working fine with this function!++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


    //TEST 3: in function------------------------------------------------------------------------------------------------
    //already tested inside of the add function but lets put it through the test here
    //use a loop, it's faster to begin
    //SortedSet set1;

    // int i = 1;
    // int input = 0;
    // while(i != 0)
    // {
    //     cout << "Enter a value to be put into the set: ";
    //     cin >> input;
    //     set1.add(input);

    //     cout << endl << "Set1: ";
    //     set1.display();
    //     cout << endl;

    //     cout << "Enter 0 to stop: ";
    //     cin >> i;
    //     cout << endl;
    // }
    //it seems to be working for the loop, only adds a value when it is not already in the set.

    //now test it with the function itself

    // set1.add(15);
    // set1.add(20);
    // set1.add(4);


    // cout << "set1: ";
    // set1.display();

    // //this will test the value at front middle end.
    // cout << endl << "Is 15 in the list? (1 is true): " << set1.in(15) << endl;
    // cout << "Is 4 in the list? (1 is true): " << set1.in(4) << endl;
    // cout << "Is 20 in the list? (1 is true): " << set1.in(20) << endl;
    // //all worked properly, so now try ones that aren't in the list

    // cout << "Is 100 in the list? (1 is true): " << set1.in(100) << endl;
    // cout << "Is 21 in the list? (1 is true): " << set1.in(21) << endl;
    // //then retry value in list to make sure nothing changed
    // cout << "Is 15 in the list? (1 is true): " << set1.in(15) << endl;

    //all works----------------------------------------------------------------------------------------------------------

    //TEST 4 push front, push back, insert ordered functions--------------------------------------------------------------------------------
    //SortedSet set1;

    // set1.push_front(5);
    // set1.push_front(10);
    // set1.push_front(5);

    // set1.display();
    //this displayed 5 10, which it should (no duplicates). This shows the previous IntList function was overridden or else it would have been 10 5

    // set1.push_back(5);
    // set1.push_back(3);
    // set1.push_back(5);

    // set1.display();
    //this showed 3 5, which means it was overridden just like for push front

    // set1.insert_ordered(5);
    // set1.insert_ordered(10);
    // set1.insert_ordered(15);
    // set1.insert_ordered(20);
    // set1.insert_ordered(15);
    // set1.insert_ordered(8);
    // set1.display();

    //this worked as well, didn't insert the final 15

    //all worked from what I can tell -------------------------------------------------------------------------------------

    //TEST 5: test operator|
    //SortedSet set1, set2, set3;

    //test with a normal ascending set, also testing that it goes in the correct place
    // set1.add(10);
    // set1.add(20);
    // set1.add(30);
    // cout << "Set1: " << set1 << endl;

    // set2.add(15);
    // set2.add(25);
    // set2.add(35);
    // cout << "Set2: " << set2 << endl;

    // set3 = set1 | set2;

    // cout << "Set3: " << set3 << endl;
    //this gave set3: 10 15 20 25 30 35 which is correct!

    //Now test with one value the same and make sure it doesnt print it
    // set1.add(10);
    // set1.add(20);
    // set1.add(30);
    // cout << "Set1: " << set1 << endl;

    // set2.add(10);
    // set2.add(25);
    // set2.add(35);
    // cout << "Set2: " << set2 << endl;

    // set3 = set1 | set2;

    // cout << "Set3: " << set3 << endl;
    //didnt print the second number so good!
    //works

    //forgot to test when both sides or one side is empty!

    // set1.add(10);
    // set1.add(20);
    // set1.add(30);
    // cout << "Set1: " << set1 << "   Set1 empty?(1 is empty): " << set1.empty() << endl;

    // // set2.add(10);
    // // set2.add(25);
    // // set2.add(35);
    // cout << "Set2: " << set2 << "   Set2 empty?(1 is empty): " << set2.empty() << endl;

    // set3 = set1 | set2;

    // cout << "Set3: " << set3 << endl;
    //-------------------------------------------------------------------------------------------------------------------

    ////TEST 6: test operator& ---------------------------------------------------------------------
    //SortedSet set1, set2, set3;

    //ALL OF THESE FIRST TESTS ARE INCORRECT! I HAD THE IDEA OF INTERSECTION WRONG!!!!!!!!!!!!!!!!!!!!!!
    // cout << "TEST operator& -----------------------" << endl;
    //first test that it puts the correct values in a row
    // set1.add(10);
    // set1.add(20);
    // set1.add(30);
    // cout << "Set1: " << set1 << endl;

    // set2.add(15);
    // set2.add(25);
    // set2.add(35);
    // cout << "Set2: " << set2 << endl;

    // set3 = set1 & set2;

    // cout << "Set3: " << set3 << endl;
    //works! now check that it works by putting duplicates in

    // set1.add(10);
    // set1.add(20);
    // set1.add(30);
    // cout << "Set1: " << set1 << endl;

    // set2.add(10);
    // set2.add(25);
    // set2.add(35);
    // cout << "Set2: " << set2 << endl;

    // set3 = set1 & set2;

    // cout << "Set3: " << set3 << endl;

    //now test what happens when sets are empty

    // set1.add(10);
    // set1.add(20);
    // set1.add(30);
    // cout << "Set1: " << set1 << "    " << set1.empty() << endl;

    // // set2.add(10);
    // // set2.add(25);
    // // set2.add(35);
    // cout << "Set2: " << set2 << "     " << set2.empty() << endl;

    // set3 = set1 & set2;

    // cout << "Set3: " << set3 << endl;
    // cout << "END TEST ------------------" << endl;

    //NOW TRY TEST AGAIN WITH THE CORRECT IDEA ON WHAT INTERSECTION IS DOING
    //==========================================================================================================================
    //this first test will check if the set will have nothing in it because nothing will match between the sets

    // SortedSet set1, set2, set3;
    // cout << "TEST operator& -----------------------" << endl;

    // set1.add(10);
    // set1.add(20);
    // set1.add(30);
    // cout << "Set1: " << set1 << endl;

    // set2.add(15);
    // set2.add(25);
    // set2.add(35);
    // cout << "Set2: " << set2 << endl;

    // set3 = set1 & set2;

    // cout << "Set3: " << set3 << endl;
    //good, set 3 was empty!


    //now try when one value is the same in one of the sets
    // SortedSet set1, set2, set3;
    // cout << "TEST operator& -----------------------" << endl;

    // set1.add(15);
    // set1.add(20);
    // set1.add(30);
    // cout << "Set1: " << set1 << endl;

    // set2.add(15);
    // set2.add(25);
    // set2.add(35);
    // cout << "Set2: " << set2 << endl;

    // set3 = set1 & set2;

    // cout << "Set3: " << set3 << endl;
    // good, set3 had 15 in it and changed to test middle start and end values

    //now try it with multiple matching values
    //  SortedSet set1, set2, set3;
    // cout << "TEST operator& -----------------------" << endl;

    // set1.add(15);
    // set1.add(25);
    // set1.add(30);
    // set1.add(100);
    // set1.add(50);
    // set1.add(5);
    // cout << "Set1: " << set1 << endl;

    // set2.add(15);
    // set2.add(25);
    // set2.add(30);
    // set2.add(75);
    // set2.add(68);
    // set2.add(5);
    // cout << "Set2: " << set2 << endl;

    // set3 = set1 & set2;

    // cout << "Set3: " << set3 << endl;
    //tried it with both multiple values and all values matching and it worked!

    //now try it with empty sets

    // SortedSet set1, set2, set3;
    // cout << "TEST operator& -----------------------" << endl;

    // set1.add(15);
    // set1.add(20);
    // set1.add(30);
    // cout << "Set1: " << set1 << endl;

    // // set2.add(15);
    // // set2.add(25);
    // // set2.add(35);
    // cout << "Set2: " << set2 << endl;

    // set3 = set1 & set2;

    // cout << "Set3: " << set3 << endl;

    //it worked for both, when either one was empty

    //==========================================================================================================================


    //WORKS, needed to add selection sort in order to get it in the right order-------------------------------------------------------


    ////TEST 7: test operator|= ---------------------------------------------------------------------
    // SortedSet set1, set2;

    // //first test that it puts the correct values in a row
    // // set1.add(10);
    // // set1.add(20);
    // // set1.add(30);
    // cout << "Set1: " << set1 << "     " << set1.empty() << endl;

    // // set2.add(15);
    // // set2.add(25);
    // // set2.add(35);
    // cout << "Set2: " << set2 << "     " << set2.empty() << endl;

    // set1 |= set2;

    // cout << "Set1: " << set1 << endl;

    //worked fine --------------------------------------------------------------------------------------------------------


    //TEST 7: test operator&= ---------------------------------------------------------------------
    //I had the idea of intersection wrong, so now that it is fixed, we will test again

    // SortedSet set1, set2;

    // cout << "TEST operator&= -----------------------" << endl;
    // //first test that it puts the correct values in a row
    // set1.add(10);
    // set1.add(20);
    // set1.add(30);
    // cout << "Set1: " << set1 << "     empty? (1 is empty): " << set1.empty() << endl;

    // set2.add(10);
    // set2.add(20);
    // set2.add(30);
    // cout << "Set2: " << set2 << "     empty? (1 is empty): " << set2.empty() << endl;

    // set1 &= set2;

    // cout << "set1 &= set2: " << set1 << endl;

    // cout << "END TEST -----------------------" << endl;

    //this worked for one value and multiple values, now try with empty sets!

    // SortedSet set1, set2;

    // cout << "TEST operator&= -----------------------" << endl;
    // //first test that it puts the correct values in a row
    // set1.add(10);
    // set1.add(20);
    // set1.add(30);
    // cout << "Set1: " << set1 << "     empty? (1 is empty): " << set1.empty() << endl;

    // set2.add(15);
    // set2.add(25);
    // set2.add(35);
    // cout << "Set2: " << set2 << "     empty? (1 is empty): " << set2.empty() << endl;

    // set1 &= set2;

    // cout << "set1 &= set2: " << set1 << endl;

    // cout << "END TEST -----------------------" << endl;

    //this worked for both empty, one or the other empty and when no values matched

    //now try self assigning
    // SortedSet set1, set2;

    // cout << "TEST operator&= -----------------------" << endl;
    // //first test that it puts the correct values in a row
    // set1.add(10);
    // set1.add(20);
    // set1.add(30);
    // cout << "Set1: " << set1 << "     empty? (1 is empty): " << set1.empty() << endl;

    // set2.add(15);
    // set2.add(25);
    // set2.add(35);
    // cout << "Set2: " << set2 << "     empty? (1 is empty): " << set2.empty() << endl;

    // set2 &= set2;

    // cout << "set1 &= set1: " << set2 << endl;

    // cout << "END TEST -----------------------" << endl;
    //---------------------------------------------------------------------------------------------------------------------------

    //TEST 8: Copy constructors-------------------------------------------------------------------------------
    // SortedSet set1;

    // set1.add(10);
    // set1.add(20);
    // set1.add(30);
    // set1.add(199);
    // cout << "Set1: " << set1 << endl;

    // SortedSet set2 = set1; // this is the code that tests the copy constructor

    // cout << "Set2: " << set2 << endl;

    //now try it with a copy constructor where an IntList is put in.
    // IntList list1;
    // list1.push_back(15);
    // list1.push_back(20);
    // list1.push_back(25);
    // list1.push_back(30);
    // cout << "list1: " << list1 << endl;

    // SortedSet set1 = list1; // this is the constructor where a set is constructed with copy constructor with a list put in
    // cout << "Set1: " << set1 << endl;
    //works

    //now try it with the list out of order to see if constructor sorts them correctly
    // IntList list1;
    // list1.push_back(17);
    // list1.push_back(15);
    // list1.push_back(30);
    // list1.push_back(25);
    // cout << "list1: " << list1 << endl;

    // SortedSet set1 = list1;
    // cout << "Set1: " << set1 << endl;
    //gives list1: 17 15 30 25
    //      Set1: 15 17 25 30            so works!


    //now try where there are duplicates and out of order
    // IntList list1;
    // list1.push_back(17);
    // list1.push_back(15);
    // list1.push_back(30);
    // list1.push_back(30);
    // list1.push_back(25);
    // cout << "list1: " << list1 << endl;

    // SortedSet set1 = list1;
    // cout << "Set1: " << set1 << endl;

    //gives  list1: 17 15 30 30 25
    //       Set1: 15 17 25 30          so works!

    //copy constructor works.-----------------------------------------------------------------------------------



    return 0;
}
