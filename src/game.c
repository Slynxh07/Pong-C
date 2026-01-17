#include "game.h"
#include "paddle.h"
#include "ball.h"
#include "raylib.h"

Paddle *p1;
Paddle *p2;
Ball *ball;
void restartGame();
void update();
void draw();

void initGame(int windowWidth, int windowHeight, char *title)
{
    InitWindow(windowWidth, windowHeight, title);
    SetTargetFPS(60);
    p1 = createPaddle((Vector2){0, 0}, LEFT);
    p2 = createPaddle((Vector2){0, 0}, RIGHT);
    ball = createBall((Vector2){GetScreenWidth() / 2, GetScreenHeight() / 2}, 10.0f);
    restartGame();
}

void restartGame()
{
    resetPaddle(p1);
    resetPaddle(p2);
    resetBall(ball);
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
    updatePaddle(p1);
    updatePaddle(p2);
    updateBall(ball);
    checkPaddleCollisions(ball, getRect(p1));
    checkPaddleCollisions(ball, getRect(p2));
}

void draw()
{
    BeginDrawing();

    ClearBackground(BLACK);
    drawPaddle(p1);
    drawPaddle(p2);
    drawBall(ball);

    EndDrawing();
}

void cleanUp()
{
    destroyPaddle(p1);
    destroyPaddle(p2);
    destroyBall(ball);
}