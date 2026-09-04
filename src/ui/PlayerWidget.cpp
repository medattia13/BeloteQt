#include "PlayerWidget.h"

#include "model/Player.h"
#include "PlayerHandWidget.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>


PlayerWidget::PlayerWidget(QWidget* parent)
    : QWidget(parent),
    m_nameLabel(new QLabel(this)),
    m_teamLabel(new QLabel(this)),
    m_statusLabel(new QLabel(this)),
    m_handWidget(new PlayerHandWidget(this))
{
    setupUi();
    setupConnections();
}
void PlayerWidget::setupUi()
{
    auto* mainLayout = new QVBoxLayout(this);

    auto* infoLayout = new QHBoxLayout();

    infoLayout->addWidget(m_nameLabel);
    infoLayout->addWidget(m_teamLabel);
    infoLayout->addWidget(m_statusLabel);

    mainLayout->addLayout(infoLayout);
    mainLayout->addWidget(m_handWidget);

    setLayout(mainLayout);
}
void PlayerWidget::setupConnections()
{
    connect(
        m_handWidget,
        &PlayerHandWidget::cardClicked,
        this,
        &PlayerWidget::cardClicked
        );
}
void PlayerWidget::setPlayer(Player* player)
{
    m_player = player;
        m_handWidget->setPlayer(player);
    updatePlayerInfo();
}

void PlayerWidget::setTeam(int team)
{
    m_team = team;

    updatePlayerInfo();
}

void PlayerWidget::updatePlayerInfo()
{
    if (!m_player) {
        m_nameLabel->clear();
        m_teamLabel->clear();
        return;
    }


    m_nameLabel->setText(m_player->name());

    m_teamLabel->setText(tr("Team %1").arg(m_team + 1));
}

void PlayerWidget::setInteractive(bool interactive)
{
    m_handWidget->setInteractive(interactive);
}

void PlayerWidget::setCurrentPlayer(bool current)
{
    if (current) {
        m_statusLabel->setText(tr("Your turn"));

        setStyleSheet(
            "PlayerWidget {"
            "    border: 2px solid #e6c229;"
            "    border-radius: 8px;"
            "    background-color: #fff8d6;"
            "}"
            );
    } else {
        m_statusLabel->setText(QString());

        setStyleSheet(
            "PlayerWidget {"
            "    border: 1px solid #cccccc;"
            "    border-radius: 8px;"
            "    background-color: transparent;"
            "}"
            );
    }
}
PlayerHandWidget* PlayerWidget::handWidget() const
{
    return m_handWidget;
}
