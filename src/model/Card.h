#ifndef CARD_H
#define CARD_H
enum class Suit
{
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

enum class Rank
{
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

class Card
{
public:
    Card(Suit suit, Rank rank);

    Suit suit() const;
    Rank rank() const;

    int points(Suit trump) const;
    int strength(Suit trump) const;

private:
    Suit m_suit;
    Rank m_rank;
};
#endif // CARD_H
