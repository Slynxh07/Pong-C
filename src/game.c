#include "game.h"
#include "paddle.h"
#include "raylib.h"

Paddle *p1;
Paddle *p2;
void restartGame();
void update();
void draw();

void initGame(int windowWidth, int windowHeight, char *title)
{
    InitWindow(windowWidth, windowHeight, title);
    SetTargetFPS(60);
    p1 = createPaddle((Vector2){0, 0}, LEFT);
    p2 = createPaddle((Vector2){0, 0}, RIGHT);
    restartGame();
}

void restartGame()
{
    resetPaddle(p1);
    resetPaddle(p2);
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

    ClearBackground(BLACK);
    drawPaddle(p1);
    drawPaddle(p2);

    EndDrawing();
}

void cleanUp()
{
    destroyPaddle(p1);
    destroyPaddle(p2);
}