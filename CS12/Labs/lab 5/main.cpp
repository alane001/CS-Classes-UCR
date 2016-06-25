//----------------------------------------------------------------------------------------------
//DESCRIPTION

//To test these functions, your main function should follow these steps:

// 1. Declare an array of doubles of size 10.
// 2. Fill the array with 10 doubles entered by the user.
// 3. Call the mean function passing it this array and output the value returned.
// 4. Ask the user for the index (0 to 9) of the value they want to remove.
// 5. Call the display function to output the array.
// 6. Call the remove function to remove the value at the index provided by the user.
// 7. Call the display function again to output the array with the value removed.

//Here's a sample run of the program (as it should look in cloud9):

//Enter 10 values:
//4 4 5 6  8 9 10
// 5  2 1

//Mean: 5.4

//Enter index of value to be removed: 3

//Before removing value: 4, 4, 5, 6, 8, 9, 10, 5, 2, 1
//After removing value: 4, 4, 5, 8, 9, 10, 5, 2, 1

//----------------------------------------------------------------------------------------------


#include <iostream>

using namespace std;

//Passes in an array along with the size of the array and returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//Passes in an array, the size of the array, and the index of a value to be removed from the array.
//The function should remove the value at this index by shifting all of the values after this value up,
//keeping the same relative order of all values not removed.
void remove(double array[], int arraySize, int index);

//Passes in an array and the size of the array, and then outputs each value in the
//array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);


int main()
{
    const int ARRAY_SIZE = 10;
    double array[ARRAY_SIZE];
    int index = 0;

    cout << "Enter 10 values:" << endl;

    //allows for user input, continues to add elements until it reaches the end of the loop
    for(int i = 0; i < ARRAY_SIZE; ++i)
    {
        cin >> array[i];

    }

    //display mean
    cout << endl;
    cout << "Mean: " << mean(array, ARRAY_SIZE) << endl;
    cout << endl;

    cout << "Enter index of value to be removed: ";
    cin >> index;

    cout << endl;


    cout << "Before removing value: ";
    display(array, ARRAY_SIZE);

    //removes selected value
    remove(array, ARRAY_SIZE, index);

    cout << "After removing value: ";
    display(array, ARRAY_SIZE);

    cout << endl;


    return 0;

}


void display(const double array[], int arraySize)
{

    //had to majorly change this to accomidate the problem with not being able to remove
    //an element from the array, so had to initialize the last elemenet to some random value
    //that could be searched for in order to tell the display function not to output the last
    //value, without this the final array would have the very last term still and would not
    //fufill the requirments

    //eg if array was 1,2,3,4 and remove index 1 then without this fix the array would
    //look like 1,3,4,4 insead of the required 1,3,4
    for(int i = 0; i < arraySize; ++i)
    {
        //this if is for the last element in the array to not put a comma or the final value depending
        if(i == arraySize - 1)
        {
            //this makes sure last element doesnt print
            if(array[i] == -234.12)
            {
                //LEAVE BLANK dont want to output final element

            }
            //this prevents putting a comma at the end of the normal non removed array
            else
            {

                cout << array[i] << endl;

            }
        }
        else
        {
            //this if is the same as the else in previous if above, it makes it so that
            //the last element does not have a comma at the end for the removed array
            if(i == arraySize - 2 && array[i+1] == -234.12)
            {
                cout << array[i];
            }
            // this is for both arrays for outputting each element with a comma
            else
            {
                cout << array[i] << ", ";
            }
        }

    }

    return;
}

double mean(const double array[], int arraySize)
{
    double meanValue = 0.0;
    double addedValue = 0.0;

    for(int i = 0; i < arraySize; ++i)
    {
        addedValue = addedValue + array[i];
    }

    meanValue = addedValue / arraySize;

    return meanValue;
}

void remove(double array[], int arraySize, int index)
{
    for(int i = index; i < arraySize - 1; ++i)
    {
        array[i] = array[i + 1];

        //this is to change the last value to somthing to remove later
        if(i == arraySize - 2)
        {
            //use a very odd number so that someone wont pick it
            array[i + 1] = -234.12;
        }
    }


    return;
}






