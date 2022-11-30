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
    friend ostream& operator << (ostream& os, const Card& aCard);
    void flip();
private:
    rank Rank;
    suit Suit;
    bool facedUp;
};


class Hand{
public:
    Hand();
    virtual ~Hand();
    void addCard(Card* c);
    void clear();
    int sumOfHand() const;
protected:
    vector<Card*> cards;
};


class GenericParticipant : public Hand{
    friend ostream& operator << (ostream& os, const GenericParticipant& participant);
public:
    GenericParticipant();
    virtual ~GenericParticipant();
    virtual bool isHitting() const = 0; //indicates if player wants to keep hitting
    bool isBusted() const; //if total >21, isBusted = true
    void bust() const;
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
    ~Dealer();
    virtual bool isHitting() const;
    void flipCard();
};

class Player : public GenericParticipant{
public:
    Player();
    ~Player();
    virtual bool isHitting() const;
    void win() const;
    void lose() const;
    void push() const;
};

class BlackjackGame {
public:
    BlackjackGame();
    ~BlackjackGame();
    void Play();
private:
    Deck game_deck;
    Dealer game_dealer;
    Player game_player;
};

//class Chip{ //extends Button
//private:
//    int value;
//    //include private image
//public:
//    Chip(int val);
//    int getValue();
//};

//class MinimumBetException {
//public:
//    MinimumBetException(const string& message);
//    string& what();
//private:
//    string message;
//}
//
//// maximum bet exception
//// when player provides excessive funds for maximum bet requirement
//class MaximumBetException {
//public:
//    MaximumBetException(const string& message);
//    string& what();
//private:
//    string message;
//}
//
//// insufficient funds exception
//// when player does not possess sufficient funds to play game
//class InsufficientFundsException {
//public:
//    InsufficientFundsException(const string& message);
//    string& what();
//private:
//    string message;
//}

#endif //TEAM_23_MONTREAL_BLACKJACK_H
