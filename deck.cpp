#include "deck.h"

#include <random>
#include <QDebug>

Deck::Deck(QObject* parent)
{
    mNumberOfCards = NUMBER_OF_CARDS_IN_A_DECK;
    mCards = new Card[mNumberOfCards];
    int cardIndex = 0;

    for (int suit = 0; suit < static_cast<int>(Suit::Count); suit++)
    {
        for (int value = 1; value <= 13; value++)
        {
            mCards[cardIndex++] = Card(static_cast<Suit>(suit), value);
        }
    }
}

Deck::~Deck()
{

}

Card *Deck::removeRandomCard()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(0, mNumberOfCards - 1);
    int randomIndex = dist(mt);

    Card randomCard = mCards[randomIndex];

    for (int i = randomIndex; i < mNumberOfCards-1; i++)
    {
        mCards[i] = mCards[i+1];
    }

    mNumberOfCards--;

    return new Card(randomCard.suit, randomCard.value);
}
