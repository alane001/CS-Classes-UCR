//-----------------------------------------------------------------------------------------------
//DESCRIPTION

//In this exercise you are to use a vector to store integers entered by the user. Once you have filled the vector,
// ask the user for a value to search for. If found, remove the value from the vector,
//keeping all other values in the same relative order, and then display the remaining values.

//-----------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//Fills vector with user input until user enters 0 (does not include 0 within vector).
void fillVector(vector<int> &v){
    int input = 1;
    while (input != 0){
        cout << "Enter a value. ";
        cin >> input;
        if (input != 0){
            v.push_back(input);
        }
        else {
            return;
        }
    }
}

//Searches for val within vector.
//If val found, returns index of first instance of val.
//If val not found, returns UINT_MAX (constant provided by the climits library).
unsigned search(const vector<int> &v, int val){
   for (unsigned i = 0; i < v.size(); ++i){
    if (v.at(i) == val){
        return i;
    }
    //else if (i == v.size() && v.at(i) != val){
    //    return UINT_MAX;
    //}
   }
   return UINT_MAX;
}

//Removes from the vector the value at index, keeping all other values in the same relative order.
void remove(vector<int> &v, unsigned index){

    for(int i = index; i < v.size(); ++i){
        if (i < v.size() - 1){
            v.at(i) = v.at(i+1);
        }
        else{
            v.pop_back();
        }
    }
}


//Displays all values within vector, each value separated by a space.
void display(const vector<int> &v){
    for (int i = 0; i < v.size(); ++i){
       cout << v.at(i) << " ";
   }
}


int main()
{
   vector<int> v;
   int value;

   fillVector(v);
   //for (int i = 0; i < v.size(); ++i){
    //   cout << v.at(i) << endl;
   //}
   cout << "Enter value to search for: ";
   cin >> value;

   //search for value
   unsigned pos = search(v, value);

   cout << "Found: ";// << pos;

   //if val found, output position it was found and then remove it from vector
   //otherwise output "NOT FOUND"
   //UINT_MAX is a constant provided by the climits library (see http://www.cplusplus.com/reference/climits/ for more info)
    if (pos != UINT_MAX)
    {
        cout << pos << endl;
        remove(v, pos);
    }
    else
    {
        cout << "NOT FOUND" << endl;
    }

   cout << "Result: ";
   //output the vector's values.
   display(v);
   cout << endl;

}
