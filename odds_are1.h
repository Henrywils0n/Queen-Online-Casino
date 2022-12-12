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
//Odds Are class contains the content for the Odds Are casino game
class OddsAre {
public:
    OddsAre(int);
    //playGame function contains the algorithm for the Odds Are casino game
    int playGame(int, int, int, int);
    //the account balance is a public integer which is the total $ amount the user currently has
    int accountBalance;

private:
    //Bonus multiplier function to multiply winning by specific bonus amount
    int bonusMultiplier(int, int, int, int);
    
    int bet;
    int guess;
    int topRange;
    
};

#endif //TEAM_23_MONTREAL_ODDS_ARE_H
