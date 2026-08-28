#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <vector>

#include "Card.h"

class Player
{
public:
    Player(int id, const QString& name);

    int id() const;
    QString name() const;

    const std::vector<Card>& hand() const;

    void addCard(const Card& card);
    void removeCard(int index);

private:
    int m_id;
    QString m_name;
    std::vector<Card> m_hand;
};

#endif // PLAYER_H
