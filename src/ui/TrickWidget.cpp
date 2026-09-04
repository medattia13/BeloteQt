#include "TrickWidget.h"

#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>

TrickWidget::TrickWidget(QWidget* parent)
    : QWidget(parent)
{
    setupUi();
}

void TrickWidget::setupUi()
{
    auto* mainLayout = new QVBoxLayout(this);

    /*
     * Create the table area.
     */
    auto* table = new QFrame(this);

    table->setMinimumSize(400, 300);

    table->setStyleSheet(
        "QFrame {"
        "    background-color: #176b3a;"
        "    border: 2px solid #0d4d2a;"
        "    border-radius: 20px;"
        "}"
    );

    /*
     * Layout for cards.
     *
     * We keep this empty for now.
     * Cards will be added when the Game class exposes
     * the current Trick.
     */
    auto* tableLayout = new QVBoxLayout(table);

    auto* label = new QLabel(tr("Current Trick"), table);

    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet(
        "QLabel {"
        "    color: white;"
        "    font-size: 16px;"
        "    font-weight: bold;"
        "}"
    );

    tableLayout->addWidget(label);

    mainLayout->addWidget(
        table,
        1,
        Qt::AlignCenter
    );

    setLayout(mainLayout);
}

void TrickWidget::clear()
{
    /*
     * The actual card widgets will be removed here once
     * TrickWidget receives the current Trick from Game.
     *
     * For now there is nothing to clear because the widget
     * only displays the table.
     */
}

void TrickWidget::updateTrick()
{
    /*
     * TODO:
     *
     * Once Game exposes the current Trick, this method
     * should:
     *
     * 1. Clear the current card widgets.
     * 2. Get the cards from the Trick.
     * 3. Create a CardWidget for each card.
     * 4. Position the cards on the table.
     *
     * Example:
     *
     * const Trick& trick = ...
     *
     * for (const Card& card : trick.cards()) {
     *     ...
     * }
     */
}
