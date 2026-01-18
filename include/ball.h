#ifndef BALL_H
#define BALL_H

#include "raylib.h"

typedef struct Ball Ball;

void updateBall(Ball *ball);
void drawBall(const Ball *ball);
void resetBall(Ball *ball);
Ball *createBall(Vector2 pos, float rad);
void checkPaddleCollisions(Ball *ball, const Rectangle *rect);
void destroyBall(Ball *ball);
int checkGoal(Ball *ball);

#endif