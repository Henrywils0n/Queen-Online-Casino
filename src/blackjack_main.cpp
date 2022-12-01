#include "Blackjack.h"

ostream& operator << (ostream& os, const Card& aCard);
ostream& operator << (ostream& os, const GenericParticipant& aGenericPlayer);

int main()
{
    cout << "\t\tWELCOME TO BLACKJACK!\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many Players? (1−7): ";
        cin >> numPlayers;
    }

    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;


    BlackjackGame aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }

    return 0;
}


ostream& operator <<(ostream& os, const Card& aCard)
{
    const string RANKS[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9",
                            "10", "J", "Q", "K"};
    const string SUITS[] = {"c", "d", "h", "s"};

    if (aCard.facedUp)
        os << RANKS[aCard.Rank-1] << SUITS[aCard.Suit-1];
    else
        os << "XX";

    return os;
}


ostream& operator<<(ostream& os, const GenericParticipant& aGenericPlayer)
{
    os << aGenericPlayer.m_name << ":\t";

    vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.cards.empty())
    {
        for (pCard = aGenericPlayer.cards.begin();
             pCard != aGenericPlayer.cards.end(); ++pCard)
            os << *(*pCard) << "\t";
        if (aGenericPlayer.sumOfHand() != 0)
            cout << "(" << aGenericPlayer.sumOfHand() << ")";
    }
    else
    {
        os << "<empty";
    }

    return os;
}