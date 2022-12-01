// ROULETTE IMPLEMENTATION FILE
// for american roulette (including double 0)

#include "roullette_game.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// constructors
	// Bet
Bet :: Bet() mul(0) numbersBet(0) moneyBet(0) { };
Bet :: Bet(int  multiplier, int money_bet, vector<int> numbers_bet) mul(multiplier) moneyBet(money_bet) numbersBet(numbers_bet) { };

// accessors
	// RouletteController
int RouletteController :: multiplier() const { return mul; }
int RouletteController :: numbersBet() const { return numbersBet[]; }
int RouletteController :: moneyBet() const { return moneyBet[]; }
int RouletteController :: getRolledNumber() const { return rolledNumber; }

	// Chips
int Chips :: currentChipTotal() const { return chipTotal; }
	
// functions
// FRAMEWORK METHODS have been moved to roulettepanel.cpp
	// roulette buttons
		// outside bets

	

// GAME METHODS
	// RoulettController
void RouletteController :: storeBets(string "bet_type", int money_bet) {
	switch ("bet_type") {
		case "street1":
			newBet = Bet(threeNM, money_bet, street1);
            placedBets.pushback(newBet);
			break;
		case "street4":
			newBet = Bet(threeNM, money_bet, street4);
            placedBets.pushback(newBet);
			break;
		case "street7":
			newBet = Bet(threeNM, money_bet, street7);
            placedBets.pushback(newBet);
			break;
		case "street10":
			newBet = Bet(threeNM, money_bet, street10);
            placedBets.pushback(newBet);
			break;
		case "street13":
			newBet = Bet(threeNM, money_bet, street13);
            placedBets.pushback(newBet);
			break;
		case "street16":
			newBet = Bet(threeNM, money_bet, street16);
            placedBets.pushback(newBet);
			break;
		case "street19":
			newBet = Bet(threeNM, money_bet, street19);
            placedBets.pushback(newBet);
			break;
		case "street22":
			newBet = Bet(threeNM, money_bet, street22);
            placedBets.pushback(newBet);
			break;
		case "street25":
			newBet = Bet(threeNM, money_bet, street25);
            placedBets.pushback(newBet);
			break;
		case "street28":
			newBet = Bet(threeNM, money_bet, street28);
            placedBets.pushback(newBet);
			break;
		case "street31":
			newBet = Bet(threeNM, money_bet, street31);
            placedBets.pushback(newBet);
			break;
		case "street34":
			newBet = Bet(threeNM, money_bet, street34);
            placedBets.pushback(newBet);
			break;
		case "loHalf":
			newBet = Bet(halfM, money_bet, loHalf);
            placedBets.pushback(newBet);
			break;
		case "hiHalf":
			newBet = Bet(halfM, money_bet, hiHalf);
            placedBets.pushback(newBet);
			break;
		case "loThird":
			newBet = Bet(thirdM, money_bet, loThird);
            placedBets.pushback(newBet);
			break;
		case "midThird":
			newBet = Bet(thirdM, money_bet, midThird);
            placedBets.pushback(newBet);
			break;
		case "hiThird":
			newBet = Bet(thirdM, money_bet, hiThird);
            placedBets.pushback(newBet);
			break;
		case "odd":
			newBet = Bet(oeM, money_bet, odd);
            placedBets.pushback(newBet);
			break;
		case "even":
			newBet = Bet(oeM, money_bet, even);
            placedBets.pushback(newBet);
			break;
		case "col1":
			newBet = Bet(colM, money_bet, col1);
            placedBets.pushback(newBet);
			break;
		case "col2":
			newBet = Bet(colM, money_bet, col2);
            placedBets.pushback(newBet);
			break;
		case "col3":
			newBet = Bet(colM, money_bet, col3);
            placedBets.pushback(newBet);
			break;
		case "red":
			newBet = Bet(colourM, money_bet, red);
            placedBets.pushback(newBet);
			break;
		case "black":
			newBet = Bet(colourM, money_bet, black);
            placedBets.pushback(newBet);
			break;
		case "zero":
			newBet = Bet(oneNM, money_bet, zero);
            placedBets.pushback(newBet);
			break;
		case "doubleZero":
			newBet = Bet(oneNM, money_bet, doubleZero);
            placedBets.pushback(newBet);
			break;
		// single numbers
		default:
			newBet = Bet(colourM, money_bet, bet_type);
            placedBets.pushback(newBet);
			break;
	}
	placedBets.add(newBet);
	return;
}

