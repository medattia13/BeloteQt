#include "SettingsWidget.h"

#include <QCheckBox>
#include <QComboBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

SettingsWidget::SettingsWidget(QWidget* parent)
    : QWidget(parent),
    m_soundCheckBox(new QCheckBox(this)),
    m_animationCheckBox(new QCheckBox(this)),
    m_languageComboBox(new QComboBox(this)),
    m_player1Name(new QLineEdit(this)),
    m_player2Name(new QLineEdit(this)),
    m_player3Name(new QLineEdit(this)),
    m_player4Name(new QLineEdit(this)),
    m_resetButton(new QPushButton(this)),
    m_backButton(new QPushButton(this))
{
    setupUi();
    setupConnections();
}

void SettingsWidget::setupUi()
{
    auto* mainLayout = new QVBoxLayout(this);

    // Title
    auto* title = new QLabel(tr("Settings"), this);

    QFont titleFont = title->font();
    titleFont.setPointSize(24);
    titleFont.setBold(true);
    title->setFont(titleFont);

    title->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(title);

    // General settings
    auto* generalGroup = new QGroupBox(tr("General"), this);
    auto* generalLayout = new QFormLayout(generalGroup);

    m_soundCheckBox->setText(tr("Enable sound"));
    m_soundCheckBox->setChecked(true);

    m_animationCheckBox->setText(tr("Enable animations"));
    m_animationCheckBox->setChecked(true);

    m_languageComboBox->addItem(tr("English"));
    m_languageComboBox->addItem(tr("French"));
    m_languageComboBox->addItem(tr("Arabic"));

    generalLayout->addRow(m_soundCheckBox);
    generalLayout->addRow(m_animationCheckBox);
    generalLayout->addRow(tr("Language:"), m_languageComboBox);

    mainLayout->addWidget(generalGroup);

    // Player names
    auto* playersGroup = new QGroupBox(tr("Player Names"), this);
    auto* playersLayout = new QFormLayout(playersGroup);

    m_player1Name->setText(tr("Player 1"));
    m_player2Name->setText(tr("Player 2"));
    m_player3Name->setText(tr("Player 3"));
    m_player4Name->setText(tr("Player 4"));

    playersLayout->addRow(tr("Player 1:"), m_player1Name);
    playersLayout->addRow(tr("Player 2:"), m_player2Name);
    playersLayout->addRow(tr("Player 3:"), m_player3Name);
    playersLayout->addRow(tr("Player 4:"), m_player4Name);

    mainLayout->addWidget(playersGroup);

    // Buttons
    auto* buttonLayout = new QHBoxLayout();

    m_resetButton->setText(tr("Reset Defaults"));
    m_backButton->setText(tr("Back"));

    buttonLayout->addWidget(m_resetButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(m_backButton);

    mainLayout->addLayout(buttonLayout);

    mainLayout->addStretch();
}

void SettingsWidget::setupConnections()
{
    connect(
        m_resetButton,
        &QPushButton::clicked,
        this,
        &SettingsWidget::resetDefaults
        );

    connect(
        m_backButton,
        &QPushButton::clicked,
        this,
        &SettingsWidget::backRequested
        );
}

void SettingsWidget::resetDefaults()
{
    m_soundCheckBox->setChecked(true);
    m_animationCheckBox->setChecked(true);

    m_languageComboBox->setCurrentIndex(0);

    m_player1Name->setText(tr("Player 1"));
    m_player2Name->setText(tr("Player 2"));
    m_player3Name->setText(tr("Player 3"));
    m_player4Name->setText(tr("Player 4"));
}
