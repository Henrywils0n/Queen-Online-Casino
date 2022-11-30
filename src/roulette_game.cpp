// ROULETTE IMPLEMENTATION FILE
// for american roulette (including double 0)

#include "roulette.h"
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
// FRAMEWORK METHODS
	// roulette buttons
		// outside bets
void RouletteFrame :: OnBetDoubleZero(wxCommandEvent event) {
}
void RouletteFrame :: OnBetZero(wxCommand &event) {
}
void RouletteFrame :: OnBetLoThird(wxCommand &event) {
}
void RouletteFrame :: OnBetMidThird(wxCommand &event) {
}
void RouletteFrame :: OnBetHiThird(wxCommand &event {
}
void RouletteFrame :: OnBetLoHalf(wxCommand &event) {
}
void RouletteFrame :: OnBetHiHalf(wxCommand &event) {
}
void RouletteFrame :: OnBetEven(wxCommand &event) {
}
void RouletteFrame :: OnBetOdd(wxCommand &event) {
}
void RouletteFrame :: OnBetRed(wxCommand &event) {
}
void RouletteFrame :: OnBetBlack(wxCommand &event) {
}
void RouletteFrame :: OnBetColumnOne(wxCommand &event) {
}
void RouletteFrame :: OnBetColumnTwo(wxCommand &event) {
}
void RouletteFrame :: OnBetColumnThree(wxCommand &event) {
}
void RouletteFrame :: OnBetStreet1(wxCommand &event) {
}
void RouletteFrame :: OnBetStreet4(wxCommand &event) {
}
void RouletteFrame :: OnBetStreet7(wxCommand &event) {
}
void RouletteFrame :: OnBetStreet10(wxCommand &event) {
}
void RouletteFrame :: OnBetStreet13(wxCommand &event) {
}
void RouletteFrame :: OnBetStreet16(wxCommand &event) { 
}
void RouletteFrame :: OnBetStreet19(wxCommand &event) {
}
void RouletteFrame :: OnBetStreet22(wxCommand &event) {
}
void RouletteFrame :: OnBetStreet25(wxCommand &event) {
}
void RouletteFrame :: OnBetStreet28(wxCommand &event) {
}
void RouletteFrame :: OnBetStreet31(wxCommand &event) {
}
void RouletteFrame :: OnBetStreet34(wxCommand &event) {
}

		// inside bets
void RouletteFrame :: OnBet1(wxCommand &event) {
}
void RouletteFrame :: OnBet2(wxCommand &event) {
}
void RouletteFrame :: OnBet3(wxCommand &event) {
}
void RouletteFrame :: OnBet4(wxCommand &event) {
}
void RouletteFrame :: OnBet5(wxCommand &event) {
}
void RouletteFrame :: OnBet6(wxCommand &event) {
}
void RouletteFrame :: OnBet7(wxCommand &event) {
}
void RouletteFrame :: OnBet8(wxCommand &event) {
}
void RouletteFrame :: OnBet9(wxCommand &event) {
}
void RouletteFrame :: OnBet10(wxCommand &event) {
}
void RouletteFrame :: OnBet11(wxCommand &event) {
}
void RouletteFrame :: OnBet12(wxCommand &event) {
}
void RouletteFrame :: OnBet13(wxCommand &event) {
}
void RouletteFrame :: OnBet14(wxCommand &event) {
}
void RouletteFrame :: OnBet15(wxCommand &event) {
}
void RouletteFrame :: OnBet16(wxCommand &event) {
}
void RouletteFrame :: OnBet17(wxCommand &event) {
}
void RouletteFrame :: OnBet18(wxCommand &event) {
}
void RouletteFrame :: OnBet19(wxCommand &event) {
}
void RouletteFrame :: OnBet20(wxCommand &event) {
}
void RouletteFrame :: OnBet21(wxCommand &event) {
}
void RouletteFrame :: OnBet22(wxCommand &event) {
}
void RouletteFrame :: OnBet23(wxCommand &event) {
}
void RouletteFrame :: OnBet24(wxCommand &event) {
}
void RouletteFrame :: OnBet25(wxCommand &event) {
}
void RouletteFrame :: OnBet26(wxCommand &event) {
}
void RouletteFrame :: OnBet27(wxCommand &event) {
}
void RouletteFrame :: OnBet28(wxCommand &event) {
}
void RouletteFrame :: OnBet29(wxCommand &event) {
}
void RouletteFrame :: OnBet30(wxCommand &event) {
}
void RouletteFrame :: OnBet31(wxCommand &event) {
}
void RouletteFrame :: OnBet32(wxCommand &event) {
}
void RouletteFrame :: OnBet33(wxCommand &event) {
}
void RouletteFrame :: OnBet34(wxCommand &event) {
}
void RouletteFrame :: OnBet35(wxCommand &event) {
}
void RouletteFrame :: OnBet36(wxCommand &event) {
}
	// functional buttons
void RouletteFrame :: OnSubmitBet(wxCommand &event) {
}
void RouletteFrame :: OnSpinWheel(wxCommand &event) {
}
void RouletteFrame :: OnInformation(wxCommand &event) {
}
void RouletteFrame :: OnPlayAgain(wxCommand &event) {
}
void RouletteFrame :: OnExit(wxCommand &event) {
}
	

// GAME METHODS
	// RoulettController
void RouletteController :: storeBets(string "bet_type", int money_bet) {
	switch ("bet_type") {
		case "street1":
			newBet = Bet(threeNM, money_bet, street1);
			break;
		case "street4":
			newBet = Bet(threeNM, money_bet, street4);
			break;
		case "street7":
			newBet = Bet(threeNM, money_bet, street7);
			break;
		case "street10":
			newBet = Bet(threeNM, money_bet, street10);
			break;
		case "street13":
			newBet = Bet(threeNM, money_bet, street13);
			break;
		case "street16":
			newBet = Bet(threeNM, money_bet, street16);
			break;
		case "street19":
			newBet = Bet(threeNM, money_bet, street19);
			break;
		case "street22":
			newBet = Bet(threeNM, money_bet, street22);
			break;
		case "street25":
			newBet = Bet(threeNM, money_bet, street25);
			break;
		case "street28":
			newBet = Bet(threeNM, money_bet, street28);
			break;
		case "street31":
			newBet = Bet(threeNM, money_bet, street31);
			break;
		case "street34":
			newBet = Bet(threeNM, money_bet, street34);
			break;
		case "loHalf":
			newBet = Bet(halfM, money_bet, loHalf);
			break;
		case "hiHalf":
			newBet = Bet(halfM, money_bet, hiHalf);
			break;
		case "loThird":
			newBet = Bet(thirdM, money_bet, loThird);
			break;
		case "midThird":
			newBet = Bet(thirdM, money_bet, midThird);
			break;
		case "hiThird":
			newBet = Bet(thirdM, money_bet, hiThird);
			break;
		case "odd":
			newBet = Bet(oeM, money_bet, odd);
			break;
		case "even":
			newBet = Bet(oeM, money_bet, even);
			break;
		case "col1":
			newBet = Bet(colM, money_bet, col1);
			break;
		case "col2":
			newBet = Bet(colM, money_bet, col2);
			break;
		case "col3":
			newBet = Bet(colM, money_bet, col3);
			break;
		case "red":
			newBet = Bet(colourM, money_bet, red);
			break;
		case "black":
			newBet = Bet(colourM, money_bet, black);
			break;
		case "zero":
			newBet = Bet(oneNM, money_bet, zero);
			break;
		case "doubleZero":
			newBet = Bet(oneNM, money_bet, doubleZero);
			break;
		// single numbers
		default:
			newBet = Bet(colourM, money_bet, bet_type);
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
	int num = RoulettController.getRolledNumber();
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