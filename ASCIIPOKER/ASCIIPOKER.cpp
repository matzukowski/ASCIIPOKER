#include <iostream>
#include "Deck.h"
#include "Game.h"
#include "Display.h"
#include <conio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    while (true) {
        Game game = Game();

        game.setup();

        Display::printPlayer(game.getPlayers()[0], 0);
        Display::printPlayer(game.getPlayers()[1], 1);
        Display::printPlayer(game.getPlayers()[2], 2);
        Display::printPlayer(game.getPlayers()[3], 3);
        Display::printPlayer(game.getPlayers()[4], 4);

        // TODO: move display calls to game
        
        //game.dealCommunityCards(3);

        int ch = _getch();
        if (ch == 0 || ch == 224) ch = _getch();
    }

    return 0;
}