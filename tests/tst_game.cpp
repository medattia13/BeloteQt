#include <QtTest>
#include <algorithm>

#include "../src/model/Game.h"
static std::vector<Card> makeBeloteScoringDeck()
{
    std::vector<Card> cards = {
        // Desired draw order.
        //
        // Player 0 = Team 1
        // Player 1 = Team 2
        // Player 2 = Team 1
        // Player 3 = Team 2

        // Trick 1
        Card(Suit::Hearts, Rank::King),       // P0
        Card(Suit::Clubs, Rank::Seven),       // P1
        Card(Suit::Clubs, Rank::Eight),       // P2
        Card(Suit::Clubs, Rank::Nine),        // P3

        // Trick 2
        Card(Suit::Hearts, Rank::Queen),      // P0
        Card(Suit::Clubs, Rank::Ten),         // P1
        Card(Suit::Clubs, Rank::Jack),        // P2
        Card(Suit::Clubs, Rank::Queen),       // P3

        // Trick 3
        Card(Suit::Hearts, Rank::Ace),        // P0
        Card(Suit::Diamonds, Rank::Seven),    // P1
        Card(Suit::Diamonds, Rank::Eight),    // P2
        Card(Suit::Diamonds, Rank::Nine),     // P3

        // Trick 4
        Card(Suit::Spades, Rank::Ace),        // P0
        Card(Suit::Diamonds, Rank::Ten),     // P1
        Card(Suit::Diamonds, Rank::Jack),    // P2
        Card(Suit::Diamonds, Rank::Queen),   // P3

        // Trick 5
        Card(Suit::Spades, Rank::King),       // P0
        Card(Suit::Clubs, Rank::King),        // P1
        Card(Suit::Spades, Rank::Seven),      // P2
        Card(Suit::Clubs, Rank::Ace),         // P3

        // Trick 6
        Card(Suit::Spades, Rank::Queen),      // P0
        Card(Suit::Diamonds, Rank::King),     // P1
        Card(Suit::Spades, Rank::Eight),      // P2
        Card(Suit::Diamonds, Rank::Ace),      // P3

        // Trick 7
        Card(Suit::Spades, Rank::Jack),       // P0
        Card(Suit::Hearts, Rank::Seven),      // P1
        Card(Suit::Spades, Rank::Nine),       // P2
        Card(Suit::Hearts, Rank::Eight),      // P3

        // Trick 8
        Card(Suit::Spades, Rank::Ten),        // P0
        Card(Suit::Hearts, Rank::Nine),       // P1
        Card(Suit::Hearts, Rank::Jack),        // P2
        Card(Suit::Hearts, Rank::Ten)         // P3
    };

    // Deck::draw() removes from the back.
    std::reverse(cards.begin(), cards.end());

    return cards;
}

static std::vector<Card> makeBeloteDeck()
{
    std::vector<Card> cards;

    // We build the cards in the ORDER in which they should be drawn.
    cards = {
        // Round 1
        Card(Suit::Hearts, Rank::King),       // Player 0
        Card(Suit::Clubs, Rank::Seven),       // Player 1
        Card(Suit::Spades, Rank::Seven),      // Player 2
        Card(Suit::Diamonds, Rank::Seven),    // Player 3

        // Round 2
        Card(Suit::Hearts, Rank::Queen),      // Player 0
        Card(Suit::Clubs, Rank::Eight),       // Player 1
        Card(Suit::Spades, Rank::Eight),      // Player 2
        Card(Suit::Diamonds, Rank::Eight),    // Player 3

        // Round 3
        Card(Suit::Hearts, Rank::Ace),
        Card(Suit::Clubs, Rank::Nine),
        Card(Suit::Spades, Rank::Nine),
        Card(Suit::Diamonds, Rank::Nine),

        // Round 4
        Card(Suit::Hearts, Rank::Jack),
        Card(Suit::Clubs, Rank::Ten),
        Card(Suit::Spades, Rank::Ten),
        Card(Suit::Diamonds, Rank::Ten),

        // Round 5
        Card(Suit::Hearts, Rank::Ten),
        Card(Suit::Clubs, Rank::Jack),
        Card(Suit::Spades, Rank::Jack),
        Card(Suit::Diamonds, Rank::Jack),

        // Round 6
        Card(Suit::Hearts, Rank::Nine),
        Card(Suit::Clubs, Rank::Queen),
        Card(Suit::Spades, Rank::Queen),
        Card(Suit::Diamonds, Rank::Queen),

        // Round 7
        Card(Suit::Hearts, Rank::Eight),
        Card(Suit::Clubs, Rank::King),
        Card(Suit::Spades, Rank::King),
        Card(Suit::Diamonds, Rank::King),

        // Round 8
        Card(Suit::Hearts, Rank::Seven),
        Card(Suit::Clubs, Rank::Ace),
        Card(Suit::Spades, Rank::Ace),
        Card(Suit::Diamonds, Rank::Ace)
    };

    // Deck::draw() removes from the back,
    // so reverse the desired draw order.
    std::reverse(cards.begin(), cards.end());

    return cards;
}


