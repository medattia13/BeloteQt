#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>

#include "model/Game.h"

class GameController : public QObject
{
    Q_OBJECT

public:
    explicit GameController(QObject* parent = nullptr);
    Game& game();
    const Game& game() const;

public slots:
    void startGame();
    void selectTrump(Suit suit);
    void playCard(int cardIndex);
signals:
void gameStarted();
    void gameUpdated();
    void trumpSelectionRequired();
    void cardPlayed(int playerId, int cardIndex);
    void roundFinished(int team1Score, int team2Score);
    void gameFinished(int winningTeam);
    bool hasTrump() const;
        void error(const QString& message);
    void stateChanged();
private:
    Game m_game;
};

#endif
