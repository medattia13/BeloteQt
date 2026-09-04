#include "StartScreen.h"

#include <QFont>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

StartScreen::StartScreen(QWidget* parent)
    : QWidget(parent),
      m_newGameButton(new QPushButton(tr("New Game"), this)),
      m_settingsButton(new QPushButton(tr("Settings"), this))
{
    auto* mainLayout = new QVBoxLayout(this);

    /*
     * Title
     */
    auto* titleLabel = new QLabel(tr("BELOTE"), this);
    titleLabel->setAlignment(Qt::AlignCenter);

    QFont titleFont;
    titleFont.setPointSize(36);
    titleFont.setBold(true);

    titleLabel->setFont(titleFont);

    /*
     * Subtitle
     */
    auto* subtitleLabel =
        new QLabel(tr("A card game for four players"), this);

    subtitleLabel->setAlignment(Qt::AlignCenter);

    /*
     * Buttons
     */
    m_newGameButton->setMinimumSize(200, 50);
    m_settingsButton->setMinimumSize(200, 50);

    /*
     * Layout
     */
    mainLayout->addStretch();

    mainLayout->addWidget(
        titleLabel,
        0,
        Qt::AlignCenter
    );

    mainLayout->addSpacing(10);

    mainLayout->addWidget(
        subtitleLabel,
        0,
        Qt::AlignCenter
    );

    mainLayout->addSpacing(40);

    mainLayout->addWidget(
        m_newGameButton,
        0,
        Qt::AlignCenter
    );

    mainLayout->addSpacing(10);

    mainLayout->addWidget(
        m_settingsButton,
        0,
        Qt::AlignCenter
    );

    mainLayout->addStretch();

    setLayout(mainLayout);

    /*
     * Signals
     */
    connect(
        m_newGameButton,
        &QPushButton::clicked,
        this,
        &StartScreen::newGameRequested
    );

    connect(
        m_settingsButton,
        &QPushButton::clicked,
        this,
        &StartScreen::settingsRequested
    );
}
