#pragma once

#include "Card.h"
#include "Player.h"
#include "Trick.h"

class BeloteRules
{
public:
    static bool canPlayCard(
        const Player& player,
        const Card& card,
        const Trick& trick,
        Suit trump
        );

    static int cardStrength(
        const Card& card,
        Suit trump
        );

    static int cardPoints(
        const Card& card,
        Suit trump
        );

    static int trickWinner(
        const Trick& trick,
        Suit trump
        );

    static int trickPoints(
        const Trick& trick,
        Suit trump
        );

private:
    static bool ownsCard(
        const Player& player,
        const Card& card
        );

    static bool hasSuit(
        const Player& player,
        Suit suit
        );

    static bool hasTrump(
        const Player& player,
        Suit trump
        );

    static bool followsSuit(
        const Card& card,
        const Trick& trick
        );

    static bool mustOvertrump(
        const Player& player,
        const Trick& trick,
        const Card& card,
        Suit trump
        );
};
