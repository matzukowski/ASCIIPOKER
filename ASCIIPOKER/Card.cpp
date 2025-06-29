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