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
    void OddsAre(int);
    int numGen();
    int bonusMultiplier(int, int);
    int randomNumGen(int); //generates a random number
    //int searchList();  //Search card deck for player's guess
    void playerGuess(int, int);  //Feed in player guess and call searchList()
    int accountBalance;

private: //Declaring private variables for the JumblePuzzle class
    int bet;
    int score;
    int countWin; //Number of wins in a row for bonus multiplier
    int totalWin; //Overall wins, doesnt count wins in a row, just total number
    string guess;
    Card cards[];
    Card cardGuess; //Players guess converted to a Card object
};

#endif //TEAM_23_MONTREAL_ODDS_ARE_H
