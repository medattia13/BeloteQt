#include <QtTest>

#include "../src/model/Card.h"

class TestCard : public QObject
{
    Q_OBJECT

private slots:
    void createsCard();
    void returnsSuit();
    void returnsRank();

    void nonTrumpPoints();
    void trumpPoints();

    void nonTrumpStrength();
    void trumpStrength();
};

void TestCard::createsCard()
{
    Card card(Suit::Hearts, Rank::Ace);

    QCOMPARE(card.suit(), Suit::Hearts);
    QCOMPARE(card.rank(), Rank::Ace);
}

void TestCard::returnsSuit()
{
    Card card(Suit::Spades, Rank::King);

    QCOMPARE(card.suit(), Suit::Spades);
}

void TestCard::returnsRank()
{
    Card card(Suit::Diamonds, Rank::Queen);

    QCOMPARE(card.rank(), Rank::Queen);
}

void TestCard::nonTrumpPoints()
{
    const Suit trump = Suit::Hearts;

    QCOMPARE(Card(Suit::Clubs, Rank::Ace).points(trump), 11);
    QCOMPARE(Card(Suit::Clubs, Rank::Ten).points(trump), 10);
    QCOMPARE(Card(Suit::Clubs, Rank::King).points(trump), 4);
    QCOMPARE(Card(Suit::Clubs, Rank::Queen).points(trump), 3);
    QCOMPARE(Card(Suit::Clubs, Rank::Jack).points(trump), 2);

    QCOMPARE(Card(Suit::Clubs, Rank::Nine).points(trump), 0);
    QCOMPARE(Card(Suit::Clubs, Rank::Eight).points(trump), 0);
    QCOMPARE(Card(Suit::Clubs, Rank::Seven).points(trump), 0);
}

void TestCard::trumpPoints()
{
    const Suit trump = Suit::Hearts;

    QCOMPARE(Card(Suit::Hearts, Rank::Jack).points(trump), 20);
    QCOMPARE(Card(Suit::Hearts, Rank::Nine).points(trump), 14);
    QCOMPARE(Card(Suit::Hearts, Rank::Ace).points(trump), 11);
    QCOMPARE(Card(Suit::Hearts, Rank::Ten).points(trump), 10);
    QCOMPARE(Card(Suit::Hearts, Rank::King).points(trump), 4);
    QCOMPARE(Card(Suit::Hearts, Rank::Queen).points(trump), 3);
    QCOMPARE(Card(Suit::Hearts, Rank::Eight).points(trump), 0);
    QCOMPARE(Card(Suit::Hearts, Rank::Seven).points(trump), 0);
}

void TestCard::nonTrumpStrength()
{
    const Suit trump = Suit::Hearts;

    // Non-trump order:
    // Ace > Ten > King > Queen > Jack > Nine > Eight > Seven

    QCOMPARE(Card(Suit::Clubs, Rank::Ace).strength(trump), 8);
    QCOMPARE(Card(Suit::Clubs, Rank::Ten).strength(trump), 7);
    QCOMPARE(Card(Suit::Clubs, Rank::King).strength(trump), 6);
    QCOMPARE(Card(Suit::Clubs, Rank::Queen).strength(trump), 5);
    QCOMPARE(Card(Suit::Clubs, Rank::Jack).strength(trump), 4);
    QCOMPARE(Card(Suit::Clubs, Rank::Nine).strength(trump), 3);
    QCOMPARE(Card(Suit::Clubs, Rank::Eight).strength(trump), 2);
    QCOMPARE(Card(Suit::Clubs, Rank::Seven).strength(trump), 1);
}

void TestCard::trumpStrength()
{
    const Suit trump = Suit::Hearts;

    // Trump order:
    // Jack > Nine > Ace > Ten > King > Queen > Eight > Seven

    QCOMPARE(Card(Suit::Hearts, Rank::Jack).strength(trump), 8);
    QCOMPARE(Card(Suit::Hearts, Rank::Nine).strength(trump), 7);
    QCOMPARE(Card(Suit::Hearts, Rank::Ace).strength(trump), 6);
    QCOMPARE(Card(Suit::Hearts, Rank::Ten).strength(trump), 5);
    QCOMPARE(Card(Suit::Hearts, Rank::King).strength(trump), 4);
    QCOMPARE(Card(Suit::Hearts, Rank::Queen).strength(trump), 3);
    QCOMPARE(Card(Suit::Hearts, Rank::Eight).strength(trump), 2);
    QCOMPARE(Card(Suit::Hearts, Rank::Seven).strength(trump), 1);
}

QTEST_MAIN(TestCard)

#include "tst_card.moc"
