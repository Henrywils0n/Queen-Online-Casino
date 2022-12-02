#include "../include/blackjack.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

Card::Card(rank r, suit s, bool ifu=true): Rank(r), Suit(s), facedUp(ifu){}
Card::Card(rank r, suit s) : Rank(r), Suit(s) { this->facedUp = true; }

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

string Card::toString() {
    string res;
    if (this->facedUp) {
        return this->getRank() + " of " + this->getSuit();
    }
    return "Face down card";
}

//ostream& operator<<(ostream& os, const Card& card) {
//   string res = card.getRank() + " of " + card.getSuit();
//    os << res;
//    return os;
//}

//-----------------------------------------------------------------------------------------------------------

Deck::Deck()
{
    cards.reserve(52);
    //init();
}

Deck::~Deck(){}

void Deck::init(){
    clear();
    for (int i = Card::CLUBS; i <= Card::SPADES; ++i) {
        for (int j = Card::ACE; j <= Card::KING; ++j) {
            Card* c = new Card(static_cast<Card::rank>(i), static_cast<Card::suit>(j), true);
            addCard(c);
            OutputDebugStringW(L"" + to_string(i) + " " + to_string(j) + "\n");
        }
    }
}

void Deck::shuffle()
{
    random_shuffle(cards.begin(), cards.end());
}

void Deck::deal(Hand& h)
{
    if (cards.empty())
    {
        init();
        wxLogError("Deck was empty");
    }
    h.addCard(cards.back());
    cards.pop_back();
}

void Deck::anotherCard(GenericParticipant& participant)
{
    cout << endl;
    while (!(participant.isBusted()) && participant.isHitting())
    {
        deal(participant);
        cout << participant << endl;

        if (participant.isBusted())
            participant.bust();
    }
}
//-----------------------------------------------------------------------------------------------------------
BlackjackGame::BlackjackGame(const vector<string>& names){
    game_deck = new Deck();
    
    vector<string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName)
        game_players.push_back(Player(*pName));
    srand(time(0));
    game_deck->init();
    game_deck->shuffle();
}

BlackjackGame::BlackjackGame(Player* p) {
    game_deck = new Deck();

    game_players.push_back(*p);
    srand(time(0));
    game_deck->init();
    game_deck->shuffle();
}

BlackjackGame::~BlackjackGame(){}

void BlackjackGame::Play() {
    //deal two cards to each person
    vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = game_players.begin(); pPlayer != game_players.end(); ++pPlayer) {
            game_deck->deal(*pPlayer);
        }
        game_deck->deal(game_dealer);
    }

    game_dealer.flipCard(); //hide dealer's first card

    //display hands
    //for (pPlayer = game_players.begin(); pPlayer != game_players.end(); ++pPlayer)
    //    cout << *pPlayer << endl;
    //cout << game_dealer << endl;

    // deal additional cards to players
    //for (pPlayer = game_players.begin(); pPlayer != game_players.end(); ++pPlayer)
      //  game_deck.anotherCard(*pPlayer);

    //reveal dealer's first card
    //game_dealer.flipCard();
    //cout << endl << game_dealer;

    //deal additional cards to dealer
    //game_deck.anotherCard(game_dealer);

    //if (game_dealer.isBusted())
    //{
        //players win
    //    for (pPlayer = game_players.begin(); pPlayer != game_players.end(); ++pPlayer)
    //        if (!(pPlayer->isBusted()))
    //            pPlayer->win();
    //}
    //else
    //{
        //compare players' hands to dealer hand
    //    for (pPlayer = game_players.begin(); pPlayer != game_players.end(); ++pPlayer)
    //        if(!(pPlayer->isBusted())) {
    //            if(pPlayer->sumOfHand() > game_dealer.sumOfHand())
    //                pPlayer->win();
    //            else if (pPlayer->sumOfHand() < game_dealer.sumOfHand())
    //                pPlayer->lose();
    //            else
    //               pPlayer->push();
    //        }
    //}

//remove cards
    for (pPlayer = game_players.begin(); pPlayer != game_players.end(); ++pPlayer)
        pPlayer->clear();
    game_dealer.clear();
}

//-----------------------------------------------------------------------------------------------------------
GenericParticipant::GenericParticipant(const string& name): m_name(name){}

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
    //largest possible hand in blackjack has 7 cards
    cards.reserve(7);
}

Hand::~Hand()
{
    clear();
}

void Hand::addCard(Card* card)
{
    cards.push_back(card);
}

void Hand::clear() {
    vector<Card*>::iterator iter = cards.begin();

    for (iter = cards.begin(); iter != cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    cards.clear();
}

int Hand::sumOfHand() const {
    if(cards.empty())
        return 0;
    //If first card has value of 0, then card is face down; return 0
    if(cards[0]->getValue() == 0)
        return 0;

    int total = 0;
    vector<Card*>::const_iterator iter;
    //treat each ace as a 1
    for(iter = cards.begin(); iter != cards.end(); ++iter)
        total += (*iter)->getValue();

    //now, check to see if ace should be 11
    bool containsAce = false;
    for (iter = cards.begin(); iter != cards.end(); ++iter)
        if ((*iter)->getValue() == Card::ACE)
            containsAce = true;

    //now check to see if total is less than 11
    if(containsAce && total <= 11)
        total +=10;

    return total;
}

vector<Card*> Hand::getCards() {
    return this->cards;
}
//---------------------------------------------------------------------------------------------------------------
Dealer::Dealer(const string& name): GenericParticipant(name){}

Dealer::~Dealer(){}

bool Dealer::isHitting() const{
    return (sumOfHand() <= 16);
}

void Dealer::flipCard()
{
    if(!(cards.empty()))
        cards[0]->flip();
    else
        cout << "No card to flip!\n";
}

//-----------------------------------------------------------------------------------------------------------
Player::Player(const string& name): GenericParticipant(name) {
    this->bet = 0;
}

Player::~Player(){}

bool Player::isHitting() const{
    cout << "Do you want a hit (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::win() const
{
    cout << "Player wins!\n";
}

void Player::lose() const
{
    cout << "Player loses!\n";
}

void Player::push() const
{
    cout << "Player pushes!\n";
}

void Player::setBet(int b) {
    this->bet = b;
}

int Player::getBet() {
    return this->bet;
}