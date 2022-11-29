#pragma once
#include "frame.h"

class Game {
public:
  Game();
  ~Game();
  
  wxFrame* menuFrame;
  wxFrame* rouletteFrame;
  wxFrame* blackjackFrame;
  wxFrame* oddsAreFrame;
  
  void setBalance(int val);
  int  getBalance();
  
  void playRoutlette();
  void playBlackjack();
  void playOddsAre();
  void returnToMenu();
  
private:
  int balance;
};
