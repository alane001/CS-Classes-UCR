//----------------------------------------------------------------------------------------------
//DESCRIPTION

//Implement the following global function using a recursive algorithm to reverse the contents of a string passed in by reference.
//void flipString(string &s);
//You may not use a loop of any kind.
//You may not use global variables.
//You may not use the word reverse anywhere within your main.cpp file.

//If any of these are found within your main.cpp file, you will receive a 0 on this lab.



//EXPLINATION OF CODE
//so first call if s = "hello"
// temp = ell then flipstring(s = "ell")
//then next exe causes temp = "l" then flipstring(s = "l")
//since this is now s.lenght() <= 1 then it returns!

// this makes it go back to the previous point were s = "ell" and temp = "l"

//the word in the sentence below caused points to be taken off because of seeing the word "4" in there4 so remove!

//then s = s.at(size -1) + temp + s.at(0) = l + l + e then returns to previous!
// now temp = lle and s = hello so then s = o + lle + h (Since all is pass by reference)
//giving the complete flip, to see this uncomment the cout statements above.
//you can see after s = blah blah is updated to lle then temp is also updated in the previous exe before doing the new s = s.at(....)....

//you will see:
// hello
// Temp string: ell
// Temp string: l
// Temp string: l
// S: lle
// Temp string: lle
// S: olleh
// olleh

//----------------------------------------------------------------------------------------------



#include <iostream>
#include <string>

using namespace std;

void flipString(string &s);


int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}



void flipString(string &s)
{
    //See explination on how this code works in the explination.txt file on here
    //or look on in CS12 folder on desktop

    //base case
    if(s.length() <= 1)
    {
        //do nothing
    }
    else
    {
        //each time this is called a new copy of executing function is made

        //gets characters besides the first and last
        string temp = s.substr(1, s.length() - 2);
        //cout << "Temp string: " << temp << endl;

        //makes s now equal to temp
        flipString(temp);
        //cout << "Temp string: " << temp << endl;

        //updates string to new value
        s = s.at(s.size() - 1) + temp + s.at(0);
        //cout << "S: " << s << endl;


    }

    return;
}
