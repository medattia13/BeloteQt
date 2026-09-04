#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QWidget>

class QLabel;

class ScoreWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScoreWidget(QWidget* parent = nullptr);

    void setScores(int team1, int team2);

private:
    QLabel* m_team1Score;
    QLabel* m_team2Score;
};

#endif
