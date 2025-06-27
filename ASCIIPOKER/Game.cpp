#include "Game.h"
#include <iostream>

Game::Game() : pot(0), smallBlind(10), bigBlind(20), currentBet(0) {}

void Game::setup() {
    players.emplace_back("You", false, 1000);
    for (int i = 1; i < 5; ++i) {
        players.emplace_back("Bot" + std::to_string(i), true, 1000);
    }
}

void Game::dealHoleCards() {
    deck.getNewDeck();
    for (Player& player : players) {
        player.clearHand();
        player.giveCard(deck.drawCard());
    }
    for (Player& player : players) {
        player.giveCard(deck.drawCard());
    }
}

void Game::dealCommunityCards(int count) {
    for (int i = 0; i < count; ++i) {
        communityCards.push_back(deck.drawCard());
    }
}

void Game::bettingRound() {

    throw std::runtime_error("not implemented");
}

void Game::play() {
    setup();
    dealHoleCards();
    bettingRound();
    dealCommunityCards(3);
    bettingRound();
    dealCommunityCards(1);
    bettingRound();
    dealCommunityCards(1);
    bettingRound();
}