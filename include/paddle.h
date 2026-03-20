#ifndef PADDLE_H
#define PADDLE_H

#include <raylib.h>
#include <collision.h>

typedef struct Paddle
{
    long height, width;
    Vector2 pos;
    int yVelocity;
} Paddle;

Paddle *createPaddle(int height, int width, Vector2 pos);
void movePaddle(Paddle *p, int x, int y);
void drawPaddle(Paddle *p, Color c);
WallCollision hasBoarderCollision(Paddle *p);

#endif /* PADDLE_H */