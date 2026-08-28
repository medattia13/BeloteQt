#include "Player.h"

Player::Player(int id, const QString& name)
    : m_id(id),
      m_name(name)
{
}

int Player::id() const
{
    return m_id;
}

QString Player::name() const
{
    return m_name;
}

const std::vector<Card>& Player::hand() const
{
    return m_hand;
}

void Player::addCard(const Card& card)
{
    m_hand.push_back(card);
}

void Player::removeCard(int index)
{
    if (index < 0 || index >= static_cast<int>(m_hand.size())) {
        throw std::out_of_range("Invalid card index");
    }

    m_hand.erase(m_hand.begin() + index);
}
