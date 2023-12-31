#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "deck.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Deck deck;
    engine.rootContext()->setContextProperty("deck", &deck);

    const QUrl url(u"qrc:/PokerTime/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