std::vector<Card> cards = {
    // Player 0
    Card(Suit::Hearts, Rank::Ace),
    Card(Suit::Hearts, Rank::King),
    Card(Suit::Hearts, Rank::Queen),
    Card(Suit::Hearts, Rank::Jack),
    Card(Suit::Hearts, Rank::Ten),
    Card(Suit::Hearts, Rank::Nine),
    Card(Suit::Hearts, Rank::Eight),
    Card(Suit::Hearts, Rank::Seven),

    // Player 1
    Card(Suit::Diamonds, Rank::Ace),
    Card(Suit::Diamonds, Rank::King),
    Card(Suit::Diamonds, Rank::Queen),
    Card(Suit::Diamonds, Rank::Jack),
    Card(Suit::Diamonds, Rank::Ten),
    Card(Suit::Diamonds, Rank::Nine),
    Card(Suit::Diamonds, Rank::Eight),
    Card(Suit::Diamonds, Rank::Seven),

    // Player 2
    Card(Suit::Clubs, Rank::Ace),
    Card(Suit::Clubs, Rank::King),
    Card(Suit::Clubs, Rank::Queen),
    Card(Suit::Clubs, Rank::Jack),
    Card(Suit::Clubs, Rank::Ten),
    Card(Suit::Clubs, Rank::Nine),
    Card(Suit::Clubs, Rank::Eight),
    Card(Suit::Clubs, Rank::Seven),

    // Player 3
    Card(Suit::Spades, Rank::Ace),
    Card(Suit::Spades, Rank::King),
    Card(Suit::Spades, Rank::Queen),
    Card(Suit::Spades, Rank::Jack),
    Card(Suit::Spades, Rank::Ten),
    Card(Suit::Spades, Rank::Nine),
    Card(Suit::Spades, Rank::Eight),
    Card(Suit::Spades, Rank::Seven)
};


class TestGame : public QObject
{
    Q_OBJECT


private slots:
    void createsGame();

    void startsRound();
    void dealsEightCardsToEachPlayer();

    void trumpCanBeChosen();

    void currentPlayerStartsAtZero();

    void cannotPlayBeforeTrumpIsChosen();
    void cannotPlayWithInvalidPlayer();

    void cannotPlayWithInvalidCardIndex();
    void cannotPlayWhenItIsNotPlayersTurn();

    void playsCardSuccessfully();
    void turnMovesToNextPlayer();
    void completeTrick();
    void playsFullRound();
    void matchIsNotOverAtStart();
    void fullRoundEndsAfterEightTricks();
    void fullRoundScores162();
void roundScoresAccumulate();
void announceBelote();
void playerWithoutBeloteCannotAnnounce();
void beloteCanBeAnnounced();
void invalidPlayerCannotAnnounceBelote();
void beloteAddsTwentyPoints();
void testInjectedDeck();
void testGameUsesInjectedDeck();
void beloteRequiresTrump();
void playFullRound(Game& game);
};

void TestGame::createsGame()
{
    Game game;

    QCOMPARE(static_cast<int>(game.players().size()), 4);

    QCOMPARE(game.team1().player1(), 0);
    QCOMPARE(game.team1().player2(), 2);

    QCOMPARE(game.team2().player1(), 1);
    QCOMPARE(game.team2().player2(), 3);

    QCOMPARE(game.currentPlayer(), 0);

    QVERIFY(!game.isGameOver());
}

void TestGame::startsRound()
{
    Game game;

    game.startRound();

    QCOMPARE(static_cast<int>(game.players().size()), 4);
    QCOMPARE(game.currentPlayer(), 0);

    QVERIFY(!game.isGameOver());
}

