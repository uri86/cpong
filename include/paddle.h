#ifndef PADDLE_H
#define PADDLE_H

#include <raylib.h>

typedef struct Paddle
{
    long height, width;
    Vector2 pos;
} Paddle;

Paddle *createPaddle(int height, int width, Vector2 pos);
void movePaddle(Paddle *p, int x, int y);
void drawPaddle(Paddle *p, Color c);

#endif /* PADDLE_H */