#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QPushButton>

#include "model/Card.h"

class CardWidget : public QPushButton
{
    Q_OBJECT

public:
    explicit CardWidget(const Card& card,
                        int cardIndex,
                        QWidget* parent = nullptr);

    const Card& card() const;
    void setInteractive(bool interactive);
signals:
    void cardClicked(int cardIndex);
protected:
void mousePressEvent(QMouseEvent* event) override;
private:
    Card m_card;
    int m_cardIndex;
        bool m_interactive = false;
};

#endif
