#ifndef PLAYERHAND_H
#define PLAYERHAND_H

#include "cards.h"

class PlayerHand : public Cards
{
public:
    PlayerHand(const Card &card1, const Card &card2);
};

#endif // PLAYERHAND_H
