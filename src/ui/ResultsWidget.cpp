#include "ResultsWidget.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

ResultsWidget::ResultsWidget(QWidget* parent)
    : QWidget(parent),
      m_resultLabel(new QLabel(this)),
      m_newGameButton(new QPushButton(tr("New Game"), this))
{
    auto* layout = new QVBoxLayout(this);

    m_resultLabel->setAlignment(Qt::AlignCenter);
    m_resultLabel->setStyleSheet(
        "font-size: 28px;"
        "font-weight: bold;"
    );

    m_newGameButton->setFixedWidth(160);

    layout->addStretch();
    layout->addWidget(m_resultLabel);
    layout->addSpacing(30);
    layout->addWidget(m_newGameButton, 0, Qt::AlignCenter);
    layout->addStretch();

    setLayout(layout);

    connect(
        m_newGameButton,
        &QPushButton::clicked,
        this,
        &ResultsWidget::newGameRequested
    );
}

void ResultsWidget::setWinningTeam(int team)
{
    m_resultLabel->setText(
        tr("Team %1 wins!").arg(team)
    );
}
