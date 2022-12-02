//
// Created by Cam Overvelde on 2022-11-29.
//

#ifndef TEAM_23_MONTREAL_BLACKJACK_H
#define TEAM_23_MONTREAL_BLACKJACK_H

#include "header.h"
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
    Card(rank r, suit s);
    int getValue() const;
    string getSuit() const;
    string getRank() const;
    void flip();

    friend ostream& operator << (ostream& os, const Card& card);

    // TODO: Replace this
    /**
     * Insertion overloading is not working with wxString and I do not have time
     * to figure out why
     */
    string toString();
private:
    rank Rank;
    suit Suit;
    bool facedUp;

    //friend ostream& operator << (ostream& os, const Card& card);
};

class Hand{
public:
    Hand();
    virtual ~Hand();
    void addCard(Card* c);
    void clear();
    int sumOfHand() const;

    /**
     * Legacy 
     */
    vector<Card*> getCards();

    /**
     * Of course I do not want this to be public but the memory access is more work
     * then its worth
     */
    vector<Card*> cards;
protected:
};


class GenericParticipant : public Hand{
    friend ostream& operator << (ostream& os, const GenericParticipant& participant);
public:
    GenericParticipant();
    virtual ~GenericParticipant();
    virtual bool isHitting() const = 0; //indicates if player wants to keep hitting
    bool isBusted() const; //if total >21, isBusted = true
    void bust() const;
protected:
    string m_name;
};

class Deck : public Hand {
public:
    Deck();
    virtual ~Deck();
    void init();
    void shuffle();
    void deal(Hand& hand); //deal one card
    void anotherCard(GenericParticipant& participant); //give additional cards
};

class Dealer : public GenericParticipant{
public:
    Dealer();
    Dealer(const string& name = "Dealer");
    ~Dealer();
    virtual bool isHitting() const;
    void flipCard();
};

class Player : public GenericParticipant{
public:
    Player();
    Player(const string& name = "");
    ~Player();
    virtual bool isHitting() const;
    void win();
    void lose();
    void push();
    void placeBet(int b);
    void setBalance(int amount);
private:
    int bet;
    int balance;
};

class BlackjackGame {
public:
    BlackjackGame(const vector<string>& names);
    BlackjackGame();
    ~BlackjackGame();
    void Play();

    // Temp public
    Deck* game_deck;
    Dealer* game_dealer;
    Player* game_players;

private:

};

class Chip{
private:
    int value;
public:
    Chip(int val);
    int getValue();
};

class MinimumBetException {
public:
    MinimumBetException(const string& message);
    string& what();
private:
    string message;
};

// maximum bet exception
// when player provides excessive funds for maximum bet requirement
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


#endif //TEAM_23_MONTREAL_BLACKJACK_H
