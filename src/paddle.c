#include "paddle.h"
#include <stdlib.h>

float speed = 15.0f;

typedef struct Paddle
{
    Vector2 pos;
    Rectangle rect;
    Team side;
} Paddle;

void updatePaddle(Paddle *p)
{
    float dir = 0;

    switch (p->side)
    {
        case LEFT:
            dir = (IsKeyDown(KEY_S) ? 1.0f : 0.0f) - (IsKeyDown(KEY_W) ? 1.0f : 0.0f);
            break;
        case RIGHT:
            dir = (IsKeyDown(KEY_DOWN) ? 1.0f : 0.0f) - (IsKeyDown(KEY_UP) ? 1.0f : 0.0f);
            break;
    }

    p->pos.y += speed * dir;

    p->rect.x = p->pos.x;
    p->rect.y = p->pos.y;
}

void drawPaddle(const Paddle *p)
{
    DrawRectangleRec(p->rect, WHITE);
}

Paddle *createPaddle(Vector2 pos, Team side)
{
    Paddle *p = malloc(sizeof(Paddle));
    p->pos = pos;
    p->rect = (Rectangle){pos.x, pos.y, 20, 120};
    p->side = side;
    return p;
}

void resetPaddle(Paddle *p)
{
    p->pos.y = (GetScreenHeight() - p->rect.height) / 2;
    switch (p->side)
    {
        case LEFT:
            p->pos.x = 40;
            break;
        case RIGHT:
            p->pos.x = GetScreenWidth() - 60;
            break;
    }
    p->rect.x = p->pos.x;
    p->rect.y = p->pos.y;
}

void destroyPaddle(Paddle *p)
{
    free(p);
}