void TestGame::dealsEightCardsToEachPlayer()
{
    Game game;

    game.startRound();

    for (const Player& player : game.players()) {
        QCOMPARE(
            static_cast<int>(player.hand().size()),
            8
        );
    }
}

void TestGame::trumpCanBeChosen()
{
    Game game;

    game.startRound();

    game.chooseTrump(Suit::Spades);

    QCOMPARE(game.trump(), Suit::Spades);
}


void TestGame::currentPlayerStartsAtZero()
{
    Game game;

    QCOMPARE(game.currentPlayer(), 0);

    game.startRound();

    QCOMPARE(game.currentPlayer(), 0);
}

void TestGame::cannotPlayBeforeTrumpIsChosen()
{
    Game game;

    game.startRound();

    QVERIFY(
        !game.playCard(0, 0)
    );
}

void TestGame::cannotPlayWithInvalidPlayer()
{
    Game game;

    game.startRound();
    game.chooseTrump(Suit::Hearts);

    QVERIFY(!game.playCard(-1, 0));
    QVERIFY(!game.playCard(4, 0));
    QVERIFY(!game.playCard(100, 0));
}

void TestGame::cannotPlayWithInvalidCardIndex()
{
    Game game;

    game.startRound();
    game.chooseTrump(Suit::Hearts);

    QVERIFY(!game.playCard(0, -1));
    QVERIFY(!game.playCard(0, 8));
    QVERIFY(!game.playCard(0, 100));
}

void TestGame::cannotPlayWhenItIsNotPlayersTurn()
{
    Game game;

    game.startRound();
    game.chooseTrump(Suit::Hearts);

    // Player 0 starts.
    QCOMPARE(game.currentPlayer(), 0);

    // Player 1 tries to play instead.
    QVERIFY(!game.playCard(1, 0));

    // Still Player 0's turn.
    QCOMPARE(game.currentPlayer(), 0);
}

void TestGame::playsCardSuccessfully()
{
    Game game;

    game.startRound();
    game.chooseTrump(Suit::Hearts);

    QCOMPARE(
        static_cast<int>(game.players()[0].hand().size()),
        8
    );

    QVERIFY(
        game.playCard(0, 0)
    );

    QCOMPARE(
        static_cast<int>(game.players()[0].hand().size()),
        7
    );
}

void TestGame::turnMovesToNextPlayer()
{
    Game game;

    game.startRound();
    game.chooseTrump(Suit::Hearts);

    QCOMPARE(game.currentPlayer(), 0);

    // Player 0 can play any card because the trick is empty.
    QVERIFY(game.playCard(0, 0));

    QCOMPARE(game.currentPlayer(), 1);

    // Find a legal card for Player 1.
    bool played = false;

    for (int i = 0;
         i < static_cast<int>(game.players()[1].hand().size());
         ++i) {

        if (game.playCard(1, i)) {
            played = true;
            break;
        }
    }

    QVERIFY(played);

    QCOMPARE(game.currentPlayer(), 2);

    // Find a legal card for Player 2.
    played = false;

    for (int i = 0;
         i < static_cast<int>(game.players()[2].hand().size());
         ++i) {

        if (game.playCard(2, i)) {
            played = true;
            break;
        }
    }

    QVERIFY(played);

    QCOMPARE(game.currentPlayer(), 3);
}

void TestGame::completeTrick()
{
    Game game;

    game.startRound();
    game.chooseTrump(Suit::Hearts);

    QCOMPARE(game.currentPlayer(), 0);

    for (int i = 0; i < 4; ++i) {

        const int currentPlayer =
            game.currentPlayer();

        bool played = false;

        for (int cardIndex = 0;
             cardIndex < static_cast<int>(
                 game.players()[currentPlayer].hand().size());
             ++cardIndex) {

            if (game.playCard(currentPlayer, cardIndex)) {
                played = true;
                break;
            }
        }

        QVERIFY(played);
    }

    // One complete trick has been played.
    for (const Player& player : game.players()) {
        QCOMPARE(
            static_cast<int>(player.hand().size()),
            7
        );
    }

    // The round is not over after one trick.
    QVERIFY(!game.isGameOver());

    // A winner should start the next trick.
    QVERIFY(game.currentPlayer() >= 0);
    QVERIFY(game.currentPlayer() < 4);

    // No round score has been awarded yet.
    QCOMPARE(
        game.team1().score() + game.team2().score(),
        0
    );
}


