#ifndef PLAYERHAND_H
#define PLAYERHAND_H

#include "cards.h"

class Deck;
class Hand;

class PlayerHand : public Cards
{
public:
    PlayerHand(const Card &card1, const Card &card2, Card *deck);
    ~PlayerHand();

private:
    Hand GetScore();

    Card **mAllCards;

    void bubbleSort();

    bool checkRoyalFlush();
    bool checkStraightFlush();
    bool checkFourOfAKind();
    bool checkFullHouse();
    bool checkFlush();
    bool checkStraight();
    bool checkThreeOfAKind();
    bool checkTwoPair();
    bool checkPair();
    bool checkHighCard();
};

#endif // PLAYERHAND_H
