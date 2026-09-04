#ifndef GAME_H
#define GAME_H

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Team.h"
#include "Trick.h"

#include <optional>
#include <vector>

class Game
{
public:
    Game();
    explicit Game(const Deck& deck);

    void startRound();

    bool playCard(int playerId, int cardIndex);

    void chooseTrump(Suit suit);

    bool announceBelote(int playerId);
    bool canAnnounceBelote(int playerId) const;

    bool isGameOver() const;
    bool isRoundOver() const;
    bool isMatchOver() const;

    int currentPlayer() const;

    const std::vector<Player>& players() const;
    const Team& team1() const;
    const Team& team2() const;

    //Suit trump() const;
std::optional<Suit> trump() const;
    int roundScoreTeam1() const;
    int roundScoreTeam2() const;
    Player& player(int index);
    const Player& player(int index) const;
private:
    void finishRound();
    void scoreRound();

    Deck m_deck;
    std::vector<Player> m_players;

    Team m_team1;
    Team m_team2;

    std::optional<Suit> m_trump;

    Trick m_currentTrick;

    std::vector<Trick> m_completedTricksList;
    std::vector<int> m_trickWinners;

    int m_currentPlayer = 0;
    int m_completedTricks = 0;

    bool m_roundStarted = false;
    bool m_roundOver = false;

    bool m_beloteAnnounced[4] = {
        false,
        false,
        false,
        false
    };

    bool m_customDeck = false;

    int m_roundScoreTeam1 = 0;
    int m_roundScoreTeam2 = 0;

    static constexpr int WINNING_SCORE = 2000;
};

#endif
