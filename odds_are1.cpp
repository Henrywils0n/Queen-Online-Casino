#include <iostream>
#include <odds_are1.h>
using namespace  std;

void BadUserInput::BadUserInput(const string& prompt){
    message = prompt
}
string& BadUserInput::what(){
    return message;
}

void OddsAre(int accountBalance){
    accountBalance = accountBalance;
    cardNumGen();
    playerGuess();
    pointsEarned();

}

//Asks user how many cards they want to guess, returns number
int OddsAre::numGen(){
    int cardsToGuess;
    cout << "How much would you like to bet"
    cin >> bet;
    if( bet > accountBalance){
        throw BadUserInput ("Invalid bet amount");
    }
    cout << "How many numbers would you like to guess from?"; 
    cin >> numsToGuess;
    //create cardsToGuess number of Card objects and add to a list
    randomNumGen(numsToGuess);
}

//If player has multiple wins in a row, multiply their score by the bonus points 
//and return final score.
int OddsAre::bonusMultiplier(int countWin, int bet) {
    int bonusAmount;
    int updateBet;
    if (countWin == 1) {
        bonusAmount = 2 * countWin;
        updateBet = bonusAmount * bet;
    } else if (countWin == 2) {
        bonusAmount = 4 * countWin;
        updateBet = bonusAmount * bet;
    } else if (countWin > 2) {
        bonusAmount = 10 * countWin;
        updateBet = bonusAmount * bet;
    } else {
        bonusAmount = 1 * countWin;
        updateBet = balanceAmount - bet;
        
    }
    return updateBet;
}

void OddsAre::randomNumGen(int numsToGuess) {
    int ans;
    ans = rand()%cardRange + 1;
    playerGuess(ans, numsToGuess);
    //return ans;
} //generates a random number

void OddsAre::playerGuess(int ans, int numsToGuess){
    cout << "Guess a number within the range";
    cin >> guess;
    if (guess > numsToGuess || guess < numsToGuess){
        throw BadUserInput("Invalid Input");
    }else{
        if(ans == guess){
            int win += 1;
            bonusMultiplier(win);
        }else{
            bonusMultiplier(0);
            
        }
    }
}