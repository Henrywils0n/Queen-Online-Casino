
#include <iostream>
using namespace  std;

//Asks user how many cards they want to guess, returns number
int cardNumGen(){
    int cardsToGuess;
    cout << "How many card would you like to guess?"; 
    cin >> cardsToGuess;
    return cardsToGuess;
}

//Calculate how many points the player has earned based on how many wins they have
int pointsEarned(int countWin){
    //Take countwin value and multiple by base score, each correct guess = 10 points?
    int score = countWin * 10;
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


int searchList(int arrayList[], int size, int ans) {
    for (int i =0; i<size; i++){
        if (arrayList[i]==ans){
            return ans;
        }else {
            return "not found";
        } 
    }
}