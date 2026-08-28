class RandomAI : public PlayerAI
{
public:
    int chooseCard(const Game& game,
                   int playerId) override;
};
