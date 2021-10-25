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

int Month::monthNumber(){
  return mnth;
}

Month Month::nextMonth(){
  int nextMonth = mnth + 1; 
  if(nextMonth == 13){
    nextMonth = 1;
  }
  return Month(nextMonth);
}

Month::Month(int monthNumber){
  mnth = monthNumber;
}

void Month::outputMonthNumber( ostream& out){
  out << mnth;
}

void Month::outputMonthName(ostream& out){
  string monthName[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  out << monthName[mnth - 1];
}

void error(char c1, char c2, char c3){
  cout << endl << c1 << c2 << c3 << " is not a month. Exiting\n";
  exit(1);
}

void error(int n){
  cout << endl << n << " is not a month number. Exiting" << endl;
  exit(1);
}

void Month::getMonthByNumber(istream& in){
  in >> mnth;
}

void Month::getMonthByName(istream& in){
  char c1, c2, c3;
  bool monthFlag = false;
  string comMonth;
  string monthName[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
  in >> c1 >> c2 >> c3;
  c1 = tolower(c1);
  c2 = tolower(c2);
  c3 = tolower(c3);

  comMonth.push_back(c1);
  comMonth.push_back(c2);
  comMonth.push_back(c3);
  for(int i = 0; i<12; i++){
    if (comMonth == monthName[i]){
      mnth = i + 1;
      monthFlag = true;
    }
  }
  if(monthFlag == false){
    error(c1, c2, c3);
  }
}

Month::Month(char c1, char c2, char c3){
  
  bool monthFlag = false;
  string comMonth;
  string monthName[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};

  c1 = tolower(c1);
  c2 = tolower(c2);
  c3 = tolower(c3);

  comMonth.push_back(c1);
  comMonth.push_back(c2);
  comMonth.push_back(c3);
  for(int i = 0; i<12; i++){
    if (comMonth == monthName[i]){
      mnth = i + 1;
      monthFlag = true;
    }
  }
  if(monthFlag == false){
    error(c1, c2, c3);
  }
}
Month::Month(){

}

int main(){
  cout << "Testing constructor Month(char, char, char)" << endl;
  Month m;
  m = Month('j', 'a', 'n');
  m.outputMonthNumber(cout); cout << " ";
  m.outputMonthName( cout); cout << " ";
  m = Month('f', 'e', 'b');
  m.outputMonthNumber(cout); cout << " ";
  m.outputMonthName( cout); cout << " ";
  m = Month('m', 'a', 'r');
  m.outputMonthNumber(cout); cout << " ";
  m.outputMonthName( cout); cout << " ";
  m = Month('a', 'p', 'r');
  m.outputMonthNumber(cout); cout << " ";
  m.outputMonthName( cout); cout << " ";
  m = Month('m', 'a', 'y');
  m.outputMonthNumber(cout); cout << " ";
  m.outputMonthName( cout); cout << " ";
  m = Month('j', 'u', 'n');
  m.outputMonthNumber(cout); cout << " ";
  m.outputMonthName( cout); cout << " ";
  m = Month('j', 'u', 'l');
  m.outputMonthNumber(cout); cout << " ";
  m.outputMonthName( cout); cout << " ";
  m = Month('a', 'u', 'g');
  m.outputMonthNumber(cout); cout << " ";
  m.outputMonthName( cout); cout << " ";
  m = Month('s', 'e', 'p');
  m.outputMonthNumber(cout); cout << " ";
  m.outputMonthName( cout); cout << " ";
  m = Month('o', 'c', 't');
  m.outputMonthNumber(cout); cout << " ";
  m.outputMonthName( cout); cout << " ";
  m = Month('n', 'o', 'v');
  m.outputMonthNumber(cout); cout << " ";
  m.outputMonthName( cout); cout << " ";
  m = Month('d', 'e', 'c');
  m.outputMonthNumber(cout); cout << " ";
  m.outputMonthName( cout); cout << " ";

  cout << endl << "Testing Month[int] constructor" << endl;
  int i = 1;
  while(i <= 12){
    Month mm(i);
    mm.outputMonthNumber( cout ); cout << " ";
    mm.outputMonthName(cout); cout << endl;
    i = i+1;
  }
  cout << endl
    << "Testing the getMonthByName and ouputMonth* \n";
  i = 1;
  Month mm;
  while( i <= 12){
    mm.getMonthByName(cin);
    mm.outputMonthNumber(cout); cout << " ";
    mm.outputMonthName(cout); cout << endl;
    i = i + 1;
  }
  cout << endl
    << "Testing the getMonthByNumber and outputMonth* \n";
  i = 1;
  while(i <= 12){
    mm.getMonthByNumber(cin);
    mm.outputMonthNumber(cout); cout << " ";
    mm.outputMonthName(cout); cout << endl;
    i = i + 1;
  }
  cout << endl
    << "Testing the nextMonth* \n";
  i = 1;
  while (i <= 12){
    Month mn(i);
    mn = mn.nextMonth();
    mn.outputMonthNumber(cout); cout << " ";
    mn.outputMonthName(cout); cout << endl;
    i = i+1;
  }
    
  return 0;
}