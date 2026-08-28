#ifndef GAMESTATE_H
#define GAMESTATE_H

enum class GameState
{
    WaitingForPlayers,
    Dealing,
    ChoosingTrump,
    Playing,
    TrickFinished,
    RoundFinished,
    GameFinished
};

#endif
