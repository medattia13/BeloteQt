#include "GameController.h"

GameController::GameController(QObject* parent)
    : QObject(parent)
{
}


const Game& GameController::game() const
{
    return m_game;
}
Game& GameController::game()
{
    return m_game;
}
void GameController::startGame()
{
    m_game.startRound();

    emit gameUpdated();

    // Trump must be selected before cards can be played.
    if (!m_game.trump().has_value()) {
        emit trumpSelectionRequired();
    }
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
        // The card was invalid, so don't notify the UI.
        return;
    }

    emit cardPlayed(playerId, cardIndex);
    emit gameUpdated();

    if (m_game.isMatchOver()) {
        const int winningTeam =
            m_game.roundScoreTeam1() >= m_game.roundScoreTeam2()
                ? 1
                : 2;

        emit gameFinished(winningTeam);
    }
}

