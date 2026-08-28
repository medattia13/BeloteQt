#include "BeloteRules.h"
#include <algorithm>

bool BeloteRules::ownsCard(
    const Player& player,
    const Card& card)
{
    for (const Card& handCard : player.hand()) {
        if (handCard.suit() == card.suit() &&
            handCard.rank() == card.rank()) {
            return true;
        }
    }

    return false;
}

bool BeloteRules::hasSuit(
    const Player& player,
    Suit suit)
{
    for (const Card& card : player.hand()) {
        if (card.suit() == suit) {
            return true;
        }
    }

    return false;
}

bool BeloteRules::hasTrump(
    const Player& player,
    Suit trump)
{
    return hasSuit(player, trump);
}

bool BeloteRules::followsSuit(
    const Card& card,
    const Trick& trick)
{
    if (trick.cards().empty()) {
        return true;
    }

    return card.suit() == trick.cards().front().second.suit();
}

bool BeloteRules::mustOvertrump(
    const Player& player,
    const Trick& trick,
    const Card& card,
    Suit trump)
{
    if (card.suit() != trump || trick.cards().empty()) {
        return false;
    }

    int strongestTrump = -1;

    for (const auto& played : trick.cards()) {
        const Card& playedCard = played.second;

        if (playedCard.suit() == trump) {
            strongestTrump = std::max(
                strongestTrump,
                playedCard.strength(trump)
                );
        }
    }

    // No trump has been played yet.
    if (strongestTrump == -1) {
        return false;
    }

    // Does the player have a trump stronger than the
    // strongest trump currently on the table?
    for (const Card& handCard : player.hand()) {
        if (handCard.suit() == trump &&
            handCard.strength(trump) > strongestTrump) {

            // They have a stronger trump, so they must
            // play one stronger than the current winner.
            return card.strength(trump) <= strongestTrump;
        }
    }

    // They cannot overtrump, so their trump is legal.
    return false;
}


bool BeloteRules::canPlayCard(
    const Player& player,
    const Card& card,
    const Trick& trick,
    Suit trump)
{
    // Card must belong to the player.
    if (!ownsCard(player, card)) {
        return false;
    }

    // First card of the trick: anything is allowed.
    if (trick.cards().empty()) {
        return true;
    }

    const Suit leadSuit =
        trick.cards().front().second.suit();

    // Player has the leading suit: must follow it.
    if (hasSuit(player, leadSuit)) {
        return card.suit() == leadSuit;
    }

    // Player cannot follow suit.
    // If they have trump, they must play trump.
    if (hasTrump(player, trump)) {
        if (card.suit() != trump) {
            return false;
        }

        // Must overtrump if possible.
        if (mustOvertrump(player, trick, card, trump)) {
            return false;
        }

        return true;
    }

    // Cannot follow and has no trump: anything is allowed.
    return true;
}
