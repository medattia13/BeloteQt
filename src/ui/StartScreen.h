#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QWidget>

class QPushButton;

class StartScreen : public QWidget
{
    Q_OBJECT

public:
    explicit StartScreen(QWidget* parent = nullptr);

signals:
    void newGameRequested();
    void settingsRequested();

private:
    QPushButton* m_newGameButton;
    QPushButton* m_settingsButton;
};

#endif
