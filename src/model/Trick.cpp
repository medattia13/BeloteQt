#include "Trick.h"

void Trick::addCard(int playerId, const Card& card)
{
    if (!isComplete()) {
        m_cards.emplace_back(playerId, card);
    }
}

bool Trick::isComplete() const
{
    return m_cards.size() == 4;
}

const std::vector<std::pair<int, Card>>& Trick::cards() const
{
    return m_cards;
}

int Trick::winner(Suit trump, Suit leadSuit) const
{
    if (m_cards.empty()) {
        return -1;
    }

    int winnerId = m_cards[0].first;
    const Card* winningCard = &m_cards[0].second;

    for (size_t i = 1; i < m_cards.size(); ++i) {
        const Card& currentCard = m_cards[i].second;

        bool currentIsTrump = currentCard.suit() == trump;
        bool winningIsTrump = winningCard->suit() == trump;

        // Trump beats non-trump.
        if (currentIsTrump && !winningIsTrump) {
            winnerId = m_cards[i].first;
            winningCard = &currentCard;
            continue;
        }

        // Non-trump cannot beat an existing trump.
        if (!currentIsTrump && winningIsTrump) {
            continue;
        }

        // Both are trump.
        if (currentIsTrump && winningIsTrump) {
            if (currentCard.strength(trump) >
                winningCard->strength(trump)) {

                winnerId = m_cards[i].first;
                winningCard = &currentCard;
            }

            continue;
        }

        // From here, neither card is trump.

        bool currentIsLead = currentCard.suit() == leadSuit;
        bool winningIsLead = winningCard->suit() == leadSuit;

        // Lead suit beats another non-trump suit.
        if (currentIsLead && !winningIsLead) {
            winnerId = m_cards[i].first;
            winningCard = &currentCard;
            continue;
        }

        // A non-lead suit cannot beat the lead suit.
        if (!currentIsLead && winningIsLead) {
            continue;
        }

        // Both are lead suit.
        if (currentIsLead && winningIsLead) {
            if (currentCard.strength(trump) >
                winningCard->strength(trump)) {

                winnerId = m_cards[i].first;
                winningCard = &currentCard;
            }
        }
    }

    return winnerId;
}


int Trick::points(Suit trump) const
{
    int total = 0;

    for (const auto& entry : m_cards) {
        total += entry.second.points(trump);
    }

    return total;
}
