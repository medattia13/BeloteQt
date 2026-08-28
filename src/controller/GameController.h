#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>

#include "Game.h"

class GameController : public QObject
{
    Q_OBJECT

public:
    explicit GameController(QObject* parent = nullptr);

    const Game& game() const;

public slots:
    void startGame();
    void selectTrump(Suit suit);
    void playCard(int cardIndex);

signals:
    void gameUpdated();
    void trumpSelectionRequired();
    void cardPlayed(int playerId, int cardIndex);
    void gameFinished(int winningTeam);

private:
    Game m_game;
};

#endif
