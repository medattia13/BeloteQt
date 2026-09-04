#include "ScoreWidget.h"

#include <QFont>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

ScoreWidget::ScoreWidget(QWidget* parent)
    : QWidget(parent),
      m_team1Score(new QLabel(this)),
      m_team2Score(new QLabel(this))
{
    auto* mainLayout = new QHBoxLayout(this);

    /*
     * Team 1
     */
    auto* team1Layout = new QVBoxLayout();

    auto* team1Label = new QLabel(tr("Team 1"), this);
    team1Label->setAlignment(Qt::AlignCenter);

    m_team1Score->setAlignment(Qt::AlignCenter);

    /*
     * Team 2
     */
    auto* team2Layout = new QVBoxLayout();

    auto* team2Label = new QLabel(tr("Team 2"), this);
    team2Label->setAlignment(Qt::AlignCenter);

    m_team2Score->setAlignment(Qt::AlignCenter);

    /*
     * Score styling
     */
    QFont scoreFont;
    scoreFont.setPointSize(20);
    scoreFont.setBold(true);

    m_team1Score->setFont(scoreFont);
    m_team2Score->setFont(scoreFont);

    /*
     * Team layout
     */
    team1Layout->addWidget(team1Label);
    team1Layout->addWidget(m_team1Score);

    team2Layout->addWidget(team2Label);
    team2Layout->addWidget(m_team2Score);

    mainLayout->addLayout(team1Layout);
    mainLayout->addStretch();
    mainLayout->addLayout(team2Layout);

    setLayout(mainLayout);

    /*
     * Initial scores
     */
    setScores(0, 0);
}

void ScoreWidget::setScores(int team1, int team2)
{
    m_team1Score->setText(QString::number(team1));
    m_team2Score->setText(QString::number(team2));
}
