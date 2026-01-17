#ifndef PADDLE_H
#define PADDLE_H

#include "raylib.h"

typedef struct Paddle Paddle;

typedef enum Team {
    LEFT,
    RIGHT
} Team;

Paddle *createPaddle(Vector2 pos, Team side);
void updatePaddle(Paddle *p);
void drawPaddle(const Paddle *p);
void destroyPaddle(Paddle* p);
void resetPaddle(Paddle *p);
Rectangle *getRect(Paddle *p);

#endif