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

class OddsAre {
public:
  OddsAre(int accountBalance);
  int playGame(int topRange_in, int guess_in, int bet_in);
    
private:
  int bonusMultiplier(int countWin, int bet, int topRange);
  int balance;
  int win;
};
