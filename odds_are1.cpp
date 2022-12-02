#include <iostream>
#include "odds_are1.h"
using namespace  std;

BadUserInput::BadUserInput(const string& message) : message(message) {}
string& BadUserInput::what() {
    return message;
}

OddsAre::OddsAre(int accountBalance){
    //numGen(accountBalance); //Calls first function to get input regarding game
    accountBalance = accountBalance;
    int topRange = 0;  //Player guesses a number between 0 and topRange
    int bet = 0;
    int guess = 0;
}

//Plays the game
int OddsAre::playGame(int accountBalance, int topRange, int guess, int bet){

    if (topRange == 1 || topRange == 0) {
        throw BadUserInput("Please enter a number greater than one and zero.");
    }
    if (cin.fail()) {
        throw BadUserInput("Please enter a valid number.");
    }
// generates a random number between 1 and the upper bound.
    int ans = rand()%topRange + 1;
//asks users to guess a number
    int win = 0;
    if (guess > topRange || guess < 0){
        throw BadUserInput("Invalid Input");
    }else{
        if(ans == guess){
            win++;
            cout << "You win! \n";
            bonusMultiplier(win, bet, accountBalance, topRange);
        }else{
            win = 0;
            cout << "You lost! \n";
            bonusMultiplier(win, bet, accountBalance, topRange);
        }
    }
}
//Calculate the score
int OddsAre::bonusMultiplier(int countWin, int bet, int accountBalance, int topRange){
    int bonusAmount;
    int updateBalance;
    if(countWin >= 1){
        if(topRange == 2){
            bonusAmount = 2 * countWin;
            updateBalance = bonusAmount * bet;
            accountBalance = updateBalance + accountBalance;
        }else if(2 < topRange < 5){
            bonusAmount = 5 * countWin;
            updateBalance = bonusAmount * bet;
            accountBalance = updateBalance + accountBalance;
        }else if(5 < topRange < 10){
            bonusAmount = 7 * countWin;
            updateBalance = bonusAmount * bet;
            accountBalance = updateBalance + accountBalance;
        }else if(10 < topRange){
            bonusAmount = 10 * countWin;
            updateBalance = bonusAmount * bet;
            accountBalance = updateBalance + accountBalance;
        }else{
            ;
        }
    }else{
        bonusAmount = 1 * countWin;
        accountBalance = accountBalance - bet;
    }
    cout << "Your updated account balance: " << accountBalance;
    return updateBalance; //Player's credit balance after the game (shows if they won or lost)
}

//Just put here for testing through the terminal, delete later
int main(){
    OddsAre(100); //Setting account balance to 100 for testing
    return 0;
}