#include "../include/oddsare.h"
#include <time.h>

using namespace  std;

BadUserInput::BadUserInput(const string& message) : message(message) {}
string& BadUserInput::what() {
  return message;
}

OddsAre::OddsAre(int accountBalance) {
  //numGen(accountBalance); //Calls first function to get input regarding game
  srand(time(NULL));
  balance = accountBalance;
  win = 0;
}

//Plays the game (return 0 if won, 1 if lost)
int OddsAre::playGame(int topRange_in, int guess_in, int bet_in) {
  if (topRange_in <= 1) {
    throw BadUserInput("Please enter a number greater than one.");
  }
  
  // generates a random number between 1 and the upper bound.
  int ans = rand()%topRange_in + 1;

  if (guess_in > topRange_in || guess_in < 0) {
    throw BadUserInput("Input out of range.");
  }
  else {
    if(ans == guess_in) {
      win++;
      return bonusMultiplier(win, bet_in, topRange_in);
    }
    else {
      win = 0;
      return bonusMultiplier(win, bet_in, topRange_in);
    }
  }
}
//Calculate the score
int OddsAre::bonusMultiplier(int countWin, int bet, int topRange_in) {
  int bonusAmount = 1;
  
  // If the user has won, they get a bonus.
  if (countWin >= 1) {
    if (topRange_in == 2) {
      bonusAmount = 2 * countWin;
    }
    else if (2 < topRange_in && topRange_in < 5) {
      bonusAmount = 5 * countWin;
    }
    else if (5 < topRange_in && topRange_in < 10) {
      bonusAmount = 7 * countWin;
    }
    else {
      bonusAmount = 10 * countWin;
    }
  }
  else {
    bonusAmount = -1;
  }
  return bonusAmount * bet; // Difference in player's balance.
}
