#include <iostream>
#include <iomanip>
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

int main(){
  int menu = 0;
  int tempScore;
  string tempName;
  const int MAX_PLAYERS = 10;
  vector<Player> players;

  while(menu != 5){
    cout << "[1] Add a new player" << endl
    << "[2] Print all players" << endl
    << "[3] See player score" << endl
    << "[4] Remove player" << endl
    << "[5] Exit" << endl;
    cin >> menu;
    while(menu < 1 || menu > 5){
      cout << "Please eneter a valid selection: ";
      cin >> menu;
    }
    // Switch to handle menu choice 
    switch(menu){
      case 1:{
        // Add a new player
        if (players.size() < MAX_PLAYERS){
          cout << "Please enter a name and score \nName: ";
          cin >> tempName;
          cout << "Score: ";
          cin >> tempScore;
          cout << endl;
          Player player(tempScore, tempName);
          players.push_back(player);
        }
        else{
          cout << "There are already 10 players, please remove one to add another." << endl;
        }
        break;
      }
      case 2:{
        // Print all players and scores
        cout << left << setw(20) << "Name" << setw(20) << "Score" << endl;
        for(int i = 0; i < players.size(); i++){
          cout << left << setw(20) << players[i].getName() << setw(20) << players[i].getScore() << endl;
        }
        cout << endl;
        break;
      }
      case 3:{
        // Search for name
        string nameSearch;
        bool nameFlag = false;
        cout << "Enter a name to search for: ";
        cin >> nameSearch;
        for(int i = 0; i < players.size(); i++){
          if(players[i].getName() == nameSearch){
            cout << players[i].getName() << "'s score: " << players[i].getScore() << endl;
            nameFlag = true;
            break;
          }
        }
        if (nameFlag == false){
          cout << "Error name not found. Please check spelling." << endl;
        }
        cout << endl;
        break;
      }
      case 4:{
        // remove player by name
        string nameSearch;
        int nloc = -1;
        cout << "Enter a name to search for: ";
        cin >> nameSearch;
        for(int i = 0; i < players.size(); i++){
          if(players[i].getName() == nameSearch){
            nloc = i;
            break;
          }
        }
        if(nloc != -1){
          players.erase(players.begin()+nloc);
          cout << "Player removed." << endl;
        }
        else{ cout << "No players removed." << endl; }
        cout << endl;
        break;
      }
    }
  }

}

Player::Player() {
  name = "";
  score = 0;
}

Player::Player(int newScore, string newName){
  name = newName;
  score = newScore;
}

void Player::setName(string newName){
  name = newName;
}

void Player::setScore(int newScore){
  score = newScore;
}

string Player::getName(){
  return name;
}

int Player::getScore(){
  return score;
}

// Prototypes
void addPlayer(int &numPlayers, vector<Player> &players);
void printPlayers(int numPlayers, vector<Player> players);
void searchPlayers(int numPlayers, vector<Player> players);
void removePlayer(int &numPlayers, vector<Player> &players);

// add new player
void addPlayer(int &numPlayers, vector<Player> &players){
  if(numPlayers == 10){
    cout << "Player array full." << endl;
  }
  else {
    cout << "Enter new player name." << endl;
    string name;
    cin >> name;
    cout << "Enter new player score." << endl;
    int score;
    cin >> score;
    Player newPlayer(score, name);
    players.push_back(newPlayer);
    numPlayers++;
  }
}

void printPlayers(int numPlayers, vector<Player> players){
  cout << "Player Scores" << endl;
  for (int i = 0; i < numPlayers; i++){
    cout << players[i].getName() << " " << players[i].getScore() << endl;
  }
}