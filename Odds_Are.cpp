
#include <iostream>
#include <odds_are.h>
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
int OddsAre::cardNumGen(){
    int cardsToGuess;
    cout << "How many card would you like to guess from?"; 
    cin >> cardsToGuess;
    //create cardsToGuess number of Card objects and add to a list
    Card cards[cardsToGuess]; 
    return cards;
}

//Calculate how many points the player has earned based on how many wins they have
//totalWin
// int OddsAre::pointsEarned(int totalWin){
//     //Take countwin value and multiple by base score, each correct guess = 10 points?
//     int score = totalWin * 10;
//     return score;
// }

//If player has multiple wins in a row, multiply their score by the bonus points 
//and return final score.
int OddsAre::bonusMultiplier(int countWin, int score) {
    int bonusAmount;
    if (countWin == 1) {
        bonusAmount = 2 * countWin;
    } else if (countWin == 2) {
        bonusAmount = 4 * score;
    } else if (countWin > 2) {
        bonusAmount = 10 * score;
    } else {
        bonusAmount = 1 * score;
    }
    return bonusAmount;
}

int OddsAre::randomNumGen(int cardRange) {
    int ans;
    ans = rand()%cardRange + 1;
    return ans;
} //generates a random number


int OddsAre::searchList(Card cards[], Card ans) {
    for (int i =0; i< sizeof(cards); i++){   //Loop through list of cards 
        if (cards[i]==ans){                  //If current card is same as the guess, return the card
            cout << "Card is in the deck!";
            return ans;
        }else {
            cout << "Not found in deck!";
            return 0;
        } 
    }
}

void OddsAre::playerGuess(Card cards){
    cout << "Guess a card";
    cin >> guess;
    Card cardGuess = guess;
    searchList(cards, cardGuess);
}
