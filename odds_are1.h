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
    int playGame(int, int, int, int);
    
    int accountBalance;

private: 
    int bonusMultiplier(int, int, int, int);
    
    int bet;
    int guess;
    int topRange;
    
};

#endif //TEAM_23_MONTREAL_ODDS_ARE_H
