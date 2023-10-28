#include "community_cards.h"

CommunityCards::CommunityCards()
{
    mNumberOfCards = 0;
    mCards = new Card[5];
}

bool CommunityCards::AddCard(const Card &card)
{
    if (mNumberOfCards == 5)
    {
        return false;
    }

    mCards[mNumberOfCards] = card;
    mNumberOfCards++;

    return true;
}
