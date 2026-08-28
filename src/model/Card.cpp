#include "Card.h"

Card::Card(Suit suit, Rank rank)
    : m_suit(suit),
      m_rank(rank)
{
}

Suit Card::suit() const
{
    return m_suit;
}

Rank Card::rank() const
{
    return m_rank;
}

int Card::points(Suit trump) const
{
    if (m_suit == trump) {
        switch (m_rank) {
        case Rank::Jack:
            return 20;

        case Rank::Nine:
            return 14;

        case Rank::Ace:
            return 11;

        case Rank::Ten:
            return 10;

        case Rank::King:
            return 4;

        case Rank::Queen:
            return 3;

        case Rank::Eight:
        case Rank::Seven:
            return 0;
        }
    }

    switch (m_rank) {
    case Rank::Ace:
        return 11;

    case Rank::Ten:
        return 10;

    case Rank::King:
        return 4;

    case Rank::Queen:
        return 3;

    case Rank::Jack:
        return 2;

    case Rank::Nine:
    case Rank::Eight:
    case Rank::Seven:
        return 0;
    }

    return 0;
}

int Card::strength(Suit trump) const
{
    // Higher value = stronger card.
    // Trump order:
    // Jack > Nine > Ace > Ten > King > Queen > Eight > Seven
    if (m_suit == trump) {
        switch (m_rank) {
        case Rank::Jack:
            return 8;

        case Rank::Nine:
            return 7;

        case Rank::Ace:
            return 6;

        case Rank::Ten:
            return 5;

        case Rank::King:
            return 4;

        case Rank::Queen:
            return 3;

        case Rank::Eight:
            return 2;

        case Rank::Seven:
            return 1;
        }
    }

    // Non-trump order:
    // Ace > Ten > King > Queen > Jack > Nine > Eight > Seven
    switch (m_rank) {
    case Rank::Ace:
        return 8;

    case Rank::Ten:
        return 7;

    case Rank::King:
        return 6;

    case Rank::Queen:
        return 5;

    case Rank::Jack:
        return 4;

    case Rank::Nine:
        return 3;

    case Rank::Eight:
        return 2;

    case Rank::Seven:
        return 1;
    }

    return 0;
}
