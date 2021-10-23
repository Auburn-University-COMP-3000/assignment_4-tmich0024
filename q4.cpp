#include <iostream> 
#include <cstdlib> // for exit()
#include <cctype>  // for tolower()

using namespace std;

class Month
{
public:
  //constructor to set month based on first 3 chars of the month name
  Month(char c1, char c2, char c3);   // done, debugged
  //a constructor to set month base on month number, 1 = January etc.
  Month( int monthNumber);           // done, debugged
  //a default constructor (what does it do? nothing)
  Month(); // done, no debugging to do
  //an input function to set the month based on the month number
  void getMonthByNumber(istream&); // done, debugged
  //input function to set the month based on a three character input
  void getMonthByName(istream&);   // done, debugged
  //an output function that outputs the month as an integer,
  void outputMonthNumber(ostream&); // done, debugged
  //an output function that outputs the month as the letters.
  void outputMonthName(ostream&);   // done, debugged
  //a function that returns the next month as a month object
  Month nextMonth(); //
  //NB: each input and output function have a single formal parameter
  //for the stream
   
  int monthNumber();

private:
  int mnth;
};
