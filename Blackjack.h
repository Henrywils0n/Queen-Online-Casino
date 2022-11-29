//
// Created by Cam Overvelde on 2022-11-29.
//

#ifndef TEAM_23_MONTREAL_BLACKJACK_H
#define TEAM_23_MONTREAL_BLACKJACK_H

#include <vector>
#include <string>
#include <iostream>
#pragma once
using namespace std;


class Suit {
private:
    string name;
    Suit(string nameValue);
public:
    const static Suit CLUBS = new Suit("Clubs");
    const static Suit DIAMONDS = new Suit("Diamonds");
    const static Suit HEARTS = new Suit("Hearts");
    const static Suit SPADES = new Suit("Spades");
    string getName();
};

class Rank{
private:
    string name;
    Rank(string nameValue);
public:
    const static Rank ACE = new Rank("Ace");
    const static Rank TWO = new Rank("Two");
    const static Rank THREE = new Rank("Three");
    const static Rank FOUR = new Rank("Four");
    const static Rank FIVE = new Rank("Five");
    const static Rank SIX = new Rank("Six");
    const static Rank SEVEN = new Rank("Seven");
    const static Rank EIGHT = new Rank("Eight");
    const static Rank NINE = new Rank("Nine");
    const static Rank TEN = new Rank("Ten");
    const static Rank JACK = new Rank("Jack");
    const static Rank QUEEN = new Rank("Queen");
    const static Rank KING = new Rank("King");
    string getName();
};

class Chip{ //extends Button
private:
    int value;
    //include private image
public:
    Chip(int val);
    int getValue();
};

class Card{
private:
    Suit suit;
    Rank rank;
    int cardValue;
public:
    Card();
    Card(Suit suit, Rank rank);
    Suit getSuit();
    Rank getRank();
    int getValue();
    void setAceValue(int i);

};

class Blackjack{

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
