#include <iostream>
#include "IntVector.h"
#include <string>

using namespace std;

//The whole point of this main.cpp is to be a test harness to make sure that the IntVector.cpp file is working correctly
int main()
{
    //This will test the default constructor. However to test it correctly we need a couple other
    //memeber functions to see if the correct values were used for the data memebers
    //IntVector newVector;
    
    //Now that the object was instansiated, we can test the size and capacity functions to see if they
    //work, while testing if the default constructor works.
    // cout << "Size of default constructor (expect 0): " << newVector.size() << endl;
    
    // cout << "Capacity of default constructor (expect 0): " << newVector.capacity() << endl;
    
    //These worked! so can move on to next constructor.
    
    
    
    
    
    // cout << endl;
    // string answer = "yes";
    // int userSize = 0, userValue = 0;
    
    // while(answer == "yes")
    // {
    //     cout << "Enter size: ";
    //     cin >> userSize;
    //     cout << endl << "Enter value: ";
    //     cin >> userValue;
        
    //     IntVector constructor(userSize, userValue);
    
    //     cout << "Size of constructor (expect " << userSize << "): " << constructor.size() << endl;
    
    //     cout << "Capacity of constructor (expect " << userSize << "): " << constructor.capacity() << endl;
    
    //     cout << endl << "Continue? (yes to continue) ";
    //     cin >> answer;
    // }
    
    
    //Once out of loop, the destructor was called to delete everything, therefore it is working
    //To test that, I wrote in a cout code into the destructor to tell me when it was called.
    
    
    
    
    
    
    //Now lets test the bool empty function
    
    // IntVector empFunc;
    
    // cout << "Is default empty? (expect 1 for default constructor) " << empFunc.empty();
    
    // cout << endl;
    // string answer2 = "yes";
    // int userSize2 = 0, userValue2 = 0;
    
    // while(answer2 == "yes")
    // {
    //     cout << "Enter size: ";
    //     cin >> userSize2;
    //     cout << endl << "Enter value: ";
    //     cin >> userValue2;
        
    //     IntVector constructor2(userSize2, userValue2);
        
    //     cout << "Is default empty? (expect 1 for true, 0 if false) " << constructor2.empty();
    
    //     cout << endl << "Continue? (yes to continue) ";
    //     cin >> answer2;
    // }
    
    //This loop worked for the values I used. Once I used size = 0 for the loop it changed to true (1);
    
    
    
    
    // cout << endl;
    // string answer3 = "yes";
    // int userSize3 = 0, userValue3 = 0, userIndex = 0;
    
    // while(answer3 == "yes")
    // {
    //     cout << "Enter size: ";
    //     cin >> userSize3;
    //     cout << endl << "Enter value: ";
    //     cin >> userValue3;
    //     cout << endl << "Enter index: ";
    //     cin >> userIndex;
        
    //     IntVector constructor3(userSize3, userValue3);
    //     cout << "Make sure to test the throw, out of range check as well. Do size = 10 and index >= 10." << endl;
    //     cout << "Test of .at function: (should return same value as value entered) " << constructor3.at(userIndex);
    
    //     cout << endl << "Continue? (yes to continue) ";
    //     cin >> answer3;
    // }
    //It threw an out of range when I did size = 10 value = 10 and index = 10. SO success.
    //Also, everytime I called an index all values were the same as value, so success.
    
    
    
    
    
    //Now lets test the back and front functions
    
    // cout << endl;
    // string answer4 = "yes";
    // int userSize4 = 0, userValue4 = 0;
    
    // while(answer4 == "yes")
    // {
    //     cout << "Enter size: ";
    //     cin >> userSize4;
    //     cout << endl << "Enter value: ";
    //     cin >> userValue4;
        
    //     IntVector constructor4(userSize4, userValue4);
        
    //     //Not sure how to test if it is pulling the end or front since all are initialized to the same number!
    //     cout << "Test front() function: (should be the same as value) " << constructor4.front() << endl;
    //     cout << "Test back() function: (should be the same as value) " << constructor4.back();
    
    //     cout << endl << "Continue? (yes to continue) ";
    //     cin >> answer4;
    // }
    
    //These all worked, so success.
    
    
    
    //The test failed for instansiating the non-default constructor with only one paramerter
    // eg: IntVector constructor(userSize);
    
    // cout << endl;
    // string answer5 = "yes";
    // int userSize5 = 0;
    
    // while(answer5 == "yes")
    // {
    //     cout << "Enter size: ";
    //     cin >> userSize5;
        
    //     IntVector constructor5(userSize5);
        
    //     //Not sure how to test if it is pulling the end or front since all are initialized to the same number!
    //     cout << "Test front() function: (Value should be 0 b/c of default parameter called for value) " << constructor5.front() << endl;
    //     cout << "Test back() function: (Value should be 0 b/c of default parameter called for value) " << constructor5.back();
    
    //     cout << endl << "Continue? (yes to continue) ";
    //     cin >> answer5;
    // }
    
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //ABOVE THIS IS FROM THE LAB THAT WAS ALREADY SUCCESSFUL, retested the at, front and back functions for the non constant versions.
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    
    
    //Now to test the private memeber functions, to do this I allowed the functions to be in public just to test them easier
    //IF THIS TEST IS USED THEN YOU MUST CHANGE THE .H FILE'S PRIVATE MEMEBER FUNCTIONS TO PUBLIC!!!!!!!!!!!!!!!!!!!
    //++++++++++++++++++++++++++++++++++++++++++++++ LOOOOOOK AT ABOVE STATEMENT!!!!!!!!!!!!!!!!!!!!!!!!
    
    
    //This first one will test expand();
    
    // string answer = "yes";
    // int userSize = 0, userValue = 0;
    
    // while(answer == "yes")
    // {
    //     cout << "Enter size: ";
    //     cin >> userSize;
    //     cout << endl << "Enter value: ";
    //     cin >> userValue;
        
    //     IntVector constructor(userSize, userValue);
    
    //     cout << "Size of constructor (expect " << userSize << "): " << constructor.size() << endl;
    
    //     cout << "Capacity of constructor (expect " << userSize << "): " << constructor.capacity() << endl;
        
    //     //This will print all values in the array
    //     for(unsigned i = 0; i < constructor.capacity(); ++i)
    //     {
    //         cout << constructor.at(i) << " ";
    //     }
        
        
    //     //Now expand it to see if it does it correctly.
    //     constructor.expand();
        
    //     cout << "Size of constructor (expect the same value as above) " << constructor.size() << endl;
    
    //     cout << "Capacity of constructor (expect 2x larger) " << constructor.capacity() << endl;
        
    //     //this is to check that the array size is changed, expect this to fail, out of range, this shows the capicity did change
    //     for(unsigned i = 0; i < constructor.capacity(); ++i)
    //     {
    //         cout << constructor.at(i) << " ";
    //     }
        
    //     cout << endl << "Continue? (yes to continue) ";
    //     cin >> answer;
    // }
    //SUCCESSFUL
    
    
    //This one will test expand(int);
    
    // string answer = "yes";
    // int userSize = 0, userValue = 0, expandNum = 0;
    
    // while(answer == "yes")
    // {
    //     cout << "Enter size: ";
    //     cin >> userSize;
    //     cout << endl << "Enter value: ";
    //     cin >> userValue;
        
    //     IntVector constructor(userSize, userValue);
    
    //     cout << "Size of constructor (expect " << userSize << "): " << constructor.size() << endl;
    
    //     cout << "Capacity of constructor (expect " << userSize << "): " << constructor.capacity() << endl;
        
    //     //This will print all values in the array
    //     for(unsigned i = 0; i < constructor.capacity(); ++i)
    //     {
    //         cout << constructor.at(i) << " ";
    //     }
        
    //     cout << "Expand by how much? ";
    //     cin >> expandNum;
        
    //     //Now expand it to see if it does it correctly.
    //     constructor.expand(expandNum);
        
    //     cout << "Size of constructor (expect the same value as above) " << constructor.size() << endl;
    
    //     cout << "Capacity of constructor (expect + " << expandNum << " larger) " << constructor.capacity() << endl;
        
    //     //this is to check that the array size is changed, expect this to fail, out of range, this shows the capicity did change
    //     for(unsigned i = 0; i < constructor.capacity(); ++i)
    //     {
    //         cout << constructor.at(i) << " ";
    //     }
        
    //     cout << endl << "Continue? (yes to continue) ";
    //     cin >> answer;
    // }
    //SUCCESSFUL
    
    
    
    
    
    //Now lets test the insert function
    
    string answer = "yes";
    int userSize = 0, userValue = 0, userIndex = 0, userValue2 = 0;
    
    while(answer == "yes")
    {
        cout << "Enter size: ";
        cin >> userSize;
        cout << endl << "Enter value: ";
        cin >> userValue;
        
        IntVector constructor(userSize, userValue);
    
        cout << "Size of constructor (expect " << userSize << "): " << constructor.size() << endl;
    
        cout << "Capacity of constructor (expect " << userSize << "): " << constructor.capacity() << endl;
        
        constructor.at(1) = 2;
        constructor.at(2) = 3;
        constructor.at(3) = 4;
        constructor.at(4) = 5;
        
        //This will print all values in the array
        for(unsigned i = 0; i < constructor.size(); ++i)
        {
            cout << constructor.at(i) << " ";
        }
        cout << endl;
        
        //Now lets insert a value at a user defined index
        cout << "Index? ";
        cin >> userIndex;
        cout << endl << "Value to be put in: ";
        cin >> userValue2;
        cout << endl;
        
        constructor.insert(userIndex, userValue2);
        
        //Now check to see if capacity increased;
        cout << "Size of constructor (expect " << userSize << " + 1 now): " << constructor.size() << endl;
    
        cout << "Capacity of constructor (expect double of last one): " << constructor.capacity() << endl;
        
        //for loop to see if that value was added correctly
        for(unsigned i = 0; i < constructor.size(); ++i)
        {
            cout << constructor.at(i) << " ";
        }
        
        cout << endl << "Continue? (yes to continue) ";
        cin >> answer;
    }
    //FUNCTION WORKED
    
    
    
    //Now lets test erase
    
    // string answer = "yes";
    // int userSize = 0, userValue = 0, userIndex = 0;
    
    // while(answer == "yes")
    // {
    //     cout << "Enter size: ";
    //     cin >> userSize;
    //     cout << endl << "Enter value: ";
    //     cin >> userValue;
        
    //     IntVector constructor(userSize, userValue);
    
    //     cout << "Size of constructor (expect " << userSize << "): " << constructor.size() << endl;
    
    //     cout << "Capacity of constructor (expect " << userSize << "): " << constructor.capacity() << endl;
        
    //     //This will print all values in the array
    //     for(unsigned i = 0; i < constructor.size(); ++i)
    //     {
    //         cout << constructor.at(i) << " ";
    //     }
    //     cout << endl;
        
    //     //Now lets insert a value at a user defined index
    //     cout << "Index? ";
    //     cin >> userIndex;
    //     cout << endl;
        
    //     constructor.erase(userIndex);
        
    //     //Now check to see if capacity increased;
    //     cout << "Size of constructor (expect " << userSize << " - 1 now): " << constructor.size() << endl;
    
    //     //cout << "Capacity of constructor (expect double of last one): " << constructor.capacity() << endl;
        
    //     //for loop to see if that value was added correctly
    //     for(unsigned i = 0; i < constructor.size(); ++i)
    //     {
    //         cout << constructor.at(i) << " ";
    //     }
        
    //     cout << endl << "Continue? (yes to continue) ";
    //     cin >> answer;
    // }
    //WORKED!
    
    
    
    //Now lets test push_back
    
    // string answer = "yes";
    // int userSize = 0, userValue = 0, userValue2 = 0;
    
    // while(answer == "yes")
    // {
    //     cout << "Enter size: ";
    //     cin >> userSize;
    //     cout << endl << "Enter value: ";
    //     cin >> userValue;
        
    //     IntVector constructor(userSize, userValue);
    
    //     cout << "Size of constructor (expect " << userSize << "): " << constructor.size() << endl;
    
    //     cout << "Capacity of constructor (expect " << userSize << "): " << constructor.capacity() << endl;
        
    //     //This will print all values in the array
    //     for(unsigned i = 0; i < constructor.size(); ++i)
    //     {
    //         cout << constructor.at(i) << " ";
    //     }
    //     cout << endl;
        
    //     //Now lets insert a value at a user defined index
    //     cout << "Value on end: ";
    //     cin >> userValue2;
    //     cout << endl;
        
    //     constructor.push_back(userValue2);
        
    //     //Now check to see if capacity increased;
    //     cout << "Size of constructor (expect " << userSize << " + 1 now): " << constructor.size() << endl;
    
    //     cout << "Capacity of constructor (expect double of last one): " << constructor.capacity() << endl;
        
    //     //for loop to see if that value was added correctly
    //     for(unsigned i = 0; i < constructor.size(); ++i)
    //     {
    //         cout << constructor.at(i) << " ";
    //     }
        
    //     cout << endl << "Continue? (yes to continue) ";
    //     cin >> answer;
    // }
    //WORKED!!!!!!  
    
    
    
    
    //Lets test pop back now
    
    // string answer = "yes";
    // int userSize = 0, userValue = 0;
    
    // while(answer == "yes")
    // {
    //     cout << "Enter size: ";
    //     cin >> userSize;
    //     cout << endl << "Enter value: ";
    //     cin >> userValue;
        
    //     IntVector constructor(userSize, userValue);
    
    //     cout << "Size of constructor (expect " << userSize << "): " << constructor.size() << endl;
    
    //     cout << "Capacity of constructor (expect " << userSize << "): " << constructor.capacity() << endl;
        
    //     //This will print all values in the array
    //     for(unsigned i = 0; i < constructor.size(); ++i)
    //     {
    //         cout << constructor.at(i) << " ";
    //     }
    //     cout << endl;
        
        
    //     constructor.pop_back();
        
    //     //Now check to see if capacity increased;
    //     cout << "Size of constructor (expect " << userSize << " - 1 now): " << constructor.size() << endl;
    
    //     //cout << "Capacity of constructor (expect double of last one): " << constructor.capacity() << endl;
        
    //     //for loop to see if that value was added correctly
    //     for(unsigned i = 0; i < constructor.size(); ++i)
    //     {
    //         cout << constructor.at(i) << " ";
    //     }
        
    //     cout << endl << "Continue? (yes to continue) ";
    //     cin >> answer;
    // }
    //WORKED
    
    
    
    
    //Now test clear function
    
    // string answer = "yes";
    // int userSize = 0, userValue = 0;
    
    // while(answer == "yes")
    // {
    //     cout << "Enter size: ";
    //     cin >> userSize;
    //     cout << endl << "Enter value: ";
    //     cin >> userValue;
        
    //     IntVector constructor(userSize, userValue);
    
    //     cout << "Size of constructor (expect " << userSize << "): " << constructor.size() << endl;
    
    //     cout << "Capacity of constructor (expect " << userSize << "): " << constructor.capacity() << endl;
        
    //     //This will print all values in the array
    //     for(unsigned i = 0; i < constructor.size(); ++i)
    //     {
    //         cout << constructor.at(i) << " ";
    //     }
    //     cout << endl;
        
        
    //     constructor.clear();
        
    //     //Now check to see if capacity increased;
    //     cout << "Size of constructor (expect 0): " << constructor.size() << endl;
    
    //     //cout << "Capacity of constructor (expect double of last one): " << constructor.capacity() << endl;
        
    //     //for loop to see if that value was added correctly
    //     for(unsigned i = 0; i < constructor.size(); ++i)
    //     {
    //         cout << constructor.at(i) << " ";
    //     }
        
    //     cout << endl << "Continue? (yes to continue) ";
    //     cin >> answer;
    // }
    //WORKED!!!!!!
    
    
    
    //Now test resize function
    
    // string answer = "yes";
    // int userSize = 0, userValue = 0, resizeVal = 0, userValue2 = 0;
    
    // while(answer == "yes")
    // {
    //     cout << "Enter size: ";
    //     cin >> userSize;
    //     cout << endl << "Enter value: ";
    //     cin >> userValue;
        
    //     IntVector constructor(userSize, userValue);
    
    //     cout << "Size of constructor (expect " << userSize << "): " << constructor.size() << endl;
    
    //     cout << "Capacity of constructor (expect " << userSize << "): " << constructor.capacity() << endl;
        
    //     //This will print all values in the array
    //     for(unsigned i = 0; i < constructor.size(); ++i)
    //     {
    //         cout << constructor.at(i) << " ";
    //     }
    //     cout << endl;
        
    //     cout << "Resize value: ";
    //     cin >> resizeVal;
    //     // cout << endl << "Value to fill in with: ";
    //     // cin >> userValue2;
    //     // cout << endl;
        
    //     constructor.resize(resizeVal);//, userValue2);
        
    //     //Now check to see if capacity increased;
    //     cout << "Size of constructor (expect " << resizeVal << "): " << constructor.size() << endl;
    
    //     cout << "Capacity of constructor (depends on which expand called, either double or just increase): " << constructor.capacity() << endl;
        
    //     //for loop to see if that value was added correctly
    //     for(unsigned i = 0; i < constructor.size(); ++i)
    //     {
    //         cout << constructor.at(i) << " ";
    //     }
        
    //     cout << endl << "Continue? (yes to continue) ";
    //     cin >> answer;
    // }
    //WORKED had to do some work to get it correct, but it seems to be working now
    
    
    
    
    //Now lets test the reserve function
    
    // string answer = "yes";
    // int userSize = 0, userValue = 0, resizeVal = 0;
    
    // while(answer == "yes")
    // {
    //     cout << "Enter size: ";
    //     cin >> userSize;
    //     cout << endl << "Enter value: ";
    //     cin >> userValue;
        
    //     IntVector constructor(userSize, userValue);
    
    //     cout << "Size of constructor (expect " << userSize << "): " << constructor.size() << endl;
    
    //     cout << "Capacity of constructor (expect " << userSize << "): " << constructor.capacity() << endl;
        
    //     //This will print all values in the array
    //     for(unsigned i = 0; i < constructor.size(); ++i)
    //     {
    //         cout << constructor.at(i) << " ";
    //     }
    //     cout << endl;
        
    //     cout << "Reserve value: ";
    //     cin >> resizeVal;
    //     cout << endl;
        
    //     cout << "Should do nothing to the capacity if the capacity (" << constructor.capacity() << ") is larger than " << resizeVal << endl;
        
    //     constructor.reserve(resizeVal);
        
    //     //Now check to see if capacity increased;
    //     cout << "Size of constructor (expect should not change!): " << constructor.size() << endl;
    
    //     cout << "Capacity of constructor (depends on which expand called, either double or just increase): " << constructor.capacity() << endl;
        
    //     // //for loop to see if that value was added correctly
    //     // for(unsigned i = 0; i < constructor.size(); ++i)
    //     // {
    //     //     cout << constructor.at(i) << " ";
    //     // }
        
    //     cout << endl << "Continue? (yes to continue) ";
    //     cin >> answer;
    // }
    //WORKED
    
    
    
    //Now lets test assign
    
    // string answer = "yes";
    // int userSize = 0, userValue = 0, resizeVal = 0, userValue2 = 0;
    
    // while(answer == "yes")
    // {
    //     cout << "Enter size: ";
    //     cin >> userSize;
    //     cout << endl << "Enter value: ";
    //     cin >> userValue;
        
    //     IntVector constructor(userSize, userValue);
    
    //     cout << "Size of constructor (expect " << userSize << "): " << constructor.size() << endl;
    
    //     cout << "Capacity of constructor (expect " << userSize << "): " << constructor.capacity() << endl;
        
    //     //This will print all values in the array
    //     for(unsigned i = 0; i < constructor.size(); ++i)
    //     {
    //         cout << constructor.at(i) << " ";
    //     }
    //     cout << endl;
        
    //     cout << "Resize value: ";
    //     cin >> resizeVal;
    //     cout << endl << "Value to fill in with: ";
    //     cin >> userValue2;
    //     cout << endl;
        
    //     constructor.assign(resizeVal, userValue2);
        
    //     //Now check to see if capacity increased;
    //     cout << "Size of constructor (expect " << resizeVal << "): " << constructor.size() << endl;
    
    //     cout << "Capacity of constructor (depends on which expand called, either double or just increase): " << constructor.capacity() << endl;
        
    //     //for loop to see if that value was added correctly
    //     for(unsigned i = 0; i < constructor.size(); ++i)
    //     {
    //         cout << constructor.at(i) << " ";
    //     }
        
    //     cout << endl << "Continue? (yes to continue) ";
    //     cin >> answer;
    // }
    //WORKED
    
    
    
    
    
    
    
    return 0;
}