Each card could be represented by a custom Qt widget:
class CardWidget : public QGraphicsPixmapItem
{
public:
    CardWidget(const Card& card);

signals:
    void clicked();
};
Or if you prefer normal widgets: 

class CardWidget : public QPushButton
{
    Q_OBJECT

public:
    explicit CardWidget(const Card& card,
                        QWidget* parent = nullptr);

signals:
    void cardClicked();
};
