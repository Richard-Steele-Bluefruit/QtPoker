#ifndef TEST_PLAYER_HAND_H
#define TEST_PLAYER_HAND_H

#include <QtTest>

class PlayerHandTests : public QObject
{
    Q_OBJECT

public:
    PlayerHandTests();
    ~PlayerHandTests();

private slots:
    void initTestCase();
    void cleanupTestCase();

    void test_checkFlush1();
    void test_checkFlush2();
    void test_checkFlush3();
    void test_checkStraight1();
    void test_checkStraight2();
    void test_checkStraight3();
};

//#include "test_player_hand.moc"

#endif // TEST_PLAYER_HAND_H
