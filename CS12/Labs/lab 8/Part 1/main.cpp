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