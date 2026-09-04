#include "Game.h"
#include "BeloteRules.h"

Game::Game()
    : m_team1(0, 2),
      m_team2(1, 3),
      m_trump(std::nullopt)
{
    m_players.emplace_back(0, "Player 1");
    m_players.emplace_back(1, "Player 2");
    m_players.emplace_back(2, "Player 3");
    m_players.emplace_back(3, "Player 4");
}

Game::Game(const Deck& deck)
    : m_deck(deck),
      m_team1(0, 2),
      m_team2(1, 3),
      m_trump(std::nullopt),
      m_customDeck(true)
{
    m_players.emplace_back(0, "Player 1");
    m_players.emplace_back(1, "Player 2");
    m_players.emplace_back(2, "Player 3");
    m_players.emplace_back(3, "Player 4");
}

void Game::startRound()
{
    if (isMatchOver()) {
        return;
    }

    if (!m_customDeck) {
        m_deck.reset();
        m_deck.shuffle();
    }

    m_completedTricksList.clear();
    m_trickWinners.clear();

    for (bool& announced : m_beloteAnnounced) {
        announced = false;
    }

    // Clear players' hands.
    for (Player& player : m_players) {
        while (!player.hand().empty()) {
            player.removeCard(
                static_cast<int>(player.hand().size()) - 1
            );
        }
    }

    // Reset round state.
    m_trump = std::nullopt;
    m_currentTrick = Trick();
    m_currentPlayer = 0;
    m_completedTricks = 0;

    m_roundScoreTeam1 = 0;
    m_roundScoreTeam2 = 0;

    m_roundStarted = true;
    m_roundOver = false;

    // Deal eight cards to each player.
    for (int i = 0; i < 8; ++i) {
        for (Player& player : m_players) {
            player.addCard(m_deck.draw());
        }
    }
}
Player& Game::player(int index)
{
    return m_players.at(index);
}

const Player& Game::player(int index) const
{
    return m_players.at(index);
}


bool Game::playCard(int playerId, int cardIndex)
{
    // A round must be active.
    if (!m_roundStarted || m_roundOver) {
        return false;
    }

    // Player ID must be valid.
    if (playerId < 0 ||
        playerId >= static_cast<int>(m_players.size())) {
        return false;
    }

    // It must be this player's turn.
    if (playerId != m_currentPlayer) {
        return false;
    }

    Player& player = m_players[playerId];

    // Card index must be valid.
    if (cardIndex < 0 ||
        cardIndex >= static_cast<int>(player.hand().size())) {
        return false;
    }

    // Trump must have been chosen.
    if (!m_trump.has_value()) {
        return false;
    }

    const Card card = player.hand()[cardIndex];

    // Check Belote rules.
    if (!BeloteRules::canPlayCard(
            player,
            card,
            m_currentTrick,
            *m_trump)) {
        return false;
    }

    // Play the card.
    m_currentTrick.addCard(playerId, card);
    player.removeCard(cardIndex);

    // Trick is not complete yet.
    if (!m_currentTrick.isComplete()) {
        m_currentPlayer =
            (m_currentPlayer + 1) %
            static_cast<int>(m_players.size());

        return true;
    }

    // Trick is complete.
    const Suit leadSuit =
        m_currentTrick.cards().front().second.suit();

    const int winner =
        m_currentTrick.winner(*m_trump, leadSuit);

    ++m_completedTricks;

    // Store completed trick and winner.
    m_completedTricksList.push_back(m_currentTrick);
    m_trickWinners.push_back(winner);

    // Winner starts the next trick.
    m_currentPlayer = winner;

    // Clear current trick.
    m_currentTrick = Trick();

    // Eight tricks complete the round.
    if (m_completedTricks == 8) {
        finishRound();
    }

    return true;
}

void Game::chooseTrump(Suit suit)
{
    if (!m_roundStarted) {
        return;
    }

    if (!m_currentTrick.cards().empty()) {
        return;
    }

    if (m_trump.has_value()) {
        return;
    }

    m_trump = suit;
}

bool Game::announceBelote(int playerId)
{
    if (!canAnnounceBelote(playerId)) {
        return false;
    }

    if (m_beloteAnnounced[playerId]) {
        return false;
    }

    m_beloteAnnounced[playerId] = true;

    return true;
}

bool Game::canAnnounceBelote(int playerId) const
{
    if (!m_roundStarted || !m_trump.has_value()) {
        return false;
    }

    if (playerId < 0 ||
        playerId >= static_cast<int>(m_players.size())) {
        return false;
    }

    bool hasKing = false;
    bool hasQueen = false;

    for (const Card& card : m_players[playerId].hand()) {
        if (card.suit() != *m_trump) {
            continue;
        }

        if (card.rank() == Rank::King) {
            hasKing = true;
        }

        if (card.rank() == Rank::Queen) {
            hasQueen = true;
        }
    }

    return hasKing && hasQueen;
}

void Game::finishRound()
{
    scoreRound();

    m_roundOver = true;
    m_roundStarted = false;
}

void Game::scoreRound()
{
    if (!m_trump.has_value()) {
        return;
    }

    int team1Tricks = 0;
    int team2Tricks = 0;

    int team1Points = 0;
    int team2Points = 0;

    for (size_t i = 0; i < m_completedTricksList.size(); ++i) {
        const Trick& trick = m_completedTricksList[i];
        const int winner = m_trickWinners[i];

        const bool team1Won =
            winner == m_team1.player1() ||
            winner == m_team1.player2();

        if (team1Won) {
            ++team1Tricks;
        }
        else {
            ++team2Tricks;
        }

        int points = trick.points(*m_trump);

        // Last trick bonus.
        if (i == 7) {
            points += 10;
        }

        if (team1Won) {
            team1Points += points;
        }
        else {
            team2Points += points;
        }
    }

    // Capot.
    if (team1Tricks == 8) {
        team1Points = 250;
        team2Points = 0;
    }
    else if (team2Tricks == 8) {
        team2Points = 250;
        team1Points = 0;
    }

    // Announced Belote / Rebelote.
    for (int player = 0; player < 4; ++player) {
        if (!m_beloteAnnounced[player]) {
            continue;
        }

        if (player == m_team1.player1() ||
            player == m_team1.player2()) {
            team1Points += 20;
        }
        else {
            team2Points += 20;
        }
    }

    // Store round scores.
    m_roundScoreTeam1 = team1Points;
    m_roundScoreTeam2 = team2Points;

    // Add to match scores.
    m_team1.addPoints(team1Points);
    m_team2.addPoints(team2Points);
}

bool Game::isGameOver() const
{
    return m_roundOver;
}

bool Game::isRoundOver() const
{
    return m_roundOver;
}

bool Game::isMatchOver() const
{
    return m_team1.score() >= WINNING_SCORE ||
           m_team2.score() >= WINNING_SCORE;
}

int Game::currentPlayer() const
{
    return m_currentPlayer;
}

const std::vector<Player>& Game::players() const
{
    return m_players;
}

const Team& Game::team1() const
{
    return m_team1;
}

const Team& Game::team2() const
{
    return m_team2;
}
/*
Suit Game::trump() const
{
    if (m_trump.has_value()) {
        return *m_trump;
    }

    return Suit::Hearts;
}*/
std::optional<Suit> Game::trump() const
{
    return m_trump;
}

int Game::roundScoreTeam1() const
{
    return m_roundScoreTeam1;
}

int Game::roundScoreTeam2() const
{
    return m_roundScoreTeam2;
}
