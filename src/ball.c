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

    if (ball->pos.y - ball->rad <= 0 || ball->pos.y + ball->rad >= GetScreenHeight())
    {
        ball->velocity.y *= -1;
    }
}

void checkPaddleCollisions(Ball *ball, const Rectangle *rect)
{
    Vector2 prevPos = { ball->pos.x - ball->velocity.x, ball->pos.y - ball->velocity.y };

    if (CheckCollisionCircleRec(ball->pos, ball->rad, *rect))
    {
        bool fromTop = prevPos.y + ball->rad <= rect->y;
        bool fromBottom = prevPos.y - ball->rad >= rect->y + rect->height;
        
        if (fromTop || fromBottom) 
        {
            return;
        }
        else
        {
            float hitPos = (ball->pos.y - rect->y) / rect->height;

            ball->velocity.y = (hitPos - 0.5f) * 10.0f;
            ball->velocity.x *= -1;
        }
    }
}

void resetBall(Ball *ball)
{
    ball->velocity = (Vector2){10, 10};
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

int checkGoal(Ball *ball)
{
    if (ball->pos.x >= GetScreenWidth() - ball->rad) return 1;
    else if (ball->pos.x <= ball->rad) return 2;
    return 0;
}