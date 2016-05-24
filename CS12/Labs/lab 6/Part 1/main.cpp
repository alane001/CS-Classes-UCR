#include <iostream>

using namespace std;


//LAB 6 PART 1
//You are to implement a function named mystrcat, which will be your own version of the cstring library's strcat function.
//strcat is strcat(destStr,SourceStr) which copies sourceStr to the end of destStr

/* Concatenate strings
   Appends a copy of the source string to the destination string.
   The terminating null character in destination is overwritten by the
   first character of source, and a null-character is included at the
   end of the new string formed by the concatenation of both in destination.

   returns destination.
*/
char * mystrcat (char * destination, const char * source);



int main() {
   char cstr1[80];
   char cstr2[80];

   cstr1[0] = 'L';
   cstr1[1] = 'i';
   cstr1[2] = 'o';
   cstr1[3] = 'n';
   cstr1[4] = 'e';
   cstr1[5] = 'l';
   cstr1[6] = '\0';

   cstr2[0] = 'M';
   cstr2[1] = 'e';
   cstr2[2] = 's';
   cstr2[3] = 's';
   cstr2[4] = 'i';
   cstr2[5] = '\0';

   cout << cstr1 << endl;
   cout << cstr2 << endl;

   mystrcat(cstr1, " ");
   mystrcat(cstr1, cstr2);

   cout << cstr1 << endl;

   return 0;
}


// null character is '\0'
//These pointers are just used instead of pass by reference. It alters the array in main, so it is not a copy
char * mystrcat (char * destination, const char * source)
{
    //Must have two in order to count correctly
    unsigned i = 0, j = 0;

    for(i = 0; destination[i] != '\0'; ++i)
    {
        //leave blank, just used as a counter up to where the null character is
    }
    for(j = 0; source[j] != '\0'; ++j)
    {
        destination[i+j] = source[j];
    }
    //This makes sure that the end will have the null character
    //Before, the test said that it wouldn't handle different sizes correctly
    destination[i+j] = '\0';


    return destination;
}
