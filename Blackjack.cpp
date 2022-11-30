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
    if (this->facedUp) {
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

//-----------------------------------------------------------------------------------------------------------

Deck::Deck()
{
    deck.reserve(52);
    init();
}

Deck::~Deck(){}

void Deck::init(){
    clear();
        for (int i = Card::CLUBS; i <= Card::SPADES; ++i)
            for (int j = Card::ACE; j <= Card::KING; ++j)
                Add (new Card(static_cast<Card::rank>(i), static_cast<Card::suit>(j)));
}

void Deck::shuffle()
{
    random_shuffle(deck.begin(), deck.end());
}

void Deck::Deal(Hand& h)
{
    if (deck.empty())
    {
        init();
    }
    h.Add(deck.back());
    deck.pop_back();
}

void Deck::anotherCard(GenericParticipant& participant)
{
    cout << endl;
    while (!(participant.isBusted()) && participant.isHitting())
    {
        Deal(participant);
        cout << participant << endl;

        if (participant.isBusted())
           participant.bust();
    }
}

//-----------------------------------------------------------------------------------------------------------
GenericParticipant::GenericParticipant(){}

GenericParticipant::~GenericParticipant(){}

bool GenericParticipant::isBusted() const {
    return (sumOfHand()>21);
}

void GenericParticipant::bust() const
{
    cout << "busted.\n";
}

//-----------------------------------------------------------------------------------------------------------
Hand::Hand()
{
    //largest possible hand in blackjack has 11 cards
    hand.reserve(11);
}

Hand::~Hand()
{
    clear();
}

void Hand::addCard(Card* card)
{
    hand.push_back(card);
}

void Hand::clear() {
    vector<Card*>::iterator iter = hand.begin();

    for (iter = hand.begin(); iter != hand.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    hand.clear();
}

int Hand::sumOfHand() const {
    if(hand.empty())
        return 0;
    //If first card has value of 0, then card is face down; return 0
    if(hand[0]->getValue() == 0)
        return 0;

    int total = 0;
    vector<Card*>::const_iterator iter;
    //treat each ace as a 1
    for(iter = hand.begin(); iter != hand.end(); ++iter)
        total += (*iter)->getValue();

    //now, check to see if ace should be 11
    bool containsAce = false;
    for (iter = hand.begin(); iter != hand.end(); ++iter)
        if ((*iter)->getValue() == Card::ACE)
    containsAce = true;

    //now check to see if total is less than 11
    if(containsAce && total <= 11)
        total +=10;

    return total;
}

//-----------------------------------------------------------------------------------------------------------
Blackjack::Blackjack(){
    this->player= new Player();
    this->dealer = new Dealer();
    srand(time(0));
    this->deck.init();
    this->deck.shuffle();
}

void Blackjack::Play() {
    //deal two cards to each person
    for (int i = 0; i < 2; i++) {
        deck.deal(*player);
        deck.deal(dealer);
    }
    dealer.flipCard(); //hide dealer's first card

    //display hands:
    //
    //

    //add cards while player is hitting
    while (player.hit()) {
        deck.addCard(*player);
    }

    //show dealer's first card
    dealer.flipCard();

    //add cards to dealer hand
    //
}


