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

class Deck : public Hand{
public:
    Deck();
    void init();
    void shuffle();
    void deal(Hand& hand);
    void anotherCard(GenericParticipant& participant);
private:
    vector <Card*> deck;
};

class Hand{
public:
    Hand();
    //virtual ~Hand();
    void addCard(Card* c);
    void clear();
    int sumOfHand();
private:
    vector <Card*> hand;
};

class GenericParticipant : public Hand{
public:
    GenericParticipant();
    virtual bool isHitting() const = 0;
    bool isBusted() const;
    void Bust() const;
};

class Dealer : public GenericParticipant{
public:
    Dealer();
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

class Blackjack {
public:
    Blackjack();
    void Play();
private:
    Deck deck;
    Dealer dealer;
    Player player;
};

class Chip{ //extends Button
private:
    int value;
    //include private image
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
