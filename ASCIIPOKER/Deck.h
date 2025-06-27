#pragma once
#include <vector>
#include "Card.h"

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck();

    void getNewDeck();
    Card drawCard();
    bool isEmpty() const;
    int size() const;
};
