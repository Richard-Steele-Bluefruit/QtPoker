#ifndef DECK_H
#define DECK_H

#include "cards.h"

#define NUMBER_OF_CARDS_IN_A_DECK   52

class Deck : public Cards
{
public:
    Deck();
    ~Deck();

    Card *RemoveRandomCard();
};

#endif // DECK_H
