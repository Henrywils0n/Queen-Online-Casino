#pragma once
#include <string>

//Class to handle invalid user input
class BadUserInput {
public:
  BadUserInput(const std::string&);
  std::string& what();
private:
  std::string message;
};

//Odds Are class contains the content for the Odds Are casino game
class OddsAre {
public:
  OddsAre(int accountBalance);
  //playGame function contains the algorithm for the Odds Are casino game
  int playGame(int topRange_in, int guess_in, int bet_in);
    
private:
  //Bonus multiplier function to multiply winning by specific bonus amount
  int bonusMultiplier(int countWin, int bet, int topRange);

  // private fields for storing game variables
  int balance;
  int win;
};
