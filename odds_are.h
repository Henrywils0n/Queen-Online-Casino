#ifndef TEAM_23_MONTREAL_ODDS_ARE_H
#define TEAM_23_MONTREAL_ODDS_ARE_H

#include <string>
using namespace std;

//Class to handle invalid user input
class BadUserInput {
public:
    BadJumbleException(const string&);
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
    int searchList();

private: //Declaring private variables for the JumblePuzzle class
    int bet;
    int score;
    int countWin;
    string playerGuess;
    int cardLayout[];
};

#endif //TEAM_23_MONTREAL_ODDS_ARE_H
