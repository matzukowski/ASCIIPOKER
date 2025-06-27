#pragma once
#include <vector>
#include <string>
#include "Card.h"

class Player {
private:
    std::string name;

    bool isBot;
    bool folded;
    int chips;

    std::vector<Card> hand;

public:
    Player(const std::string& name, bool isBot, int startingChips);

    void giveCard(const Card& card);
    void clearHand();

    const std::vector<Card>& getHand() const;
    std::string getName() const;
    bool isBotPlayer() const;
    int getChips() const;
    bool hasFolded() const;

    void fold();
    void deductChips(int amount);
    void addChips(int amount);
};