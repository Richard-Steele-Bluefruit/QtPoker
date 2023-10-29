#ifndef PLAYERHAND_H
#define PLAYERHAND_H

#include "cards.h"
#include "community_cards.h"

class Deck;
class Hand;

class PlayerHand : public Cards
{
public:
    PlayerHand(Card &card1, Card &card2, CommunityCards *communityCards);
    ~PlayerHand();

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

private:
    Hand GetScore();
    void bubbleSort();

    Card **mAllCards;

};

#endif // PLAYERHAND_H
