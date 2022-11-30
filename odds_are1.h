#ifndef TEAM_23_MONTREAL_ODDS_ARE1_H
#define TEAM_23_MONTREAL_ODDS_ARE1_H

#include <string>
using namespace std;

//Class to handle invalid user input
class BadUserInput {
public:
    BadUserInput(const string&);
    string& what();
private:
    string message;
};

class OddsAre {
public:
    OddsAre(int);
    int numGen(int);
    int bonusMultiplier(int, int, int, int);
    void randomNumGen(int, int,int); //generates a random number
    //int searchList();  //Search card deck for player's guess
    void playerGuess(int, int, int, int);  //Feed in player guess and call searchList()

private: //Declaring private variables for the JumblePuzzle class
    int bet;
    int guess;
   
};

#endif //TEAM_23_MONTREAL_ODDS_ARE_H
