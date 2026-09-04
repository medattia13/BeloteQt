/*Game	Rules and game state
GameController	Commands/actions between UI and Game
MainWindow	Application shell + screen navigation
StartScreen	Start menu
GameWidget	Main game table
PlayerHandWidget	Displays player's cards
CardWidget	Displays/interacts with one card
TrickWidget	Displays current trick
ScoreWidget	Displays scores
TrumpSelectionWidget	Allows trump selection
ResultsWidget	Displays match result
*/
#include "GameWidget.h"

#include "GameController.h"
#include "PlayerWidget.h"
#include "TrickWidget.h"
#include "ScoreWidget.h"
#include "TrumpSelectionWidget.h"
#include "model/Game.h"

#include <QGridLayout>
#include <QVBoxLayout>

GameWidget::GameWidget(GameController* controller,
                       QWidget* parent)
    : QWidget(parent),
    m_controller(controller),
    m_trickWidget(new TrickWidget(this)),
    m_scoreWidget(new ScoreWidget(this))
{
    for (int i = 0; i < 4; ++i) {
        m_players[i] = new PlayerWidget(this);
    }

    setupUi();
    setupConnections();
    refresh();
}



void GameWidget::setupUi()
{
    auto* mainLayout = new QVBoxLayout(this);

    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setSpacing(10);

    /*
     * Score at the top.
     */
    m_scoreWidget->setMinimumHeight(60);

    mainLayout->addWidget(m_scoreWidget);

    /*
     * Main Belote table.
     *
     *                    Player 2
     *
     *             ┌─────────────────┐
     *             │                 │
     * Player 1    │      TRICK      │    Player 3
     *             │                 │
     *             └─────────────────┘
     *
     *                    Player 0
     */
    auto* tableLayout = new QGridLayout();

    tableLayout->setContentsMargins(0, 0, 0, 0);
    tableLayout->setSpacing(10);

    /*
     * Top player.
     */
    tableLayout->addWidget(
        m_players[2],
        0, 1,
        Qt::AlignCenter
        );

    /*
     * Left player.
     */
    tableLayout->addWidget(
        m_players[1],
        1, 0,
        Qt::AlignCenter
        );

    /*
     * Trick in the center.
     */
    tableLayout->addWidget(
        m_trickWidget,
        1, 1
        );

    /*
     * Right player.
     */
    tableLayout->addWidget(
        m_players[3],
        1, 2,
        Qt::AlignCenter
        );

    /*
     * Human player at the bottom.
     */
    tableLayout->addWidget(
        m_players[0],
        2, 1,
        Qt::AlignCenter
        );

    /*
     * Make the center expand.
     */
    tableLayout->setRowStretch(1, 1);
    tableLayout->setColumnStretch(1, 1);

    /*
     * Keep the side players relatively narrow.
     */
    tableLayout->setColumnMinimumWidth(0, 150);
    tableLayout->setColumnMinimumWidth(2, 150);

    mainLayout->addLayout(tableLayout, 1);

    setLayout(mainLayout);
}
void GameWidget::setupConnections()
{
    if (!m_controller) {
        return;
    }

    /*
     * Human player clicked a card.
     */
    connect(
        m_players[0],
        &PlayerWidget::cardClicked,
        this,
        &GameWidget::cardClicked
        );

    /*
     * Send card selection to the controller.
     */
    connect(
        this,
        &GameWidget::cardClicked,
        m_controller,
        &GameController::playCard
        );

    /*
     * General game state update.
     */
    connect(
        m_controller,
        &GameController::gameUpdated,
        this,
        &GameWidget::updateGame
        );

    /*
     * A card was successfully played.
     */
    connect(
        m_controller,
        &GameController::cardPlayed,
        this,
        &GameWidget::cardPlayed
        );

    /*
     * Controller requires trump selection.
     */
    connect(
        m_controller,
        &GameController::trumpSelectionRequired,
        this,
        &GameWidget::showTrumpSelection
        );
}


void GameWidget::updateGame()
{
    refresh();
}

void GameWidget::refresh()
{
    if (!m_controller) {
        return;
    }

    Game& game = m_controller->game();

    /*
     * Score
     */
    m_scoreWidget->setScores(
        game.roundScoreTeam1(),
        game.roundScoreTeam2()
        );

    /*
     * Players
     */
    for (int i = 0; i < 4; ++i) {
        PlayerWidget* playerWidget = m_players[i];

        playerWidget->setPlayer(
            &game.player(i)
            );

        /*
         * Belote teams:
         *
         * Player 0 + Player 2 = Team 1
         * Player 1 + Player 3 = Team 2
         */
        playerWidget->setTeam(
            (i % 2) + 1
            );

        /*
         * Highlight current player.
         */
        playerWidget->setCurrentPlayer(
            game.currentPlayer() == i
            );

        /*
         * Only human player (0) can interact.
         */
        playerWidget->setInteractive(
            i == 0 &&
            game.currentPlayer() == 0 &&
            !game.isRoundOver() &&
            !game.isMatchOver()
            );
    }

    /*
     * Trick
     */
    m_trickWidget->updateTrick();
}




void GameWidget::cardPlayed(int playerId, int cardIndex)
{
    Q_UNUSED(playerId)
    Q_UNUSED(cardIndex)

    refresh();
}


void GameWidget::showTrumpSelection()
{
    TrumpSelectionWidget dialog(this);

    connect(
        &dialog,
        &TrumpSelectionWidget::suitSelected,
        this,
        &GameWidget::trumpSelected
        );

    dialog.exec();
}

