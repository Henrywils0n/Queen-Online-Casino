//
// Created by Cam Overvelde on 2022-11-29.
//

#include "Blackjack.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

Card::Card(rank r, suit s, bool ifu): Rank(r), Suit(s), facedUp(ifu)
{}

int Card::getValue() const{
    //0 if card is not faced up
    int value = 0;
    if (facedUp) {
        value = Rank;
        //jack, queen, and king are = 10
        if (value > 10)
            value = 10;
    }
    return value;
}

string Card::getRank() const{
    switch (this->Rank){
        case rank::ACE: return "Ace";
        case rank::TWO: return "Two";
        case rank::THREE: return "Three";
        case rank::FOUR: return "Four";
        case rank::FIVE: return "Five";
        case rank::SIX: return "Six";
        case rank::SEVEN: return "Seven";
        case rank::EIGHT: return "Eight";
        case rank::NINE: return "Nine";
        case rank::TEN: return "Ten";
        case rank::JACK: return "Jack";
        case rank::QUEEN: return "Queen";
        case rank::KING: return "King";
    }
}

string Card::getSuit() const{
    switch (this->Suit){
        case suit::CLUBS: return "Clubs";
        case suit::DIAMONDS: return "Diamonds";
        case suit::SPADES: return "Spades";
        case suit::HEARTS: return "Hearts";
    }
}

void Card::flip(){
    facedUp = !(facedUp);
}

Deck::Deck()
{
    deck.reserve(52);
    init();
}

void newDeck(){

}

void Deck::init(){
    newDeck();
        for (int i = Card::CLUBS; i <= Card::SPADES; ++i)
            for (int j = Card::ACE; j <= Card::KING; ++j)
                Add (new Card(static_cast<Card::rank>(i), static_cast<Card::suit>(j)));
}

void Deck::shuffle()
{
    random_shuffle(deck.begin(), deck.end());
}

void Deck::Deal(Hand h)
{
    if (!deck.empty())
    {
        h.Add(deck.back());
        deck.pop_back();
    }
    else
    {

    }
}



