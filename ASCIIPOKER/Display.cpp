#include "Display.h"
#include "Game.h"
#include <iostream>
#include <map>

const std::vector<std::pair<int, int>> Display::playerCoordinates = {
    {0, 16},    // Bot 1 - L
    {22, 0},    // Bot 2 - TL
    {44, 0},    // Bot 3 - TR
    {69, 16},   // Bot 4 - R
    {30, 22}    // player
};

void Display::moveCursor(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}

void Display::moveCursorHome() {
    std::cout << "\033[H";
}

void Display::clearScreen() {
    moveCursorHome();
    std::cout << "\033[J";
}

void Display::clearHand(int playerNumber) {
    auto [x, y] = playerCoordinates[playerNumber];
    for (int i = 0; i < cardHeight; ++i) {
        moveCursor(x, y + 2 + i);
        std::cout << std::string(handWidth, ' ');
    }
    moveCursorHome();
}

void Display::clearCommunityCards() {
    auto [x, y] = communityBase;
    for (int i = 0; i < cardHeight; ++i) {
        moveCursor(x, y + i);
        std::cout << std::string(communityWidth, ' ');
    }
    moveCursorHome();
}

void Display::printCard(const Card& card, int x, int y) {
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

        initialized = true;
    }

    moveCursor(x, y);
        

    auto it = arts.find({ card.getRank(), card.getSuit()});
    if (it != arts.end()) {
        std::cout << it->second;
    }

    // default cart art
    std::cout <<
        u8"╔═════╗\x1b[1B\x1b[7D"
        u8"║" + card.getRankSymbol() + (card.getRank() == Rank::Ten ? "" : ".") + u8"...║\x1b[1B\x1b[7D"
        u8"║.....║\x1b[1B\x1b[7D"
        u8"║.." + card.getSuitSymbol() + u8"..║\x1b[1B\x1b[7D"
        u8"║.....║\x1b[1B\x1b[7D"
        u8"║..." + (card.getRank() == Rank::Ten ? "" : ".") + card.getRankSymbol() + u8"║\x1b[1B\x1b[7D"
        u8"╚═════╝";
}

void Display::printCardBackside(int x, int y) {
    moveCursor(x, y);

    std::cout <<
        u8"╔═════╗\x1b[1B\x1b[7D"
        u8"║/////║\x1b[1B\x1b[7D"
        u8"║/////║\x1b[1B\x1b[7D"
        u8"║/////║\x1b[1B\x1b[7D"
        u8"║/////║\x1b[1B\x1b[7D"
        u8"║/////║\x1b[1B\x1b[7D"
        u8"╚═════╝";

    moveCursorHome();
}

void Display::printPlayer(const Player& player, int playerNumber) {
    auto [x, y] = playerCoordinates[playerNumber];

    moveCursor(x, y);
    std::cout << player.getName();

    const auto& hand = player.getHand();
    for (int i = 0; i < hand.size() + 2; ++i) {
        printCardBackside(x + i * (cardWidth + cardSpacing), y + 2);
    }

    moveCursor(x, y + 10);
    std::cout << "$ " << player.getChips();
}

void Display::printCommunityCard(const Card& card, int place) {
    auto [x, y] = communityBase;
    x += place * (cardWidth + cardSpacing);
    printCard(card, x, y);
}