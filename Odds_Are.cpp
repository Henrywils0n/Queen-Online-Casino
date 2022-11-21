//
// Created by Matthew Mamelak on 2022-11-20.
//

int bonusMultiplier(countWin) {
    int bonusAmount;
    if (countWin == 1) {
        bonusAmount = 2;
    } else if (countWin == 2) {
        bonusAmount = 4;
    } else if (countWin > 2) {
        bonusAmount = 10;
    } else {
        bonusAmount = 1;
    }
    return bonusAmount;
}

int randomNumGen(cardRange) {
    int ans;
    ans = rand()%cardRange + 1;
    return ans;
} //generates a random number


int searchList(int arrayList[], int size, int ans) {
    for (int i =0; i<size; i++){
        if (arrayList[i]==ans){
            return ans;
        }
    } else {
        return "not found";
    }
}