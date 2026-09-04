#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>

class QLabel;
class Player;
class PlayerHandWidget;

class PlayerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerWidget(QWidget* parent = nullptr);

    void setPlayer(Player* player);
    void setCurrentPlayer(bool current);
    void setInteractive(bool enabled);
    void setTeam(int team);

    PlayerHandWidget* handWidget() const;

signals:
    void cardClicked(int cardIndex);

private:
    void setupUi();
    void setupConnections();
    void updatePlayerInfo();

    Player* m_player = nullptr;

    QLabel* m_nameLabel;
    QLabel* m_teamLabel;
    QLabel* m_statusLabel;
    PlayerHandWidget* m_handWidget;

        int m_team = 0;
};

#endif
