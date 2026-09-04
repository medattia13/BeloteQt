#include "MainWindow.h"

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStackedWidget>

#include "GameController.h"
#include "GameWidget.h"
#include "ResultsWidget.h"
#include "SettingsWidget.h"
#include "StartScreen.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      m_stack(new QStackedWidget(this)),
      m_startScreen(new StartScreen(this)),
      m_controller(new GameController(this)),
      m_gameWidget(new GameWidget(m_controller, this)),
      m_settingsWidget(new SettingsWidget(this)),
      m_resultsWidget(new ResultsWidget(this))

{
    setupMenu();
    setupScreens();
    setupConnections();

    showStartScreen();

    setWindowTitle("Belote");
    resize(1200, 800);
}

void MainWindow::setupMenu()
{
    QMenu* gameMenu = menuBar()->addMenu(tr("&Game"));

    QAction* newGameAction =
        gameMenu->addAction(tr("&New Game"));

    QAction* restartAction =
        gameMenu->addAction(tr("&Restart"));

    gameMenu->addSeparator();

    QAction* quitAction =
        gameMenu->addAction(tr("&Quit"));

    connect(newGameAction,
            &QAction::triggered,
            this,
            &MainWindow::newGame);

    connect(restartAction,
            &QAction::triggered,
            this,
            &MainWindow::restartGame);

    connect(quitAction,
            &QAction::triggered,
            this,
            &MainWindow::quitGame);
    QAction* settingsAction =
        gameMenu->addAction(tr("&Settings"));

    connect(
        settingsAction,
        &QAction::triggered,
        this,
        &MainWindow::showSettingsScreen
        );

}

void MainWindow::setupScreens()
{
    m_stack->addWidget(m_startScreen);
    m_stack->addWidget(m_gameWidget);
    m_stack->addWidget(m_settingsWidget);
    m_stack->addWidget(m_resultsWidget);

    setCentralWidget(m_stack);
}

void MainWindow::setupConnections()
{
    connect(
        m_startScreen,
        &StartScreen::newGameRequested,
        this,
        &MainWindow::newGame
    );

    connect(
        m_controller,
        &GameController::gameUpdated,
        m_gameWidget,
        &GameWidget::updateGame
    );

    connect(
        m_controller,
        &GameController::cardPlayed,
        m_gameWidget,
        &GameWidget::cardPlayed
    );

    connect(
        m_controller,
        &GameController::trumpSelectionRequired,
        m_gameWidget,
        &GameWidget::showTrumpSelection
    );

    connect(
        m_controller,
        &GameController::gameFinished,
        this,
        &MainWindow::showResultsScreen
    );

    connect(
        m_gameWidget,
        &GameWidget::cardClicked,
        m_controller,
        &GameController::playCard
    );

    connect(
        m_gameWidget,
        &GameWidget::trumpSelected,
        m_controller,
        &GameController::selectTrump
    );
    connect(
        m_settingsWidget,
        &SettingsWidget::backRequested,
        this,
        &MainWindow::showStartScreen
        );

}

void MainWindow::newGame()
{
    m_controller->startGame();
    showGameScreen();
}

void MainWindow::restartGame()
{
    m_controller->startGame();
    showGameScreen();
}

void MainWindow::quitGame()
{
    close();
}

void MainWindow::showStartScreen()
{
    m_stack->setCurrentWidget(m_startScreen);
}

void MainWindow::showGameScreen()
{
    m_stack->setCurrentWidget(m_gameWidget);
}

void MainWindow::showSettingsScreen()
{
    m_stack->setCurrentWidget(m_settingsWidget);
}

void MainWindow::showResultsScreen(int winningTeam)
{
    m_resultsWidget->setWinningTeam(winningTeam);
    m_stack->setCurrentWidget(m_resultsWidget);
}
