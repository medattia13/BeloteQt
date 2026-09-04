#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>

#include "model/Card.h"

class GameController;
class PlayerWidget;
class TrickWidget;
class ScoreWidget;

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(GameController* controller,
                        QWidget* parent = nullptr);

public slots:
    void updateGame();
    void cardPlayed(int playerId, int cardIndex);
    void showTrumpSelection();

signals:
    void cardClicked(int cardIndex);
    void trumpSelected(Suit suit);

private:
    void setupUi();
    void setupConnections();
    void refresh();
    GameController* m_controller;

    PlayerWidget* m_players[4];

    TrickWidget* m_trickWidget;
    ScoreWidget* m_scoreWidget;
};

#endif // GAMEWIDGET_H
