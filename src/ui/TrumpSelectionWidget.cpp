#include "TrumpSelectionWidget.h"

#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>

TrumpSelectionWidget::TrumpSelectionWidget(QWidget* parent)
    : QDialog(parent)
{
    setupUi();
}

void TrumpSelectionWidget::setupUi()
{
    setWindowTitle(tr("Choose Trump"));
    setModal(true);
    setFixedSize(350, 250);

    auto* mainLayout = new QVBoxLayout(this);

    auto* gridLayout = new QGridLayout();

    /*
     * Hearts
     */
    auto* heartsButton = new QPushButton(
        QString::fromUtf8("♥"),
        this
    );

    /*
     * Diamonds
     */
    auto* diamondsButton = new QPushButton(
        QString::fromUtf8("♦"),
        this
    );

    /*
     * Clubs
     */
    auto* clubsButton = new QPushButton(
        QString::fromUtf8("♣"),
        this
    );

    /*
     * Spades
     */
    auto* spadesButton = new QPushButton(
        QString::fromUtf8("♠"),
        this
    );

    const QList<QPushButton*> buttons = {
        heartsButton,
        diamondsButton,
        clubsButton,
        spadesButton
    };

    for (QPushButton* button : buttons) {
        button->setMinimumSize(120, 80);

        button->setStyleSheet(
            "QPushButton {"
            "    font-size: 32px;"
            "    border: 1px solid #cccccc;"
            "    border-radius: 8px;"
            "    background-color: white;"
            "}"
            ""
            "QPushButton:hover {"
            "    background-color: #eeeeee;"
            "}"
            ""
            "QPushButton:pressed {"
            "    background-color: #dddddd;"
            "}"
        );
    }

    /*
     * Hearts and diamonds are red.
     */
    heartsButton->setStyleSheet(
        "QPushButton {"
        "    color: #c62828;"
        "    font-size: 32px;"
        "    border: 1px solid #cccccc;"
        "    border-radius: 8px;"
        "    background-color: white;"
        "}"
        ""
        "QPushButton:hover {"
        "    background-color: #eeeeee;"
        "}"
    );

    diamondsButton->setStyleSheet(
        "QPushButton {"
        "    color: #c62828;"
        "    font-size: 32px;"
        "    border: 1px solid #cccccc;"
        "    border-radius: 8px;"
        "    background-color: white;"
        "}"
        ""
        "QPushButton:hover {"
        "    background-color: #eeeeee;"
        "}"
    );

    /*
     * Add buttons to grid.
     */
    gridLayout->addWidget(heartsButton,    0, 0);
    gridLayout->addWidget(diamondsButton,  0, 1);
    gridLayout->addWidget(clubsButton,     1, 0);
    gridLayout->addWidget(spadesButton,    1, 1);

    mainLayout->addLayout(gridLayout);

    /*
     * Selecting a suit emits the signal and closes
     * the dialog.
     */
    connect(
        heartsButton,
        &QPushButton::clicked,
        this,
        [this]()
        {
            emit suitSelected(Suit::Hearts);
            accept();
        }
    );

    connect(
        diamondsButton,
        &QPushButton::clicked,
        this,
        [this]()
        {
            emit suitSelected(Suit::Diamonds);
            accept();
        }
    );

    connect(
        clubsButton,
        &QPushButton::clicked,
        this,
        [this]()
        {
            emit suitSelected(Suit::Clubs);
            accept();
        }
    );

    connect(
        spadesButton,
        &QPushButton::clicked,
        this,
        [this]()
        {
            emit suitSelected(Suit::Spades);
            accept();
        }
    );
}
