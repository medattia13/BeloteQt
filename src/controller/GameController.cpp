#include "GameController.h"

GameController::GameController(QObject* parent)
    : QObject(parent)
{
}

const Game& GameController::game() const
{
    return m_game;
}

void GameController::startGame()
{
    m_game.startRound();

    emit gameUpdated();
    emit trumpSelectionRequired();
}

void GameController::selectTrump(Suit suit)
{
    m_game.chooseTrump(suit);

    emit gameUpdated();
}

void GameController::playCard(int cardIndex)
{
    const int playerId = m_game.currentPlayer();

    if (!m_game.playCard(playerId, cardIndex)) {
        return;
    }

    emit cardPlayed(playerId, cardIndex);
    emit gameUpdated();

    if (m_game.isRoundOver()) {
        // For now we need to determine which team won the round.
        // We'll implement this properly when the controller
        // handles round/match flow.
        return;
    }
}
