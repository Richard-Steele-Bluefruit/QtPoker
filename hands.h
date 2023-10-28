#ifndef HANDS_H
#define HANDS_H

enum class Type
{
    HighCard = 0,
    Pair,
    TwoPair,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush,
    RoyalFlush
};

struct Hand
{
    Type type;
    int kicker;
};

#endif // HANDS_H
