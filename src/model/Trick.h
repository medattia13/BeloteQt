#ifndef TRICK_H
#define TRICK_H

#include "Card.h"

#include <vector>
#include <utility>

class Trick
{
public:
    void addCard(int playerId, const Card& card);

    bool isComplete() const;

    const std::vector<std::pair<int, Card>>& cards() const;

    int winner(Suit trump, Suit leadSuit) const;

    int points(Suit trump) const;

private:
    std::vector<std::pair<int, Card>> m_cards;
};

#endif // TRICK_H

