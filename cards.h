#ifndef CARDS_H
#define CARDS_H

#include <cstdint>

#include "card.h"

class Cards
{
public:
    virtual ~Cards()
    {
        delete[] mCards;
    }

    Card* getCards()
    {
        return mCards;
    }

    size_t Count()
    {
        return mNumberOfCards;
    }

protected:
    Card *mCards;
    uint8_t mNumberOfCards;
};

#endif // CARDS_H
