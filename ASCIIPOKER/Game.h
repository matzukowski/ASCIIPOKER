#pragma once
#include <vector>
#include "Player.h"
#include "Deck.h"

class Game {
private:
    Deck deck;
    std::vector<Player> players;
    std::vector<Card> communityCards;

    int pot;
    int smallBlind;
    int bigBlind;
    int currentBet;

public:
    Game();

    const std::vector<Player>& getPlayers() const;

    void setup();
    void dealHoleCards();
    void dealCommunityCards(int count);
    void bettingRound();
};