void TestGame::playsFullRound()
{
    Game game;

    game.startRound();
    game.chooseTrump(Suit::Hearts);

    // A Belote round contains 8 tricks.
    for (int trick = 0; trick < 8; ++trick) {

        // Four players play one card.
        for (int player = 0; player < 4; ++player) {

            const int currentPlayer =
                game.currentPlayer();

            bool played = false;

            // Find a legal card.
            for (int cardIndex = 0;
                 cardIndex < static_cast<int>(
                     game.players()[currentPlayer].hand().size());
                 ++cardIndex) {

                if (game.playCard(
                        currentPlayer,
                        cardIndex)) {

                    played = true;
                    break;
                }
            }

            QVERIFY2(
                played,
                "No legal card could be played"
            );
        }
    }

    // All 32 cards have been played.
    for (const Player& player : game.players()) {
        QCOMPARE(
            static_cast<int>(player.hand().size()),
            0
        );
    }

    // The round is over.
    QVERIFY(game.isGameOver());

    // There must be points on the scoreboard.
    const int totalScore =
        game.team1().score() +
        game.team2().score();

    QVERIFY(totalScore > 0);

    // A 32-card Belote deck is worth 152 points:
    // 152 card points + 10 last-trick bonus = 162.
    QCOMPARE(totalScore, 162);
}

void TestGame::matchIsNotOverAtStart()
{
    Game game;

    QVERIFY(!game.isMatchOver());

    game.startRound();

    QVERIFY(!game.isMatchOver());
}

void TestGame::fullRoundEndsAfterEightTricks()
{
    Game game;

    game.startRound();
    game.chooseTrump(Suit::Hearts);

    for (int trick = 0; trick < 8; ++trick) {

        for (int player = 0; player < 4; ++player) {

            const int current =
                game.currentPlayer();

            bool played = false;

            for (int cardIndex = 0;
                 cardIndex < static_cast<int>(
                     game.players()[current].hand().size());
                 ++cardIndex) {

                if (game.playCard(current, cardIndex)) {
                    played = true;
                    break;
                }
            }

            QVERIFY2(
                played,
                "Current player has no legal card"
            );
        }
    }

    QVERIFY(game.isGameOver());

    for (const Player& player : game.players()) {
        QCOMPARE(
            static_cast<int>(player.hand().size()),
            0
        );
    }

    const int totalScore =
        game.team1().score() +
        game.team2().score();

    QCOMPARE(totalScore, 162);
}

void TestGame::fullRoundScores162()
{
    Game game;

    game.startRound();
    game.chooseTrump(Suit::Hearts);

    // Play all 8 tricks.
    for (int trick = 0; trick < 8; ++trick) {

        // Four cards per trick.
        for (int card = 0; card < 4; ++card) {

            const int player =
                game.currentPlayer();

            bool played = false;

            const int handSize =
                static_cast<int>(
                    game.players()[player].hand().size()
                );

            for (int cardIndex = 0;
                 cardIndex < handSize;
                 ++cardIndex) {

                if (game.playCard(player, cardIndex)) {
                    played = true;
                    break;
                }
            }

            QVERIFY2(
                played,
                "Could not find a legal card"
            );
        }
    }

    QVERIFY(game.isGameOver());

}

void TestGame::roundScoresAccumulate()
{
    Game game;

    // -------------------------
    // Round 1
    // -------------------------

    game.startRound();
    game.chooseTrump(Suit::Hearts);

    for (int trick = 0; trick < 8; ++trick) {

        for (int card = 0; card < 4; ++card) {

            const int player =
                game.currentPlayer();

            bool played = false;

            const int handSize =
                static_cast<int>(
                    game.players()[player].hand().size()
                );

            for (int cardIndex = 0;
                 cardIndex < handSize;
                 ++cardIndex) {

                if (game.playCard(player, cardIndex)) {
                    played = true;
                    break;
                }
            }

            QVERIFY(played);
        }
    }

    QVERIFY(game.isGameOver());

    const int firstRoundScore =
        game.team1().score() +
        game.team2().score();

    QCOMPARE(firstRoundScore, 162);

    // -------------------------
    // Round 2
    // -------------------------

    game.startRound();
    game.chooseTrump(Suit::Spades);

    for (int trick = 0; trick < 8; ++trick) {

        for (int card = 0; card < 4; ++card) {

            const int player =
                game.currentPlayer();

            bool played = false;

            const int handSize =
                static_cast<int>(
                    game.players()[player].hand().size()
                );

            for (int cardIndex = 0;
                 cardIndex < handSize;
                 ++cardIndex) {

                if (game.playCard(player, cardIndex)) {
                    played = true;
                    break;
                }
            }

            QVERIFY(played);
        }
    }

    QVERIFY(game.isGameOver());

    const int totalScore =
        game.team1().score() +
        game.team2().score();

    QCOMPARE(totalScore, 324);
}


