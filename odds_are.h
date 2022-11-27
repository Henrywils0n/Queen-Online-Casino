#ifndef TEAM_23_MONTREAL_ODDS_ARE_H
#define TEAM_23_MONTREAL_ODDS_ARE_H

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
    int cardNumGen();
    int bonusMultiplier();
    int randomCardGen(); //Should return a card (but we do not have the card class yet)
    int randomNumGen(); //generates a random number
    int pointsEarned();
    int searchList();  //Search card deck for player's guess
    void playerGuess();  //Feed in player guess and call searchList()

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
