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
    
    cout << endl;
    string answer4 = "yes";
    int userSize4 = 0, userValue4 = 0;
    
    while(answer4 == "yes")
    {
        cout << "Enter size: ";
        cin >> userSize4;
        cout << endl << "Enter value: ";
        cin >> userValue4;
        
        IntVector constructor4(userSize4, userValue4);
        
        //Not sure how to test if it is pulling the end or front since all are initialized to the same number!
        cout << "Test front() function: (should be the same as value) " << constructor4.front() << endl;
        cout << "Test back() function: (should be the same as value) " << constructor4.back();
    
        cout << endl << "Continue? (yes to continue) ";
        cin >> answer4;
    }
    
    //These all worked, so success.
    
    
    
    //The test failed for instansiating the non-default constructor with only one paramerter
    // eg: IntVector constructor(userSize);
    
    cout << endl;
    string answer5 = "yes";
    int userSize5 = 0;
    
    while(answer5 == "yes")
    {
        cout << "Enter size: ";
        cin >> userSize5;
        
        IntVector constructor5(userSize5);
        
        //Not sure how to test if it is pulling the end or front since all are initialized to the same number!
        cout << "Test front() function: (Value should be 0 b/c of default parameter called for value) " << constructor5.front() << endl;
        cout << "Test back() function: (Value should be 0 b/c of default parameter called for value) " << constructor5.back();
    
        cout << endl << "Continue? (yes to continue) ";
        cin >> answer5;
    }
    
    
    
    
    
    
    
    return 0;
}