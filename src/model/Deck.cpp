#include "Deck.h"

#include <algorithm>
#include <random>
#include <stdexcept>

Deck::Deck()
{
    reset();
}

Deck::Deck(const std::vector<Card>& cards)
    : m_cards(cards)
{
}

void Deck::shuffle()
{
    static std::random_device rd;
    static std::mt19937 generator(rd());

    std::shuffle(m_cards.begin(), m_cards.end(), generator);
}

bool Deck::empty() const
{
    return m_cards.empty();
}

Card Deck::draw()
{
    if (m_cards.empty()) {
        throw std::out_of_range("Cannot draw from an empty deck");
    }

    Card card = m_cards.back();
    m_cards.pop_back();

    return card;
}

void Deck::reset()
{
    m_cards.clear();

    const Suit suits[] = {
        Suit::Hearts,
        Suit::Diamonds,
        Suit::Clubs,
        Suit::Spades
    };

    const Rank ranks[] = {
        Rank::Seven,
        Rank::Eight,
        Rank::Nine,
        Rank::Ten,
        Rank::Jack,
        Rank::Queen,
        Rank::King,
        Rank::Ace
    };

    for (Suit suit : suits) {
        for (Rank rank : ranks) {
            m_cards.emplace_back(suit, rank);
        }
    }
}

const std::vector<Card>& Deck::cards() const
{
    return m_cards;
}

