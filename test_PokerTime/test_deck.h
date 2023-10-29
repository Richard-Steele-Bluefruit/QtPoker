#ifndef TEST_DECK_H
#define TEST_DECK_H

#include <QtTest>

class DeckTests : public QObject
{
    Q_OBJECT

public:
    DeckTests();
    ~DeckTests();

private slots:
    void initTestCase();
    void cleanupTestCase();

    void test_removeRandomCard_removes_a_card();
};

//#include "test_deck.moc"

#endif // TEST_DECK_H
