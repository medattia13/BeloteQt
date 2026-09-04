#include "PlayerHandWidget.h"

#include "CardWidget.h"
#include "model/Player.h"

PlayerHandWidget::PlayerHandWidget(QWidget* parent)
    : QWidget(parent),
    m_layout(new QHBoxLayout(this))
{
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->setSpacing(10);
}

void PlayerHandWidget::setInteractive(bool interactive)
{
    m_interactive = interactive;

    refresh();
}
void PlayerHandWidget::refresh()
{
    clearCards();

    if (!m_player) {
        return;
    }

    const auto& cards = m_player->hand();

    for (int i = 0; i < static_cast<int>(cards.size()); ++i) {
        auto* cardWidget = new CardWidget(
            cards[i],
            i,
            this
            );

        cardWidget->setInteractive(m_interactive);

        connect(
            cardWidget,
            &CardWidget::cardClicked,
            this,
            &PlayerHandWidget::cardClicked
            );

        m_layout->addWidget(cardWidget);
    }

    m_layout->addStretch();
}


void PlayerHandWidget::setPlayer(const Player* player)
{
    m_player = player;
    refresh();
}



void PlayerHandWidget::clearCards()
{
    while (m_layout->count() > 0) {
        QLayoutItem* item = m_layout->takeAt(0);

        if (QWidget* widget = item->widget()) {
            delete widget;
        }

        delete item;
    }
}


