#include "CardWidget.h"
#include <QMouseEvent>
CardWidget::CardWidget(const Card& card,
                       int cardIndex,
                       QWidget* parent)
    : QPushButton(parent),
      m_card(card),
      m_cardIndex(cardIndex)
{
    setFixedSize(100, 140);

    connect(
        this,
        &QPushButton::clicked,
        this,
        [this]()
        {
            emit cardClicked(m_cardIndex);
        }
    );
}

const Card& CardWidget::card() const
{
    return m_card;
}
void CardWidget::setInteractive(bool interactive)
{
    m_interactive = interactive;

    if (interactive) {
        setCursor(Qt::PointingHandCursor);
    } else {
        setCursor(Qt::ArrowCursor);
    }
}

void CardWidget::mousePressEvent(QMouseEvent* event)
{
    if (!m_interactive) {
        QWidget::mousePressEvent(event);
        return;
    }

    if (event->button() == Qt::LeftButton) {
        emit cardClicked(m_cardIndex);
    }

    QWidget::mousePressEvent(event);
}

