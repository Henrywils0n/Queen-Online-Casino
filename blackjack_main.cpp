#include "Blackjack.h"


ostream& operator << (ostream& os, const Card& aCard);
ostream& operator << (ostream& os, const GenericParticipant& aGenericPlayer);

int main()
{
    cout << "\t\tWELCOME TO BLACKJACK!\n\n";



    BlackjackGame *game = new BlackjackGame();
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        game->Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }

    return 0;
}

/*
============================================================
Overloads << operator so Card object can be sent to cout
============================================================
*/
ostream& operator <<(ostream& os, const Card& aCard)
{
    const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
                            "10", "J", "Q", "K"};
    const string SUITS[] = {"c", "d", "h", "s"};

    if (aCard.facedUp)
        os << RANKS[aCard.Rank] << SUITS[aCard.Suit];
    else
        os << "XX";
    return os;
}

/*
======================================================================
Overloads << operator so a Generic Player object can be sent to cout
======================================================================
*/
ostream& operator<<(ostream& os, const GenericParticipant& aGenericPlayer)
{
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
