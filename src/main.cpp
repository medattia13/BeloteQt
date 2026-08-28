#include <QApplication>
#include <QDebug>

#include "model/Card.h"
#include "model/Player.h"
#include "model/Trick.h"
#include "model/Team.h"
#include "model/BeloteRules.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create players
    Player player1(0, "Player 1");
    Player player2(1, "Player 2");
    Player player3(2, "Player 3");
    Player player4(3, "Player 4");

    // Create teams
    Team team1(0, 2);
    Team team2(1, 3);

    // Example cards
    Card tenHearts(Suit::Hearts, Rank::Ten);
    Card jackHearts(Suit::Hearts, Rank::Jack);
    Card aceClubs(Suit::Clubs, Rank::Ace);
    Card sevenSpades(Suit::Spades, Rank::Seven);

    // Give cards to players
    player1.addCard(tenHearts);
    player2.addCard(jackHearts);
    player3.addCard(aceClubs);
    player4.addCard(sevenSpades);

    // Hearts are trump
    const Suit trump = Suit::Hearts;

    // Create a trick
    Trick trick;

    // Player 1 leads with 10 Hearts
    if (BeloteRules::canPlayCard(
            player1,
            tenHearts,
            trick,
            trump)) {

        trick.addCard(player1.id(), tenHearts);
    }

    // Player 2 plays Jack Hearts
    if (BeloteRules::canPlayCard(
            player2,
            jackHearts,
            trick,
            trump)) {

        trick.addCard(player2.id(), jackHearts);
    }

    // Player 3 plays Ace Clubs
    if (BeloteRules::canPlayCard(
            player3,
            aceClubs,
            trick,
            trump)) {

        trick.addCard(player3.id(), aceClubs);
    }

    // Player 4 plays Seven Spades
    if (BeloteRules::canPlayCard(
            player4,
            sevenSpades,
            trick,
            trump)) {

        trick.addCard(player4.id(), sevenSpades);
    }

    // Determine the winner
    if (!trick.cards().empty()) {
        const Suit leadSuit =
            trick.cards().front().second.suit();

        const int winnerId =
            trick.winner(trump, leadSuit);

        qDebug() << "Winner:" << winnerId;
        qDebug() << "Trick points:" << trick.points(trump);
    }

    // Example team scoring
    team1.addPoints(trick.points(trump));

    qDebug() << "Team 1 score:" << team1.score();
    qDebug() << "Team 2 score:" << team2.score();

    return app.exec();
}
