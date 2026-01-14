#include "game.h"
#include "raylib.h"

void initGame(int windowWidth, int windowHeight, char *title)
{
    InitWindow(windowWidth, windowHeight, title);
    SetTargetFP(60);
}

void runGame()
{
    while (!WindowShouldClose())
    {
        update();
        draw();
    }
}

void update()
{
    
}

void draw()
{
    BeginDrawing();

    ClearBackground(BLUE);

    EndDrawing();
}