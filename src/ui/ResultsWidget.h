#ifndef RESULTSWIDGET_H
#define RESULTSWIDGET_H

#include <QWidget>

class QLabel;
class QPushButton;

class ResultsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ResultsWidget(QWidget* parent = nullptr);

    void setWinningTeam(int team);

signals:
    void newGameRequested();

private:
    QLabel* m_resultLabel;
    QPushButton* m_newGameButton;
};

#endif
