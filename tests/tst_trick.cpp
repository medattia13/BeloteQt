#include <QtTest>

#include "../src/model/Trick.h"

class TestTrick : public QObject
{
    Q_OBJECT

private slots:
    void startsEmpty();
    void addCard();
    void storesPlayerId();
    void storesCards();

    void incompleteWithThreeCards();
    void completeWithFourCards();

    void winnerIsHighestLeadSuit();
    void trumpBeatsLeadSuit();
    void strongestTrumpWins();

    void pointsAreCalculated();
};

void TestTrick::startsEmpty()
{
    Trick trick;

    QVERIFY(trick.cards().empty());
    QVERIFY(!trick.isComplete());
}

void TestTrick::addCard()
{
    Trick trick;

    Card card(Suit::Hearts, Rank::Ace);

    trick.addCard(1, card);

    QCOMPARE(static_cast<int>(trick.cards().size()), 1);
    QCOMPARE(trick.cards()[0].first, 1);
}

void TestTrick::storesPlayerId()
{
    Trick trick;

    trick.addCard(3, Card(Suit::Clubs, Rank::King));

    QCOMPARE(trick.cards()[0].first, 3);
}

void TestTrick::storesCards()
{
    Trick trick;

    Card card(Suit::Spades, Rank::Queen);

    trick.addCard(2, card);

    QCOMPARE(trick.cards()[0].second.suit(), Suit::Spades);
    QCOMPARE(trick.cards()[0].second.rank(), Rank::Queen);
}

void TestTrick::incompleteWithThreeCards()
{
    Trick trick;

    trick.addCard(1, Card(Suit::Hearts, Rank::Ace));
    trick.addCard(2, Card(Suit::Clubs, Rank::King));
    trick.addCard(3, Card(Suit::Diamonds, Rank::Queen));

    QVERIFY(!trick.isComplete());
}

void TestTrick::completeWithFourCards()
{
    Trick trick;

    trick.addCard(1, Card(Suit::Hearts, Rank::Ace));
    trick.addCard(2, Card(Suit::Clubs, Rank::King));
    trick.addCard(3, Card(Suit::Diamonds, Rank::Queen));
    trick.addCard(4, Card(Suit::Spades, Rank::Jack));

    QVERIFY(trick.isComplete());
}

void TestTrick::winnerIsHighestLeadSuit()
{
    Trick trick;

    // Hearts is the lead suit.
    trick.addCard(1, Card(Suit::Hearts, Rank::Seven));
    trick.addCard(2, Card(Suit::Hearts, Rank::Ace));
    trick.addCard(3, Card(Suit::Clubs, Rank::Ace));
    trick.addCard(4, Card(Suit::Hearts, Rank::Ten));

    QCOMPARE(
        trick.winner(Suit::Spades, Suit::Hearts),
        2
        );
}

void TestTrick::trumpBeatsLeadSuit()
{
    Trick trick;

    // Hearts is lead, Spades is trump.
    trick.addCard(1, Card(Suit::Hearts, Rank::Ace));
    trick.addCard(2, Card(Suit::Hearts, Rank::King));
    trick.addCard(3, Card(Suit::Spades, Rank::Seven));
    trick.addCard(4, Card(Suit::Hearts, Rank::Ten));

    QCOMPARE(
        trick.winner(Suit::Spades, Suit::Hearts),
        3
    );
}

void TestTrick::strongestTrumpWins()
{
    Trick trick;

    // Spades are trump.
    trick.addCard(1, Card(Suit::Spades, Rank::Ace));
    trick.addCard(2, Card(Suit::Spades, Rank::Nine));
    trick.addCard(3, Card(Suit::Spades, Rank::Jack));
    trick.addCard(4, Card(Suit::Spades, Rank::King));

    // Trump order:
    // Jack > Nine > Ace > Ten > King > Queen > Eight > Seven
    QCOMPARE(
        trick.winner(Suit::Spades, Suit::Spades),
        3
    );
}

void TestTrick::pointsAreCalculated()
{
    Trick trick;

    // Hearts are trump.
    trick.addCard(1, Card(Suit::Hearts, Rank::Jack)); // 20
    trick.addCard(2, Card(Suit::Clubs, Rank::Ace));   // 11
    trick.addCard(3, Card(Suit::Diamonds, Rank::Ten)); // 10
    trick.addCard(4, Card(Suit::Spades, Rank::King)); // 4

    QCOMPARE(trick.points(Suit::Hearts), 45);
}

QTEST_MAIN(TestTrick)

#include "tst_trick.moc"
