#include <iostream>
#include "Deck.h"
#include <conio.h>
#include <windows.h>

int main() {
    Deck deck;
    deck.getNewDeck();

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int i = 1;

    while (true) {

        if (deck.isEmpty()) {
            std::cout << "\033[J";
            std::cout << "DECK EMPTY! STARTING NEW DECK!";

            i = 1;

            deck.getNewDeck();

            int ch = _getch();
            if (ch == 0 || ch == 224) _getch();

            std::cout << "\033[H";
            std::cout << "\033[J";


        }
        Card card = deck.drawCard();
        std::cout << card.getAsciiArt() << "\n\n" << i++;

        int ch = _getch();
        if (ch == 0 || ch == 224) _getch();

        std::cout << "\033[H";
    }

    return 0;
}