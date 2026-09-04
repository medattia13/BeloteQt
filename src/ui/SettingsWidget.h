#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>

class QCheckBox;
class QComboBox;
class QLineEdit;
class QPushButton;

class SettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWidget(QWidget* parent = nullptr);

signals:
    void backRequested();

private slots:
    void resetDefaults();

private:
    void setupUi();
    void setupConnections();

    QCheckBox* m_soundCheckBox;
    QCheckBox* m_animationCheckBox;
    QComboBox* m_languageComboBox;

    QLineEdit* m_player1Name;
    QLineEdit* m_player2Name;
    QLineEdit* m_player3Name;
    QLineEdit* m_player4Name;

    QPushButton* m_resetButton;
    QPushButton* m_backButton;
};

#endif // SETTINGSWIDGET_H
