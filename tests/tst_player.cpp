#include <QtTest>

#include "../src/model/Player.h"

#include <stdexcept>

class TestPlayer : public QObject
{
    Q_OBJECT

private slots:
    void createsPlayer();
    void startsWithEmptyHand();

    void addCard();
    void removeCard();

    void removeInvalidIndex();
};

void TestPlayer::createsPlayer()
{
    Player player(1, "Alice");

    QCOMPARE(player.id(), 1);
    QCOMPARE(player.name(), QString("Alice"));
}

void TestPlayer::startsWithEmptyHand()
{
    Player player(1, "Alice");

    QVERIFY(player.hand().empty());
}

void TestPlayer::addCard()
{
    Player player(1, "Alice");

    Card card(Suit::Hearts, Rank::Ace);

    player.addCard(card);

    QCOMPARE(static_cast<int>(player.hand().size()), 1);

    QCOMPARE(player.hand()[0].suit(), Suit::Hearts);
    QCOMPARE(player.hand()[0].rank(), Rank::Ace);
}

void TestPlayer::removeCard()
{
    Player player(1, "Alice");

    player.addCard(Card(Suit::Hearts, Rank::Ace));
    player.addCard(Card(Suit::Clubs, Rank::King));

    QCOMPARE(static_cast<int>(player.hand().size()), 2);

    player.removeCard(0);

    QCOMPARE(static_cast<int>(player.hand().size()), 1);

    QCOMPARE(player.hand()[0].suit(), Suit::Clubs);
    QCOMPARE(player.hand()[0].rank(), Rank::King);
}

void TestPlayer::removeInvalidIndex()
{
    Player player(1, "Alice");

    player.addCard(Card(Suit::Hearts, Rank::Ace));

    QVERIFY_EXCEPTION_THROWN(
        player.removeCard(-1),
        std::out_of_range
        );

    QVERIFY_EXCEPTION_THROWN(
        player.removeCard(1),
        std::out_of_range
        );
}

QTEST_MAIN(TestPlayer)

#include "tst_player.moc"
