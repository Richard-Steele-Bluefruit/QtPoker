#ifndef POKERGAME_H
#define POKERGAME_H

#include <QObject>

class Deck;
class CommunityCards;
class PlayerHand;

class PokerGame : public QObject
{
    Q_OBJECT
public:
    explicit PokerGame(QObject *parent = nullptr);

    void initialise(Deck *deck,
                    CommunityCards *communityCards,
                    PlayerHand *p1,
                    PlayerHand *p2);

    Q_PROPERTY(QList<QString> communityCards READ getCommunityCards WRITE setCommunityCards NOTIFY communityCardsChanged FINAL)

private:
    Deck *mDeck;
    CommunityCards *mCommunityCards;
    PlayerHand *mPlayerOne;
    PlayerHand *mPlayerTwo;
};

#endif // POKERGAME_H
