#ifndef DECK_H
#define DECK_H

#include "Card.h"

#include <vector>

class Deck
{
public:
    Deck();
    explicit Deck(const std::vector<Card>& cards);
    
    void shuffle();

    bool empty() const;

    Card draw();

    void reset();

    const std::vector<Card>& cards() const;

private:
    std::vector<Card> m_cards;
};

#endif // DECK_H