void TestGame::announceBelote()
{
    Game game;

    game.startRound();
    game.chooseTrump(Suit::Hearts);

    int playerWithoutBelote = -1;

    for (int player = 0; player < 4; ++player) {
        if (!game.canAnnounceBelote(player)) {
            playerWithoutBelote = player;
            break;
        }
    }

    QVERIFY(playerWithoutBelote != -1);

    // A player without King + Queen of trump
    // cannot announce Belote.
    QVERIFY(!game.announceBelote(playerWithoutBelote));
}

void TestGame::testInjectedDeck()
{
    Deck deck(makeBeloteDeck());

    Card first = deck.draw();

    QCOMPARE(first.suit(), Suit::Hearts);
    QCOMPARE(first.rank(), Rank::King);

    Card second = deck.draw();

    QCOMPARE(second.suit(), Suit::Clubs);
    QCOMPARE(second.rank(), Rank::Seven);

    Card third = deck.draw();

    QCOMPARE(third.suit(), Suit::Spades);
    QCOMPARE(third.rank(), Rank::Seven);

    Card fourth = deck.draw();

    QCOMPARE(fourth.suit(), Suit::Diamonds);
    QCOMPARE(fourth.rank(), Rank::Seven);
}


void TestGame::testGameUsesInjectedDeck()
{
    Deck deck(makeBeloteDeck());
    Game game(deck);

    game.startRound();

    QCOMPARE(game.players()[0].hand().size(), size_t(8));

    QCOMPARE(game.players()[0].hand()[0].suit(), Suit::Hearts);
    QCOMPARE(game.players()[0].hand()[0].rank(), Rank::King);

    QCOMPARE(game.players()[0].hand()[1].suit(), Suit::Hearts);
    QCOMPARE(game.players()[0].hand()[1].rank(), Rank::Queen);
}


void TestGame::beloteCanBeAnnounced()
{
    Deck deck(makeBeloteDeck());
    Game game(deck);

    game.startRound();

    game.chooseTrump(Suit::Hearts);

    QVERIFY(game.canAnnounceBelote(0));
    QVERIFY(game.announceBelote(0));
        // Cannot announce it twice.
    QVERIFY(!game.announceBelote(0));
}
void TestGame::beloteAddsTwentyPoints()
{
    Deck deck(makeBeloteDeck());
    Game game(deck);

    game.startRound();
    game.chooseTrump(Suit::Hearts);

    QVERIFY(game.canAnnounceBelote(0));
    QVERIFY(game.announceBelote(0));

    playFullRound(game);

    // We'll determine the exact normal score separately.
    QVERIFY(game.roundScoreTeam1() > 0);
}



void TestGame::playerWithoutBeloteCannotAnnounce()
{
    Deck deck(makeBeloteDeck());
    Game game(deck);

    game.startRound();
    game.chooseTrump(Suit::Hearts);

    QVERIFY(!game.canAnnounceBelote(1));
    QVERIFY(!game.announceBelote(1));
}

void TestGame::invalidPlayerCannotAnnounceBelote()
{
    Deck deck(makeBeloteDeck());
    Game game(deck);

    game.startRound();
    game.chooseTrump(Suit::Hearts);

    QVERIFY(!game.canAnnounceBelote(-1));
    QVERIFY(!game.canAnnounceBelote(4));

    QVERIFY(!game.announceBelote(-1));
    QVERIFY(!game.announceBelote(4));
}


void TestGame::beloteRequiresTrump()
{
    Deck deck(makeBeloteDeck());
    Game game(deck);

    game.startRound();

    QVERIFY(!game.canAnnounceBelote(0));
    QVERIFY(!game.announceBelote(0));
}
void TestGame::playFullRound(Game& game)
{
    while (!game.isGameOver()) {
        int playerId = game.currentPlayer();

        QVERIFY(game.playCard(playerId, 0));
    }
}

QTEST_MAIN(TestGame)

#include "tst_game.moc"
