#include "test_player_hand.h"

#include "../player_hand.h"

PlayerHandTests::PlayerHandTests()
{

}

PlayerHandTests::~PlayerHandTests()
{

}

void PlayerHandTests::initTestCase()
{

}

void PlayerHandTests::cleanupTestCase()
{

}

void PlayerHandTests::test_checkFlush1()
{
    // Given
    Card playerCard1(Suit::Club, 2);
    Card playerCard2(Suit::Club, 3);

    CommunityCards communityCards;

    communityCards.AddCard(Card(Suit::Club, 5));
    communityCards.AddCard(Card(Suit::Club, 7));
    communityCards.AddCard(Card(Suit::Club, 9));
    communityCards.AddCard(Card(Suit::Club, 11));
    communityCards.AddCard(Card(Suit::Club, 13));

    PlayerHand playerHand(playerCard1, playerCard2, &communityCards);

    // When
    bool hasFlush = playerHand.checkFlush();

    // Then
    QVERIFY(hasFlush);
}

void PlayerHandTests::test_checkFlush2()
{
    // Given
    Card playerCard1(Suit::Club, 2);
    Card playerCard2(Suit::Club, 3);

    CommunityCards communityCards;

    communityCards.AddCard(Card(Suit::Heart, 5));
    communityCards.AddCard(Card(Suit::Club, 7));
    communityCards.AddCard(Card(Suit::Diamond, 9));
    communityCards.AddCard(Card(Suit::Club, 11));
    communityCards.AddCard(Card(Suit::Club, 13));

    PlayerHand playerHand(playerCard1, playerCard2, &communityCards);

    // When
    bool hasFlush = playerHand.checkFlush();

    // Then
    QVERIFY(hasFlush);
}

void PlayerHandTests::test_checkFlush3()
{
    // Given
    Card playerCard1(Suit::Club, 2);
    Card playerCard2(Suit::Club, 3);

    CommunityCards communityCards;

    communityCards.AddCard(Card(Suit::Heart, 5));
    communityCards.AddCard(Card(Suit::Club, 7));
    communityCards.AddCard(Card(Suit::Diamond, 9));
    communityCards.AddCard(Card(Suit::Club, 11));
    communityCards.AddCard(Card(Suit::Spade, 13));

    PlayerHand playerHand(playerCard1, playerCard2, &communityCards);

    // When
    bool hasFlush = playerHand.checkFlush();

    // Then
    QVERIFY(hasFlush == false);
}

void PlayerHandTests::test_checkStraight1()
{
    // Given
    Card playerCard1(Suit::Club, 3);
    Card playerCard2(Suit::Spade, 2);

    CommunityCards communityCards;

    communityCards.AddCard(Card(Suit::Spade, 5));
    communityCards.AddCard(Card(Suit::Diamond, 8));
    communityCards.AddCard(Card(Suit::Club, 9));
    communityCards.AddCard(Card(Suit::Spade, 4));
    communityCards.AddCard(Card(Suit::Heart, 6));

    PlayerHand playerHand(playerCard1, playerCard2, &communityCards);

    // When
    bool hasStraight = playerHand.checkStraight();

    // Then
    QVERIFY(hasStraight);
}

void PlayerHandTests::test_checkStraight2()
{
    // Given
    Card playerCard1(Suit::Club, 3);
    Card playerCard2(Suit::Spade, 7);

    CommunityCards communityCards;

    communityCards.AddCard(Card(Suit::Spade, 5));
    communityCards.AddCard(Card(Suit::Diamond, 6));
    communityCards.AddCard(Card(Suit::Club, 6));
    communityCards.AddCard(Card(Suit::Spade, 4));
    communityCards.AddCard(Card(Suit::Heart, 6));

    PlayerHand playerHand(playerCard1, playerCard2, &communityCards);

    // When
    bool hasStraight = playerHand.checkStraight();

    // Then
    QVERIFY(hasStraight);
}

void PlayerHandTests::test_checkStraight3()
{
    // Given
    Card playerCard1(Suit::Club, 3);
    Card playerCard2(Suit::Spade, 2);

    CommunityCards communityCards;

    communityCards.AddCard(Card(Suit::Spade, 12));
    communityCards.AddCard(Card(Suit::Diamond, 8));
    communityCards.AddCard(Card(Suit::Club, 9));
    communityCards.AddCard(Card(Suit::Spade, 4));
    communityCards.AddCard(Card(Suit::Heart, 6));

    PlayerHand playerHand(playerCard1, playerCard2, &communityCards);

    // When
    bool hasStraight = playerHand.checkStraight();

    // Then
    QVERIFY(hasStraight == false);
}