void RouletteController :: spinBall() {
	// modulo 37 where 37 is double 0
	rolledNumber = rand() % 37;
	return;
}

void RouletteController :: ballOnWheel() {
	int num = RouletteController.getRolledNumber();
	switch (num) {
		case 0:
			break;
		case 1:
			// insert code for positioning ball on wheel
			// or put code after cases 
			break;
		case 2:
			break;
		case 3:
			break;
		case 4: 
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
		case 14:
			break;
		case 15:
			break;
		case 16:
			break;
		case 17:
			break;
		case 18:
			break;
		case 19:
			break;
		case 20:
			break;
		case 21:
			break;
		case 22:
			break;
		case 23:
			break;
		case 24:
			break;
		case 25:
			break;
		case 26:
			break;
		case 27:
			break;
		case 28:
			break;
		case 29:
			break;
		case 30:
			break;
		case 31:
			break;
		case 32:
			break;
		case 33:
			break;
		case 34:
			break;
		case 35:
			break;
		case 36:
			break;
		default: // case 37 (00)
			break;
	}
	
	return;
}

void RouletteController :: checkBets (vector<Bet> placedBets) {
	int numBetsHit = 0;
	int newFunds = 0;
	for (int j; j < placedBets.size; j++) {
		currentBet = placedBets.back;
		for (int k; k < currentBet.length; k++) {
			// current bet has hit
			if (rolledNumber == currentBet[k]) {
				funds += currentBet.mul * currntBet.moneyBet;
				newFunds += currentBet.mul * currentBet.moneyBet;
				numBetsHit += 1;
			}
			// current bet has not hit
			else {
				continue;
			}
		}
		placedBets.remove(placedBets.back);
	}
	cout << "You have hit " << numBetsHit << " bets!" << endl;
	cout << "You have won $" << newFunds << "this round!" << endl;
	return;
}
		
	// Chips
		// really just remove specified amount of funds
		// when player places bets and places a chip on the square
		// player will type the amount of money they would like to
		// bet
void Chips :: removeChips() {
	int money_bet;
	// cin cout will not work since they are terminal base comands
	// text box that gets typed into will send this information to
	// removeChips() instead
	cout << "Enter bet amount: " << endl;
	cin.clear();
	cin >> money_bet;
	if (money_bet <= user.funds) {
		throw InsufficientFundsException("\nYou do not have enough money to place this bet");
	}
	else if (money_bet <= minBet){
		throw MinimumBetException("\nThis bet does not satisfy the minimum bet requirement");
	}
	else if (money_bet >= maxBet) {
		throw MaximumBetException("\nThis bet does not exceeds the maximum bet limit");
	}
	moneyBet = money_bet;
	user.funds -= moneyBet;
	cout << "Bet of $" << moneyBet << " has been placed, good luck!" << endl;
}
	
	// MinimumBetException
MinimumBetException :: MinimumBetException (const string& message) : message(message) {}
string& MinimumBetException :: what() {return message; }
	
	// MaximumBetException
MaximumBetException :: MaximumBetException (const string& message) : message(message) {}
string& MaximumBetException :: what() {return message; }
	
	// InsufficientFundsException
InsufficientFundsException :: InsufficientFundsException (const string& message) : message(message) {}
string& InsufficientFundsException :: what() {return message; }