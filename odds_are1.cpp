#include <iostream>
#include "odds_are1.h"
using namespace  std;

BadUserInput::BadUserInput(const string& message) : message(message) {}
    string& BadUserInput::what() { 
        return message; 
        }

OddsAre::OddsAre(int accountBalance){
    accountBalance = accountBalance;
    numGen(accountBalance); //Calls first function to get input regarding game
}

//Asks user how many cards they want to guess, returns number
int OddsAre::numGen(int accountBalance){
    int numsToGuess;
    int bet;
    cout << "How much would you like to bet ";
    cin >> bet;
    if( bet > accountBalance){
        throw BadUserInput ("Invalid bet amount");
    }
    cout << "How many numbers would you like to guess from? "; 
    cin >> numsToGuess;
    //create cardsToGuess number of Card objects and add to a list
    randomNumGen(numsToGuess);
}

void OddsAre::randomNumGen(int numsToGuess) {
    int ans;
    ans = rand()%numsToGuess + 1;
    playerGuess(ans, numsToGuess);
    //return ans;
} //generates a random number

void OddsAre::playerGuess(int ans, int numsToGuess){
    cout << "Guess a number within the range ";
    cin >> guess;
    int win = 0;
    if (guess > numsToGuess || guess < 0){
        throw BadUserInput("Invalid Input");
    }else{
        if(ans == guess){
            win++;
            cout << "You win! \n";
            bonusMultiplier(win, bet, accountBalance);
        }else{
            cout << "You lost! \n";
            bonusMultiplier(0, bet, accountBalance);
            
        }
    }
}

//If player has multiple wins in a row, multiply their score by the bonus points 
//and return final score.
int OddsAre::bonusMultiplier(int countWin, int bet, int balanceAmount) {
    int bonusAmount;
    int updateBalance;
    if (countWin == 1) {
        bonusAmount = 2 * countWin;
        updateBalance = bonusAmount * bet;
    } else if (countWin == 2) {
        bonusAmount = 4 * countWin;
        updateBalance = bonusAmount * bet;
    } else if (countWin > 2) {
        bonusAmount = 10 * countWin;
        updateBalance = bonusAmount * bet;
    } else {
        bonusAmount = 1 * countWin;
        updateBalance = balanceAmount - bet;
        
    }
    cout << "Your updated account balance: " << updateBalance;
    return updateBalance; //Player's credit balance after the game (shows if they won or lost)
}

//Just put here for testing through the terminal, delete later
int main(){
    OddsAre(100); //Setting account balance to 100 for testing
    return 0;
}