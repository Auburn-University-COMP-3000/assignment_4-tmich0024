#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player
{
 private:
   string name;
   int score;
 public:
   Player();
   Player(int newScore, string newname);
   void setName(string newName);
   void setScore(int newScore);
   string getName();
   int getScore();
};


