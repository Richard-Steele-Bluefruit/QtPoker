#include <QTest>

#include "test_deck.h"
#include "test_player_hand.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    int status = 0;

    {
        qDebug() << "Foo";
        DeckTests tc;
        status |= QTest::qExec(&tc, argc, argv);
    }

    {
        qDebug() << "Bar";
        PlayerHandTests tc;
        status |= QTest::qExec(&tc, argc, argv);
    }

    return status;
}
