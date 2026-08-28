#include <QtTest>

#include "../src/model/Deck.h"

class TestDeck : public QObject
{
    Q_OBJECT

private slots:
    void creates32Cards();
    void drawRemovesCard();
    void resetRestores32Cards();
    void drawUntilEmpty();
};

void TestDeck::creates32Cards()
{
    Deck deck;

    QCOMPARE(static_cast<int>(deck.cards().size()), 32);
    QVERIFY(!deck.empty());
}

void TestDeck::drawRemovesCard()
{
    Deck deck;

    deck.draw();

    QCOMPARE(static_cast<int>(deck.cards().size()), 31);
}

void TestDeck::resetRestores32Cards()
{
    Deck deck;

    deck.draw();
    deck.draw();
    deck.draw();

    QCOMPARE(static_cast<int>(deck.cards().size()), 29);

    deck.reset();

    QCOMPARE(static_cast<int>(deck.cards().size()), 32);
}

void TestDeck::drawUntilEmpty()
{
    Deck deck;

    for (int i = 0; i < 32; ++i) {
        deck.draw();
    }

    QVERIFY(deck.empty());
}

QTEST_MAIN(TestDeck)

#include "tst_deck.moc"
