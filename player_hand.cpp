#include "player_hand.h"
#include "deck.h"
#include "hands.h"

PlayerHand::PlayerHand(Card &card1, Card &card2, Card *deck)
{
    mNumberOfCards = 7;
    mCards = new Card[mNumberOfCards];

    mCards[0] = card1;
    mCards[1] = card2;

    mAllCards = new Card*[7];
    mAllCards[0] = &card1;
    mAllCards[1] = &card2;
    mAllCards[2] = &deck[0];
    mAllCards[3] = &deck[1];
    mAllCards[4] = &deck[2];
    mAllCards[5] = &deck[3];
    mAllCards[6] = &deck[4];
};

PlayerHand::~PlayerHand()
{

};

void PlayerHand::bubbleSort()
{
    for (int iters = 0; iters < mNumberOfCards; iters++)
    {
        for (int i = 0; i < mNumberOfCards; i++)
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
    int suitScores[4];

    for (int i = 0; i < mNumberOfCards; i++)
    {
        suitScores[static_cast<int>(mAllCards[i]->suit)]++;
    }

    int currentHighestSuitCount = 0;

    for (int i = 0; i < mNumberOfCards; i++)
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

    for (int i = 1; i < mNumberOfCards - 1; i++)
    {
        // skip an identical value card
        if (mAllCards[i]->value == mAllCards[i + 1]->value)
        {
            continue;
        }

        if (mAllCards[i]->value == mAllCards[i + 1]->value + 1)
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
