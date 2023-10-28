#ifndef CARD_H
#define CARD_H

#include <cstdint>

enum class Suit
{
    Club,
    Spade,
    Diamond,
    Heart,

    Count
};

struct Card
{
    Card(const Suit _suit = Suit::Club, const uint8_t _value = 1)
        : suit {_suit}
        , value {_value} {}

    Suit suit;
    uint8_t value;

    inline bool operator == (Card c)
    {
        return suit == c.suit && value == c.value;
    }
};

#endif // CARD_H
