#include "Player.h"

Player::Player(const std::string& name, bool isBot, int startingChips)
    : name(name), isBot(isBot), chips(startingChips), folded(false) {}

void Player::giveCard(const Card& card) {
    hand.push_back(card);
}

void Player::clearHand() {
    hand.clear();
    folded = false;
}

const std::vector<Card>& Player::getHand() const {
    return hand;
}

std::string Player::getName() const {
    return name;
}

bool Player::isBotPlayer() const {
    return isBot;
}

int Player::getChips() const {
    return chips;
}

bool Player::hasFolded() const {
    return folded;
}

void Player::fold() {
    folded = true;
}

void Player::deductChips(int amount) {
    chips -= amount;
    if (chips < 0) chips = 0;
}

void Player::addChips(int amount) {
    chips += amount;
}