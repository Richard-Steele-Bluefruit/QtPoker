#include "player_hand.h"

PlayerHand::PlayerHand(const Card &card1, const Card &card2)
{
    mNumberOfCards = 2;
    mCards = new Card[mNumberOfCards];

    mCards[0] = card1;
    mCards[1] = card2;
}
