#include <QtTest>

#include "../src/model/BeloteRules.h"

class TestBeloteRules : public QObject
{
    Q_OBJECT

private slots:
    void cannotPlayCardNotInHand();

    void anythingAllowedOnFirstCard();

    void mustFollowLeadSuit();

    void cannotPlayOtherSuitWhenCanFollow();

    void mustTrumpWhenCannotFollow();

    void cannotPlayNonTrumpWhenTrumpAvailable();

    void canPlayAnyCardWhenNoSuitOrTrump();

    void mustOvertrumpWhenPossible();

    void canPlayTrumpWhenCannotOvertrump();

    void canPlayTrumpWhenNoTrumpOnTable();
};

void TestBeloteRules::cannotPlayCardNotInHand()
{
    Player player(1, "Alice");

    player.addCard(Card(Suit::Hearts, Rank::Ace));

    Trick trick;

    Card cardNotInHand(Suit::Clubs, Rank::Ace);

    QVERIFY(!BeloteRules::canPlayCard(
        player,
        cardNotInHand,
        trick,
        Suit::Spades
    ));
}

void TestBeloteRules::anythingAllowedOnFirstCard()
{
    Player player(1, "Alice");

    player.addCard(Card(Suit::Hearts, Rank::Ace));
    player.addCard(Card(Suit::Clubs, Rank::Seven));

    Trick trick;

    QVERIFY(BeloteRules::canPlayCard(
        player,
        Card(Suit::Hearts, Rank::Ace),
        trick,
        Suit::Spades
    ));

    QVERIFY(BeloteRules::canPlayCard(
        player,
        Card(Suit::Clubs, Rank::Seven),
        trick,
        Suit::Spades
    ));
}

void TestBeloteRules::mustFollowLeadSuit()
{
    Player player(1, "Alice");

    player.addCard(Card(Suit::Hearts, Rank::Ace));
    player.addCard(Card(Suit::Clubs, Rank::King));

    Trick trick;

    trick.addCard(
        2,
        Card(Suit::Hearts, Rank::Seven)
    );

    QVERIFY(BeloteRules::canPlayCard(
        player,
        Card(Suit::Hearts, Rank::Ace),
        trick,
        Suit::Spades
    ));
}

void TestBeloteRules::cannotPlayOtherSuitWhenCanFollow()
{
    Player player(1, "Alice");

    player.addCard(Card(Suit::Hearts, Rank::Ace));
    player.addCard(Card(Suit::Clubs, Rank::King));

    Trick trick;

    trick.addCard(
        2,
        Card(Suit::Hearts, Rank::Seven)
    );

    QVERIFY(!BeloteRules::canPlayCard(
        player,
        Card(Suit::Clubs, Rank::King),
        trick,
        Suit::Spades
    ));
}

void TestBeloteRules::mustTrumpWhenCannotFollow()
{
    Player player(1, "Alice");

    player.addCard(Card(Suit::Spades, Rank::Seven));
    player.addCard(Card(Suit::Clubs, Rank::King));

    Trick trick;

    trick.addCard(
        2,
        Card(Suit::Hearts, Rank::Ace)
    );

    QVERIFY(BeloteRules::canPlayCard(
        player,
        Card(Suit::Spades, Rank::Seven),
        trick,
        Suit::Spades
    ));
}

void TestBeloteRules::cannotPlayNonTrumpWhenTrumpAvailable()
{
    Player player(1, "Alice");

    player.addCard(Card(Suit::Spades, Rank::Seven));
    player.addCard(Card(Suit::Clubs, Rank::King));

    Trick trick;

    trick.addCard(
        2,
        Card(Suit::Hearts, Rank::Ace)
    );

    QVERIFY(!BeloteRules::canPlayCard(
        player,
        Card(Suit::Clubs, Rank::King),
        trick,
        Suit::Spades
    ));
}

void TestBeloteRules::canPlayAnyCardWhenNoSuitOrTrump()
{
    Player player(1, "Alice");

    player.addCard(Card(Suit::Clubs, Rank::King));
    player.addCard(Card(Suit::Diamonds, Rank::Seven));

    Trick trick;

    trick.addCard(
        2,
        Card(Suit::Hearts, Rank::Ace)
    );

    QVERIFY(BeloteRules::canPlayCard(
        player,
        Card(Suit::Clubs, Rank::King),
        trick,
        Suit::Spades
    ));

    QVERIFY(BeloteRules::canPlayCard(
        player,
        Card(Suit::Diamonds, Rank::Seven),
        trick,
        Suit::Spades
    ));
}

void TestBeloteRules::mustOvertrumpWhenPossible()
{
    Player player(1, "Alice");

    // Spades are trump.
    // Jack > Nine > Ace.
    player.addCard(Card(Suit::Spades, Rank::Jack));
    player.addCard(Card(Suit::Spades, Rank::Ace));

    Trick trick;

    trick.addCard(
        2,
        Card(Suit::Hearts, Rank::King)
    );

    // Someone already played the Nine of trump.
    trick.addCard(
        3,
        Card(Suit::Spades, Rank::Nine)
    );

    // Player has the Jack, which can overtrump the Nine.
    QVERIFY(BeloteRules::canPlayCard(
        player,
        Card(Suit::Spades, Rank::Jack),
        trick,
        Suit::Spades
    ));

    // Ace cannot be played because Jack is available
    // to overtrump the Nine.
    QVERIFY(!BeloteRules::canPlayCard(
        player,
        Card(Suit::Spades, Rank::Ace),
        trick,
        Suit::Spades
    ));
}

void TestBeloteRules::canPlayTrumpWhenCannotOvertrump()
{
    Player player(1, "Alice");

    // Only Ace of trump.
    player.addCard(Card(Suit::Spades, Rank::Ace));

    Trick trick;

    trick.addCard(
        2,
        Card(Suit::Hearts, Rank::King)
    );

    // Jack is already the strongest trump.
    trick.addCard(
        3,
        Card(Suit::Spades, Rank::Jack)
    );

    // Player cannot beat the Jack, so the Ace is legal.
    QVERIFY(BeloteRules::canPlayCard(
        player,
        Card(Suit::Spades, Rank::Ace),
        trick,
        Suit::Spades
    ));
}

void TestBeloteRules::canPlayTrumpWhenNoTrumpOnTable()
{
    Player player(1, "Alice");

    player.addCard(Card(Suit::Spades, Rank::Seven));

    Trick trick;

    trick.addCard(
        2,
        Card(Suit::Hearts, Rank::Ace)
    );

    QVERIFY(BeloteRules::canPlayCard(
        player,
        Card(Suit::Spades, Rank::Seven),
        trick,
        Suit::Spades
    ));
}

QTEST_MAIN(TestBeloteRules)

#include "tst_beloterules.moc"
