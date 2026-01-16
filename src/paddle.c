#include "paddle.h"
#include <stdlib.h>

typedef struct Paddle
{
    Vector2 pos;
    Rectangle rect;
    Team side;
} Paddle;

void updatePaddle(Paddle *p)
{
    
}

void drawPaddle(const Paddle *p)
{
    DrawRectangleRec(p->rect, WHITE);
}

Paddle *createPaddle(Vector2 pos, Team side)
{
    Paddle *p = malloc(sizeof(Paddle));
    p->pos = pos;
    p->rect = (Rectangle){pos.x, pos.y, 20, 100};
    p->side = side;
    return p;
}

void resetPaddle(Paddle *p)
{
    p->pos.y = (GetScreenHeight() - p->rect.height) / 2;
    switch (p->side)
    {
        case LEFT:
            p->pos.x = 20;
            break;
        case RIGHT:
            p->pos.x = GetScreenWidth() - 40;
            break;
    }
    p->rect.x = p->pos.x;
    p->rect.y = p->pos.y;
}

void destroyPaddle(Paddle *p)
{
    free(p);
}