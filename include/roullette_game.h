// ROULETTE HEADER FILE
// for american roulette (includes double 0)
#pragma once
#include "imagepanel.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// FRAMEWORK CLASS has been moved to rolettepanel.h

		
// GAME CLASSES
class Table {
	public:
// gloabl variables

	int minBet = 10;
	int maxBet = 10000;
	
	// betting number combinations
		// inside bets 
			// includes straight and street. does not include split sixline, corner, trio, basket
			// https://www.roulettesites.org/rules/#:~:text=Basic%20Roulette%20Rules%201%20Place%20a%20bet%20on,winning%20number%20during%20any%20playing%20session.%20More%20items
	vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
	
			// street (variable name "streetX" where X denotes the first number in the street)
	vector<int> street1 = {1, 2, 3};
	vector<int> street4 = {4, 5, 6};
	vector<int> street7 = {7, 8, 9};
	vector<int> street10 = {10, 11, 12};
	vector<int> street13 = {13, 14, 15};
	vector<int> street16 = {16, 17, 18};
	vector<int> street19 = {19, 20, 21};
	vector<int> street22 = {22, 23, 24};
	vector<int> street25 = {25, 26, 27};
	vector<int> street28 = {28, 29, 30};
	vector<int> street31 = {31, 32, 33};
	vector<int> street34 = {34, 35, 36};
	
		// outside bets
			// 1 to 19 and 19 to 36
	vector<int> loHalf = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
	vector<int> hiHalf = {19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
	
			// 1 to 11, 12 to 23 and 24 to 36
	vector<int> loThird = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	vector<int> midThird = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
	vector<int> hiThird = {24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
	
			// odd and even
	vector<int> odd = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35};
	vector<int> even = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36};
	
			// column 1, column 2, column 3 (column number denotes first number in column)
	vector<int> col1 = {1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34};
	vector<int> col2 = {2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35};
	vector<int> col3 = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36};
	
			// red and black
	vector<int> red = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
	vector<int> black = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};
	
			// 0 and double 0
	vector<int> zero = {0};
			// 37 is used for 00 to be consistent with spinWheel() function
	vector<int> doubleZero = {37};
	
	// bet multipliers
	// https://www.casino.org/roulette/odds/
	// inside bets 
	// individual number

	// int oneNM = 35;
	// 		// street
	// int threeNM = 11;
		
	// 		// outside bets
	// int halfM = 1;
	// int oeM = 1;
	// int colourM = 1;
	// int colM = 2;
	// int thirdM = 2;
};

// structures
	// holds all bet information
	
		// a bet object will be created for each bet the player makes in a single betting session
		// EX. player bets $20 on even and $10 on numbers 1, and 19
		// 		bet objects will be created with the following fields: 
		//		for even bet: mul = 1, numbersBet[] = even[], moneyBet = 20
		//		for single num 1 bet: mul = 35, numbersBet[] = {1}, moneyBet = 10
		//		for single num 19 bet: nul = 35, numbersBet[] = {19}, moneyBet = 10
class Bet {
public:
	// constructor 
	Bet();
	Bet(int  multiplier, int money_bet, vector<int> numbers_bet);
	
	// fields
	int mul;
	vector<int> numbersBet;
	
	// money bet will be the cumulative total of tokens bet
	int moneyBet;
	
};

class RouletteController {
	public:
// fields 
	vector<Bet> placedBets;
	int rolledNumber;
	
// accessors
	// access fields of struct bet
	int multiplier() const;
	int numbersBet() const;
	int moneyBet() const;
	int getRolledNumber() const;
	
// functions
	// stores information for each individual bets in bet objects
		// would assign the information in the above structire EX.
	void storeBets(vector<int> betNumbers, int money_bet);
	
	// returns randomly generated number
	void spinBall();
	
	// determines at what number wheel will stop spinning at given random number
		// positions ball at that number 
	void ballOnWheel();
	
	// checks all bets to see if any hit
		// checks all bet objects numbersBet[] field to see if random number is found in any bets
	int checkBets();
};

// exceptions
	// minimum bet excpetion
		// when player does not provide sufficient funds to meet minimum bet requirement
class MinimumBetException {
	public:
		MinimumBetException(const string& message);
		string& what();
	private:
		string message;
};

	// maximum bet exception
		// when player provides excesive funds for maximum bet requirement
class MaximumBetException {
	public:
		MaximumBetException(const string& message);
		string& what();
	private:
		string message;
};

	// insufficient funds exception
		// when player does not possess sufficient funds to play game
class InsufficientFundsException {
	public:
		InsufficientFundsException(const string& message);
		string& what();
	private:
		string message;
};

