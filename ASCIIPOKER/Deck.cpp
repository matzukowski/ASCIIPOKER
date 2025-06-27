#include "Deck.h"
#include <random>

Deck::Deck() {}

void Deck::getNewDeck() {
    cards.clear();
    for (int s = 0; s < 4; ++s) {
        for (int r = 0; r < 13; ++r) {
            cards.emplace_back(static_cast<Suit>(s), static_cast<Rank>(r));
        }
    }
}

Card Deck::drawCard() {
    if (cards.empty()) {
        throw std::runtime_error("deck is empty");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, cards.size() - 1);

    int index = dist(gen);
    Card drawn = cards[index];
    cards.erase(cards.begin() + index);
    return drawn;
}

bool Deck::isEmpty() const {
    return cards.empty();
}

int Deck::size() const {
    return static_cast<int>(cards.size());
}