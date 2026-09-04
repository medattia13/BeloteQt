#ifndef PLAYERHANDWIDGET_H
#define PLAYERHANDWIDGET_H

#include <QHBoxLayout>
#include <QWidget>

class Player;
class CardWidget;

class PlayerHandWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerHandWidget(QWidget* parent = nullptr);

    void setPlayer(const Player* player);
    void setInteractive(bool interactive);

signals:
    void cardClicked(int cardIndex);

private:
    void refresh();
    void clearCards();

    const Player* m_player = nullptr;

    QHBoxLayout* m_layout;
    bool m_interactive = false;
};

#endif // PLAYERHANDWIDGET_H
