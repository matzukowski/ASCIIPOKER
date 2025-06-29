#pragma once

#include <vector>
#include "Card.h"
#include "Player.h"

class Display {
public:
    static void moveCursor(int x, int y);
    static void moveCursorHome();

    static void clearScreen();
    static void clearHand(int playerNumber);
    static void clearCommunityCards();

    static void printCard(const Card& card, int x, int y) ;
    static void printCardBackside(int x, int y);
    static void printPlayer(const Player& player, int playerNumber);
    static void printCommunityCard(const Card& card, int place);

private:
    static constexpr int cardWidth = 7;
    static constexpr int cardHeight = 7;
    static constexpr int cardSpacing = 2;

    static constexpr int handWidth = cardWidth * 2 + cardSpacing;

    static constexpr int communityWidth = cardWidth * 5 + cardSpacing * 4;

    static constexpr std::pair<int, int> communityBase = { 20, 16 };

    static const std::vector<std::pair<int, int>> playerCoordinates;
};