#include "Team.h"

Team::Team(int player1, int player2)
    : m_player1(player1),
      m_player2(player2)
{
}

int Team::score() const
{
    return m_score;
}

void Team::addPoints(int points)
{
    m_score += points;
}

int Team::player1() const
{
    return m_player1;
}

int Team::player2() const
{
    return m_player2;
}
