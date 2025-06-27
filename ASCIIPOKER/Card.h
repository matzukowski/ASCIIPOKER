#pragma once
#include <string>

enum class Suit {
    Spades = 0,
    Hearts,
    Diamonds,
    Clubs
};

enum class Rank {
    Two = 0,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

class Card {
private:
    Suit suit;
    Rank rank;

public:
    Card(Suit suit, Rank rank);

    Suit getSuit() const;
    Rank getRank() const;

    std::string getSuitSymbol() const;
    std::string getRankSymbol() const;
    std::string toString() const;
    std::string getAsciiArt() const;
};