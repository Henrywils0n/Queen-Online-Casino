//
// Created by Cam Overvelde on 2022-11-29.
//

#ifndef TEAM_23_MONTREAL_BLACKJACK_H
#define TEAM_23_MONTREAL_BLACKJACK_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#pragma once
using namespace std;

class Card{
public:
    enum rank {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING};
    enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};
    Card(rank r, suit s, bool faceUp);
    int getValue() const;
    string getSuit() const;
    string getRank() const;
    void flip();
private:
    rank Rank;
    suit Suit;
    bool facedUp;
};

class Deck{
public:
    Deck();
    void init();
    void newDeck();
    void shuffle();
    void deal(Hand hand);
    void anotherCard(GenericParticipant participant);
private:
    vector <Card*> deck;
};

class Hand{
public:
    Hand();
    //virtual ~Hand();
    void addCard(Card* c);
    void newHand();
    int sumOfHand();
private:
    vector <Card*> hand;
};

class GenericParticipant{
public:
    GenericParticipant();
    virtual bool IsHitting() const = 0;
    bool IsBusted() const;
    void Bust() const;
};

class Dealer : public GenericParticipant{
public:
    Dearler();
    bool hit() const;
    void flipCard();
};

class Player : public GenericParticipant{
public:
    Player();
    bool hit() const;
    void win() const;
    void lose() const;
    void push() const;
};



class Chip{ //extends Button
private:
    int value;
    //include private image
public:
    Chip(int val);
    int getValue();
};

class Blackjack {
public:
    int winCheck(int playerHandSum, int dealerHandSum);
    int sumOfHand(Hand hand);
    void dealHand();
    void hit();
    void stand();
    int win();
    int lose();

private: //Declaring private variables for the JumblePuzzle class
    int bet;
    int score;
    int countWin; //Number of wins in a row for bonus multiplier
    int totalWin; //Overall wins, doesnt count wins in a row, just total number
    string guess;
    Card cards[];
    Card cardGuess; //Players guess converted to a Card object
};

class MinimumBetException {
public:
    MinimumBetException(const string& message);
    string& what();
private:
    string message;
}

// maximum bet exception
// when player provides excesive funds for maximum bet requirement
class MaximumBetException {
public:
    MaximumBetException(const string& message);
    string& what();
private:
    string message;
}

// insufficient funds exception
// when player does not possess sufficient funds to play game
class InsufficientFundsException {
public:
    InsufficientFundsException(const string& message);
    string& what();
private:
    string message;
}


#endif //TEAM_23_MONTREAL_BLACKJACK_H
