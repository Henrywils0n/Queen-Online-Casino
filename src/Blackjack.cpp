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
    if (facedUp) {
        value = Rank;
        //jack, queen, and king are = 10
        if (value > 10)
            value = 10;
    }
    return value;
}

string Card::getRank() const{
    switch (Rank){
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
    switch (Suit){
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
    if (this->facedUp) {
        return getRank() + " of " + getSuit();
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
    cards.reserve(3*52);
    init();
}

void Deck::init(){
    clear();
    for (int k = 0; k<2; k++){
        for (int i = Card::CLUBS; i <= Card::SPADES; ++i){
            for (int j = Card::ACE; j <= Card::KING; ++j) {
                addCard(new Card(static_cast<Card::rank>(j), static_cast<Card::suit>(i), true));
                //OutputDebugStringW(L"" + to_string(i) + " " + to_string(j) + "\n");
            }
        }
    }
}

void Deck::shuffle()
{
    random_shuffle(cards.begin(), cards.end());
}

void Deck::deal(Hand& h)
{
    if (!cards.empty())
    {
        h.addCard(cards.back());
        cards.pop_back();
    }
    else
    {
        cout << "shuffling a new deck\n";
        init();
        shuffle();
        h.addCard(cards.back());
        cards.pop_back();
    }
}

void Deck::anotherCard(GenericParticipant& participant)
{
    cout << endl;
    while (!(participant.isBusted()) && participant.isHitting())
    {
        deal(participant);
        //cout << participant << endl;

        if (participant.isBusted())
            participant.bust();
    }
}
//-----------------------------------------------------------------------------------------------------------
BlackjackGame::BlackjackGame(){
    game_deck = new Deck();
    game_players = new Player();
    game_dealer = new Dealer();
    
    srand(time(0));
    game_deck->init();
    game_deck->shuffle();
}

BlackjackGame::BlackjackGame(){}

BlackjackGame::~BlackjackGame(){}

void BlackjackGame::Play() {

    cout << "Place your bet: ";
    int bet;
    cin >> bet;
    game_players->placeBet(bet);

    // Deal
    for (int i = 0; i < 2; ++i)
    {
        game_deck->deal(*game_players);
        game_deck->deal(*game_dealer);
    }

    //hide dealer's first card
    game_dealer->flipCard();

//    //display hands
//    for (pPlayer = game_players.begin(); pPlayer != game_players.end(); ++pPlayer)
//        cout << *pPlayer << endl;
//    cout << game_dealer << endl;
//
////deal additional cards to players
//    for (pPlayer = game_players.begin(); pPlayer != game_players.end(); ++pPlayer)
//        game_deck.anotherCard(*pPlayer);
//
////reveal dealer's first card
//    game_dealer.flipCard();
//    cout << endl << game_dealer;
//
////deal additional cards to dealer
//    game_deck.anotherCard(game_dealer);
//    for (pPlayer = game_players.begin(); pPlayer != game_players.end(); ++pPlayer) {
//
//        if (pPlayer->isBusted()) {
//            pPlayer->lose();
//        } else {
//            if (game_dealer.isBusted()) {
//                pPlayer->win();
//            } else {
//                //compare players' hands to dealer hand
//                if (pPlayer->sumOfHand() > game_dealer.sumOfHand())
//                    pPlayer->win();
//                else if (pPlayer->sumOfHand() < game_dealer.sumOfHand())
//                    pPlayer->lose();
//                else
//                    pPlayer->push();
//            }
//        }
//    }
//
////remove cards
//    for (pPlayer = game_players.begin(); pPlayer != game_players.end(); ++pPlayer)
//        pPlayer->clear();
//    game_dealer.clear();
}

//-----------------------------------------------------------------------------------------------------------
GenericParticipant::GenericParticipant() {}

GenericParticipant::GenericParticipant(const string& name): m_name(name){}

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
Player::Player(const string& player): GenericParticipant() {
    bet = 0;
    setBalance(100);
}

bool Player::isHitting() const{
    if (sumOfHand() == 21){
        return false;
    }
    else {
        cout << "Do you want a hit (Y/N): ";
        char response;
        cin >> response;
        return (response == 'y' || response == 'Y');
    }
}

void Player::win()
{
    cout << "Player wins!\n";
    balance+= (bet*2);
    cout << "balance is: $" << balance << "\n";
}

void Player::lose()
{
    cout << "Player loses!\n";
    cout << "balance is: $" << balance << "\n";
}

void Player::push()
{
    cout << "Player pushes!\n";
    balance+= bet;
    cout << "balance is: $" << balance << "\n";
}

void Player::placeBet(int b){
//    if (bet > balance){
//        throw InsufficientFundsException("Not enough funds");
//    }
//    else if (bet < 0){
//        throw MinimumBetException("Bet must be a positive number");
//    }
//    else if (bet > 10000){
//        throw MaximumBetException("Bet must be less than $10,000");
//    }
//    else {
    bet = b;
    balance -= bet;
//    }
}

int Player::getBet() {
    return bet;
}

void Player::setBalance(int amount) {
    balance = amount;
}

InsufficientFundsException::InsufficientFundsException(const string& message) : message(message) {}

string& InsufficientFundsException::what() { return message; }

MaximumBetException::MaximumBetException(const string& message) : message(message) {}

string& MaximumBetException::what() { return message; }

MinimumBetException::MinimumBetException(const string& message) : message(message) {}

string& MinimumBetException::what() { return message; }
