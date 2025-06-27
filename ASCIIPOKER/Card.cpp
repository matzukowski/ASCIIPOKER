#include "Card.h"
#include <map>

Card::Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}

Suit Card::getSuit() const {
    return suit;
}

Rank Card::getRank() const {
    return rank;
}

std::string Card::getSuitSymbol() const {
    switch (suit) {
    case Suit::Spades:   return u8"♠";
    case Suit::Hearts:   return u8"♥";
    case Suit::Diamonds: return u8"♦";
    case Suit::Clubs:    return u8"♣";
    }
    return "?";
}

std::string Card::getRankSymbol() const {
    switch (rank) {
    case Rank::Two:   return "2";
    case Rank::Three: return "3";
    case Rank::Four:  return "4";
    case Rank::Five:  return "5";
    case Rank::Six:   return "6";
    case Rank::Seven: return "7";
    case Rank::Eight: return "8";
    case Rank::Nine:  return "9";
    case Rank::Ten:   return "10";
    case Rank::Jack:  return "J";
    case Rank::Queen: return "Q";
    case Rank::King:  return "K";
    case Rank::Ace:   return "A";
    }
    return "?";
}

std::string Card::toString() const {
    return getRankSymbol() + getSuitSymbol() + ' ';
}

std::string Card::getAsciiArt() const {
    static std::map<std::pair<Rank, Suit>, std::string> arts;
    static bool initialized = false;

    // custom card arts
    if (!initialized) {

        arts[{Rank::Ace, Suit::Spades}] =
            u8"╔═════╗\x1b[1B\x1b[7D"
            u8"║A....║\x1b[1B\x1b[7D"
            u8"║.....║\x1b[1B\x1b[7D"
            u8"║..♠..║\x1b[1B\x1b[7D"
            u8"║.....║\x1b[1B\x1b[7D"
            u8"║....A║\x1b[1B\x1b[7D"
            u8"╚═════╝";

        arts[{Rank::Ace, Suit::Diamonds}] =
            u8"╔═════╗\x1b[1B\x1b[7D"
            u8"║/////║\x1b[1B\x1b[7D"
            u8"║/////║\x1b[1B\x1b[7D"
            u8"║/////║\x1b[1B\x1b[7D"
            u8"║/////║\x1b[1B\x1b[7D"
            u8"║/////║\x1b[1B\x1b[7D"
            u8"╚═════╝";

        initialized = true;
    }

    auto it = arts.find({ rank, suit });
    if (it != arts.end()) {
        return it->second;
    }

    // default cart art
    if (rank == Rank::Ten) {
        return
            u8"╔═════╗\x1b[1B\x1b[7D"
            u8"║" + getRankSymbol() + u8"...║\x1b[1B\x1b[7D"
            u8"║.....║\x1b[1B\x1b[7D"
            u8"║.." + getSuitSymbol() + u8"..║\x1b[1B\x1b[7D"
            u8"║.....║\x1b[1B\x1b[7D"
            u8"║..." + getRankSymbol() + u8"║\x1b[1B\x1b[7D"
            u8"╚═════╝";
    }

    return
        u8"╔═════╗\x1b[1B\x1b[7D"
        u8"║" + getRankSymbol() + u8"....║\x1b[1B\x1b[7D"
        u8"║.....║\x1b[1B\x1b[7D"
        u8"║.." + getSuitSymbol() + u8"..║\x1b[1B\x1b[7D"
        u8"║.....║\x1b[1B\x1b[7D"
        u8"║...." + getRankSymbol() + u8"║\x1b[1B\x1b[7D"
        u8"╚═════╝";
}