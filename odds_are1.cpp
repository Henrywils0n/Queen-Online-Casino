#include <iostream>
#include "odds_are1.h"
using namespace  std;

BadUserInput::BadUserInput(const string& message) : message(message) {}
string& BadUserInput::what() {
    return message;
}

OddsAre::OddsAre(int accountBalance){
    numGen(accountBalance); //Calls first function to get input regarding game
}
//Asks user how many cards they want to guess, returns number
int OddsAre::numGen(int accountBalance){
    int numsToGuess;
    int bet;
    cout << "Please enter your bet amount:";
    cin >> bet;
    if (bet > accountBalance){
        throw BadUserInput ("Invalid bet amount!");
    }
    else if (cin.fail()) {
        throw BadUserInput("Please enter a number!");
    }
    //Asks uses for number range
    cout << "Please enter how many numbers would you like to guess from: ";
    cin >> numsToGuess;
    if (numsToGuess == 1 || numsToGuess == 0) {
        throw BadUserInput("Please enter a number greater than one and zero.");
    }
    if (cin.fail()) {
        throw BadUserInput("Please enter a valid number.");
    }
    randomNumGen(numsToGuess, accountBalance, bet);
}

//function generates a random number between 1 and the upper bound.
void OddsAre::randomNumGen(int numsToGuess, int accountBal, int betAmt) {
    int ans;
    ans = rand()%numsToGuess + 1;
    playerGuess(ans, numsToGuess, accountBal, betAmt);
}

//function asks users to guess a number
void OddsAre::playerGuess(int ans, int numsToGuess, int accountBal, int betAmt){
    cout << "Guess a number within the range:";
    cin >> guess;
    int win = 0;
    if (guess > numsToGuess || guess < 0){
        throw BadUserInput("Invalid Input");
    }else{
        if(ans == guess){
            win++;
            cout << "You win! \n";
            bonusMultiplier(win, bet, accountBal, betAmt);
        }else{
            win = 0;
            cout << "You lost! \n";
            bonusMultiplier(win, bet, accountBal, betAmt);
        }
    }
}

//If player has multiple wins in a row, multiply their score by the bonus points 
//and return final score.
int OddsAre::bonusMultiplier(int countWin, int bet, int accountBal, int betAmt) {
    int bonusAmount;
    int updateBalance;
    if (countWin == 1) {
        bonusAmount = 2 * countWin;
        updateBalance = bonusAmount * betAmt;
        accountBal = updateBalance + accountBal;
    } else if (countWin == 2) {
        bonusAmount = 4 * countWin;
        updateBalance = bonusAmount * betAmt;
        accountBal = updateBalance + accountBal;
    } else if (countWin > 2) {
        bonusAmount = 10 * countWin;
        updateBalance = bonusAmount * betAmt;
        accountBal = updateBalance + accountBal;
    } else {
        bonusAmount = 1 * countWin;
        accountBal = accountBal - betAmt;
    }
    cout << "Your updated account balance: " << accountBal;
    return updateBalance; //Player's credit balance after the game (shows if they won or lost)
}

//Just put here for testing through the terminal, delete later
int main(){
    OddsAre(100); //Setting account balance to 100 for testing
    return 0;
}