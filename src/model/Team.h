class Team
{
public:
    Team(int player1, int player2);

    int score() const;

    void addPoints(int points);

    int player1() const;
    int player2() const;

private:
    int m_player1;
    int m_player2;
    int m_score = 0;
};
