class PlayerAI
{
public:
    virtual int chooseCard(const Game& game,
                           int playerId) = 0;
};
