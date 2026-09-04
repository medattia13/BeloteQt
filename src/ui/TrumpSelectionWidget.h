#ifndef TRUMPSELECTIONWIDGET_H
#define TRUMPSELECTIONWIDGET_H

#include <QDialog>

#include "model/Card.h"

class TrumpSelectionWidget : public QDialog
{
    Q_OBJECT

public:
    explicit TrumpSelectionWidget(QWidget* parent = nullptr);

signals:
    void suitSelected(Suit suit);

private:
    void setupUi();
};

#endif
