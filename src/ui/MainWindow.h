#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QStackedWidget;

class StartScreen;
class GameWidget;
class SettingsWidget;
class ResultsWidget;

class GameController;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override = default;

private slots:
    void newGame();
    void restartGame();
    void quitGame();

    void showStartScreen();
    void showGameScreen();
    void showSettingsScreen();
    void showResultsScreen(int winningTeam);

private:
    void setupMenu();
    void setupScreens();
    void setupConnections();

    GameController* m_controller = nullptr;

    QStackedWidget* m_stack = nullptr;

    StartScreen* m_startScreen = nullptr;
    GameWidget* m_gameWidget = nullptr;
    SettingsWidget* m_settingsWidget = nullptr;
    ResultsWidget* m_resultsWidget = nullptr;
};

#endif
