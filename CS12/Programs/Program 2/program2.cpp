#include <iostream>
#include <string>

using namespace std;

class Date
{
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message:

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
 ­      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message:

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).

       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor.

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/1/2012".
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 1, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january.
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-­leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};

//ADD member function definitions below here, above is all given to us

Date::Date()
{
    day = 1;
    month = 1;
    year = 2000;
    monthName = "January";

    return;
}

Date::Date(unsigned m, unsigned d, unsigned y)
{
    // these four statements will handel when given values are out of range
    //cout << "days per feb: " << daysPerMonth(m, y);
    if(m > 12 && d > 31)
    {
        day = 31;
        month = 12;
        year = y;

        cout << "Invalid date values: Date corrected to " << month << "/"
        << day << "/" << year << "." << endl;

    }

    else if (m > 12 && d < 1)
    {
        day = 1;
        month = 12;
        year = y;

        cout << "Invalid date values: Date corrected to " << month << "/"
        << day << "/" << year << "." << endl;
    }

    else if (m < 1 && d > 31)
    {
        day = 31;
        month = 1;
        year = y;

        cout << "Invalid date values: Date corrected to " << month << "/"
        << day << "/" << year << "." << endl;
    }

    else if (m < 1 && d < 1)
    {
        day = 1;
        month = 1;
        year = y;

        cout << "Invalid date values: Date corrected to " << month << "/"
        << day << "/" << year << "." << endl;

    }
    //this allows to check if a leap year will affect the result
    else if (d > daysPerMonth(m, y))
    {
        day = daysPerMonth(m, y);
        month = m;
        year = y;
        cout << "Invalid date values: Date corrected to " << month << "/"
        << day << "/" << year << "." << endl;

    }

    //These next couple will make sure number of days in a month is being handeled correctly
    //else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12 && d > 31)
    //{
    //    day = 31;
    //    month = m;
    //    year = y;

    //    cout << "Invalid date values: Date corrected to " << month << "/"
    //    << day << "/" << year << "." << endl;
    //}
    //else if (m == 4 || m == 6 || m == )
    else
    {
        day = d;
        month = m;
        year = y;
    }

    return;
}

Date::Date(const string &mn, unsigned d, unsigned y){

    if (mn == "January" || mn == "january" || mn == "February" || mn == "february" || mn == "March" || mn == "march" || mn == "April" || mn == "april" || mn == "May" || mn == "may" || mn == "June" || mn == "june" || mn == "July" || mn == "july" || mn == "August" || mn == "august" || mn == "September" || mn == "september" || mn == "October" || mn == "october" || mn == "November" || mn == "november" || mn == "December" || mn == "december")
    {
        monthName = mn;
        month = number(monthName);
        //cout << "D: " << d << endl << "Days per month: " << daysPerMonth(month, y) << endl;
        //cout << "Is leap: " << isLeap(y) << endl;
        if (d > 31)
        {
            day = 31;
            year = y;
            cout << "Invalid date values: Date corrected to " << month << "/"
            << day << "/" << year << "." << endl;
        }

        else if (d < 1)
        {
            day = 1;
            year = y;
            cout << "Invalid date values: Date corrected to " << month << "/"
            << day << "/" << year << "." << endl;
        }
        else if (d > daysPerMonth(month, y))
        {
            day = daysPerMonth(month, y);
            //month = month;
            year = y;
            cout << "Invalid date values: Date corrected to " << month << "/"
            << day << "/" << year << "." << endl;

        }

        else
        {
            day = d;
            year = y;
        }

    }

    else
    {
        month = 1;
        day = 1;
        year = 2000;
        monthName = "January";
        cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
    }



    return;
}

//Print functions below

void Date::printNumeric() const
{

    cout << month << "/" << day << "/" << year;

    return;
}


// COME BACK AND FIX, must alter to get full names and uppercase
void Date::printAlpha() const
{
    string monthName2;
    monthName2 = name(month);

    cout << monthName2 << " " << day << ", " << year;

    return;
}

//checks if leap year or not
bool Date::isLeap(unsigned y) const
{
    // had to change to false due to incorrect reading
    bool isL = false;

    if (y % 4 == 0)
    {
        isL = true;
    }
    if (y % 100 == 0)
    {
        isL = false;
    }
    if (y % 400 == 0)
    {
        isL = true;
    }


    return isL;
}

//gives number of days per month
// all data for number of days in month is from www.timeanddate.com/calendar/months
unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{
    int days = 0;

    if (m == 2)
    {
        if (isLeap(y))
        {
            days = 29;
        }
        else
        {
            days = 28;
        }
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        days = 30;
    }
    else
    {
        days = 31;
    }

    return days;
}

string Date::name(unsigned m) const
{
    string monthName = " ";

    if (m == 1)
    {
        monthName = "January";
    }
    else if (m == 2)
    {
        monthName = "February";
    }
    else if (m == 3)
    {
        monthName = "March";
    }
    else if (m == 4)
    {
        monthName = "April";
    }
    else if (m == 5)
    {
        monthName = "May";
    }
    else if (m == 6)
    {
        monthName = "June";
    }
    else if (m == 7)
    {
        monthName = "July";
    }
    else if (m == 8)
    {
        monthName = "August";
    }
    else if (m == 9)
    {
        monthName = "September";
    }
    else if (m == 10)
    {
        monthName = "October";
    }
    else if (m == 11)
    {
        monthName = "November";
    }
    else if (m == 12)
    {
        monthName = "December";
    }

    return monthName;
}


unsigned Date::number(const string &mn) const
{
    int dayNumber = 0;

    if (mn == "January" || mn == "january")
    {
        dayNumber = 1;
    }
    else if (mn == "February" || mn == "february")
    {
        dayNumber = 2;
    }
    else if (mn == "March" || mn == "march")
    {
        dayNumber = 3;
    }
    else if (mn == "April" || mn == "april")
    {
        dayNumber = 4;
    }
    else if (mn == "May" || mn == "may")
    {
        dayNumber = 5;
    }
    else if (mn == "June" || mn == "june")
    {
        dayNumber = 6;
    }
    else if (mn == "July" || mn == "july")
    {
        dayNumber = 7;
    }
    else if (mn == "August" || mn == "august")
    {
        dayNumber = 8;
    }
    else if (mn == "September" || mn == "september")
    {
        dayNumber = 9;
    }
    else if (mn == "October" || mn == "october")
    {
        dayNumber = 10;
    }
    else if (mn == "November" || mn == "november")
    {
        dayNumber = 11;
    }
    else if (mn == "December" || mn == "december")
    {
        dayNumber = 12;
    }


    return dayNumber;

}

// DO NOT alter things below this, this is the code given to us

Date getDate();

int main() {

   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;

   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
