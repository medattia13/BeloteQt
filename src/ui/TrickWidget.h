#ifndef TRICKWIDGET_H
#define TRICKWIDGET_H

#include <QWidget>

class TrickWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TrickWidget(QWidget* parent = nullptr);

    void clear();
    void updateTrick();

private:
    void setupUi();
};

#endif
