#ifndef DECK_H
#define DECK_H

#include "cards.h"

#include <QObject>

#define NUMBER_OF_CARDS_IN_A_DECK   52

class Deck : public QObject, public Cards
{
    Q_OBJECT
public:
    explicit Deck(QObject* parent = nullptr);
    ~Deck();

    Q_INVOKABLE Card *removeRandomCard();

signals:
    void cardRemoved();
};

#endif // DECK_H
