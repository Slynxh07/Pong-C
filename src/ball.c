#include "ball.h"
#include <stdlib.h>

typedef struct Ball {
    Vector2 pos;
    Vector2 velocity;
    float rad;
} Ball;

void updateBall(Ball *ball)
{
    ball->pos.x += ball->velocity.x;
    ball->pos.y += ball->velocity.y;
}

void checkCollision(Ball *ball, Rectangle *rect)
{
    if (CheckCollisionCircleRec(ball->pos, ball->rad, *rect))
    {
        
    }
}

void resetBall(Ball *ball)
{
    ball->velocity = (Vector2){0, 0};
    ball->pos = (Vector2){GetScreenWidth() / 2, GetScreenHeight() / 2};
}

void drawBall(const Ball *ball)
{
    DrawCircle(ball->pos.x, ball->pos.y, ball->rad, WHITE);
}

Ball *createBall(Vector2 pos, float rad)
{
    Ball *ball = malloc(sizeof(Ball));
    ball->pos = pos;
    ball->rad = rad;
    ball->velocity = (Vector2){0, 0};
    return ball;
}

void destroyBall(Ball *ball)
{
    free(ball);
}