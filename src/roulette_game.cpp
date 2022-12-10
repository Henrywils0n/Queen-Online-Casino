// ROULETTE IMPLEMENTATION FILE
// for american roulette (including double 0)
#pragma once
#include "../include/roullette_game.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// constructors
	// Bet
Bet :: Bet(): mul(0), numbersBet(0), moneyBet(0) { };
Bet :: Bet(int  multiplier, int money_bet, vector<int> numbers_bet): mul(multiplier), moneyBet(money_bet), numbersBet(numbers_bet) { };

// accessors
	// RouletteController
int RouletteController :: getRolledNumber() const { return rolledNumber; }

	// Chips
// int Chips :: currentChipTotal() const { return chipTotal; }
	
// functions
// FRAMEWORK METHODS have been moved to roulettepanel.cpp
	// roulette buttons
		// outside bets

	

// GAME METHODS
	// RoulettController
void RouletteController::storeBets(vector<int> betNumbers, int money_bet) {

	if (betNumbers.size() == 3){ 
		Bet newBet = Bet(12, money_bet, betNumbers);
        placedBets.push_back(newBet);
	} else if (betNumbers.size() == 18){
		Bet newBet = Bet(2, money_bet, betNumbers);
        placedBets.push_back(newBet);
	} else if (betNumbers.size() == 12){
		Bet newBet = Bet(3, money_bet, betNumbers);
        placedBets.push_back(newBet);
	} else if (betNumbers.size() == 1){
		Bet newBet = Bet(36, money_bet, betNumbers);
        placedBets.push_back(newBet);
	} else {
		Bet newBet = Bet(36, money_bet, betNumbers);
        placedBets.push_back(newBet);
	}
	
	return;
}

void RouletteController :: spinBall() {
	// modulo 37 where 37 is double 0
	rolledNumber = rand() % 37;
    
	return;
}

void RouletteController :: ballOnWheel() {
	int num =getRolledNumber();
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
		default:// case 37 (00)
			
			break;
	}
	
	return;
}

int RouletteController :: checkBets () {
	int numBetsHit = 0;
	int newFunds = 0;
	int k = 0;
    int totalBet = 0;
	for (Bet bet: placedBets) {
		k = 0;
		for (k; k < bet.numbersBet.size(); k++) {
			// current bet has hit
			if (rolledNumber == bet.numbersBet.at(k)) {
				newFunds += bet.mul * bet.moneyBet;
                totalBet += bet.moneyBet;
				numBetsHit += 1;
				break;
			}
		}
	}
    // gameframe.setBalance(balance + newFunds - totalBet); // not sure where to call set balance fromm or how to access user balance
	return newFunds;
}

		
	// Chips
		// really just remove specified amount of funds
		// when player places bets and places a chip on the square
		// player will type the amount of money they would like to
		// bet


// void Chips :: removeChips() {
// 	int money_bet;
// 	// cin cout will not work since they are terminal base comands
// 	// text box that gets typed into will send this information to
// 	// removeChips() instead
// 	cout << "Enter bet amount: " << endl;
// 	cin.clear();
// 	cin >> money_bet;
// 	if (money_bet <= user.funds) {
// 		throw InsufficientFundsException("\nYou do not have enough money to place this bet");
// 	}
// 	else if (money_bet <= minBet){
// 		throw MinimumBetException("\nThis bet does not satisfy the minimum bet requirement");
// 	}
// 	else if (money_bet >= maxBet) {
// 		throw MaximumBetException("\nThis bet does not exceeds the maximum bet limit");
// 	}
// 	moneyBet = money_bet;
// 	user.funds -= moneyBet;
// 	cout << "Bet of $" << moneyBet << " has been placed, good luck!" << endl;
// }
	
	// MinimumBetException
MinimumBetException :: MinimumBetException (const string& message) : message(message) {}
string& MinimumBetException :: what() {return message; }
	
	// MaximumBetException
MaximumBetException :: MaximumBetException (const string& message) : message(message) {}
string& MaximumBetException :: what() {return message; }
	
	// InsufficientFundsException
InsufficientFundsException :: InsufficientFundsException (const string& message) : message(message) {}
string& InsufficientFundsException :: what() {return message; }