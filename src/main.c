#include "game.h"

int main(void)
{
    initGame(1280, 720, "Pong");
    runGame();
    cleanUp();
}