#include "game.h"
#include "paddle.h"
#include "ball.h"
#include "raylib.h"

Paddle *p1, *p2;
Ball *ball;
unsigned long long score1, score2;
void restartGame();
void resetKickOff();
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
    score1 = 0;
    score2 = 0;
    resetKickOff();
}

void resetKickOff()
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
    int goal = checkGoal(ball);
    switch (goal)
    {
        case 0:
            break;
        case LEFT:
            score1++;
            resetKickOff();
            break;
        case RIGHT:
            score2++;
            resetKickOff();
            break;
    }
}

void draw()
{
    BeginDrawing();

        ClearBackground(BLACK);
        drawPaddle(p1);
        drawPaddle(p2);
        drawBall(ball);
        DrawText(TextFormat("%d", score1), GetScreenWidth() / 4, GetScreenHeight() / 2, 30, WHITE);
        DrawText(TextFormat("%d", score2), (GetScreenWidth() / 4) * 3, GetScreenHeight() / 2, 30, WHITE);

    EndDrawing();
}

void cleanUp()
{
    destroyPaddle(p1);
    destroyPaddle(p2);
    destroyBall(ball);
}