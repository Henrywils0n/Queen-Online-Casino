
#include <iostream>
using namespace  std;

//Asks user how many cards they want to guess, returns number
int cardNumGen(){
    int cardsToGuess;
    cout << "How many card would you like to guess?"; 
    cin >> cardsToGuess;
    //create cardsToGuess number of Card objects and add to a list
    Card cards[cardsToGuess]; 
    return cards;
}

//Calculate how many points the player has earned based on how many wins they have
//totalWin
int pointsEarned(int totalWin){
    //Take countwin value and multiple by base score, each correct guess = 10 points?
    int score = totalWin * 10;
    return score;
}

//If player has multiple wins in a row, multiply their score by the bonus points 
//and return final score.
int bonusMultiplier(int countWin, int score) {
    int bonusAmount;
    if (countWin == 1) {
        bonusAmount = 2 * score;
    } else if (countWin == 2) {
        bonusAmount = 4 * score;
    } else if (countWin > 2) {
        bonusAmount = 10 * score;
    } else {
        bonusAmount = 1 * score;
    }
    return bonusAmount;
}

int randomNumGen(int cardRange) {
    int ans;
    ans = rand()%cardRange + 1;
    return ans;
} //generates a random number


int searchList(Card cards[], Card ans) {
    for (int i =0; i< sizeof(cards); i++){   //Loop through list of cards 
        if (cards[i]==ans){                  //If current card is same as the guess, return the card
            cout << "Card is in the deck!";
            return ans;
        }else {
            return 0;
            cout << "Not found in deck!";
        } 
    }
}

void playerGuess(Card cards){
    cout << "Guess a card";
    cin >> guess;
    Card cardGuess = guess;
    searchList(cards, cardGuess);
}