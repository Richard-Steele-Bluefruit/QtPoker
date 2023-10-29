#include "player_hand.h"
#include "hands.h"

#include <QDebug>

PlayerHand::PlayerHand(Card &card1, Card &card2, CommunityCards *communityCards)
{
    mNumberOfCards = 7;
    mCards = new Card[mNumberOfCards];

    mCards[0] = card1;
    mCards[1] = card2;

    mAllCards = new Card*[7];
    mAllCards[0] = &card1;
    mAllCards[1] = &card2;
    mAllCards[2] = &communityCards->getCards()[0];
    mAllCards[3] = &communityCards->getCards()[1];
    mAllCards[4] = &communityCards->getCards()[2];
    mAllCards[5] = &communityCards->getCards()[3];
    mAllCards[6] = &communityCards->getCards()[4];
};

PlayerHand::~PlayerHand()
{

};

void PlayerHand::bubbleSort()
{
    for (int iters = 0; iters < mNumberOfCards; iters++)
    {
        for (int i = 0; i < mNumberOfCards - 1; i++)
        {
            if (mAllCards[i]->value > mAllCards[i + 1]->value)
            {
                Card *tempCardPtr = mAllCards[i];
                mAllCards[i] = mAllCards[i + 1];
                mAllCards[i + 1] = tempCardPtr;
            }
        }
    }
};

Hand PlayerHand::GetScore()
{

};

bool PlayerHand::checkRoyalFlush()
{

};

bool PlayerHand::checkStraightFlush()
{

};

bool PlayerHand::checkFourOfAKind()
{

};

bool PlayerHand::checkFullHouse()
{

};

bool PlayerHand::checkFlush()
{
    int suitScores[4] = {0};

    for (int i = 0; i < mNumberOfCards; i++)
    {
        suitScores[static_cast<int>(mAllCards[i]->suit)]++;
    }

    int currentHighestSuitCount = 0;

    for (int i = 0; i < 4; i++)
    {
        if (suitScores[i] > currentHighestSuitCount)
        {
            currentHighestSuitCount = suitScores[i];
        }
    }

    return currentHighestSuitCount >= 5;
};

bool PlayerHand::checkStraight()
{
    bubbleSort();

    int runningCount = 1;

    for (int i = 0; i < mNumberOfCards - 1; i++)
    {
        // skip an identical value card
        if (mAllCards[i]->value == mAllCards[i + 1]->value)
        {
            continue;
        }

        if (mAllCards[i]->value == mAllCards[i + 1]->value - 1)
        {
            runningCount++;

            if (runningCount >= 5)
            {
                return true;
            }
        }
        else
        {
            runningCount = 1;
        }
    }

    return false;
};

bool PlayerHand::checkThreeOfAKind()
{

};

bool PlayerHand::checkTwoPair()
{

};

bool PlayerHand::checkPair()
{

};

bool PlayerHand::checkHighCard()
{

};
