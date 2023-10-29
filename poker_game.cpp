#include "poker_game.h"

#include "deck.h"
#include "community_cards.h"
#include "player_hand.h"

PokerGame::PokerGame(QObject *parent)
{

}

void PokerGame::initialise(Deck *deck,
                CommunityCards *communityCards,
                PlayerHand *p1,
                PlayerHand *p2)
{
    mDeck = deck;
    mCommunityCards = communityCards;
    mPlayerOne = p1;
    mPlayerTwo = p2;

    mCommunityCards->AddCard(mDeck->removeRandomCard());
    mCommunityCards->AddCard(mDeck->removeRandomCard());
    mCommunityCards->AddCard(mDeck->removeRandomCard());
}
