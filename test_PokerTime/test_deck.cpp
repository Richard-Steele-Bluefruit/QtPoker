#include "test_deck.h"

#include "../deck.h"

DeckTests::DeckTests()
{

}

DeckTests::~DeckTests()
{

}

void DeckTests::initTestCase()
{

}

void DeckTests::cleanupTestCase()
{

}
void DeckTests::test_removeRandomCard_removes_a_card()
{
    // Given
    Deck deck;
    QVERIFY(deck.Count() == NUMBER_OF_CARDS_IN_A_DECK);

    // When
    deck.RemoveRandomCard();

    // Then
    int expected = NUMBER_OF_CARDS_IN_A_DECK - 1;
    QVERIFY(deck.Count() == expected);
}
