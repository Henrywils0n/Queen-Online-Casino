#include "../include/rouletteframe.h"
#include "../include/oddsareframe.h"
#include "../include/blackjackframe.h"


Game::Game() {
  balance = 500;
  menuFrame = new MyFrame();
  rouletteFrame = new RouletteFrame();
  blackjackFrame = new BlackjackFrame();
  oddsAreFrame = new OddsAreFrame();
  menuFrame->Show(true);
};

Game::~Game() {
  menuFrame->Close(true);
}

void Game::setBalance(int val) {
  balance = val;
}
int  Game::getBalance() {
  return balance;
}

void Game::playRoutlette() {
  rouletteFrame->Show(true);
  menuFrame->Show(false);
}
void Game::playBlackjack() {
  blackjackFrame->Show(true);
  menuFrame->Show(false);
}
void Game::playOddsAre() {
  oddsAreFrame->Show(true);
  menuFrame->Show(false);
}

void Game::returnToMenu() {
  oddsAreFrame->Show(false);
  rouletteFrame->Show(false);
  blackjackFrame->Show(false);
  
  menuFrame->Show(true);
}
