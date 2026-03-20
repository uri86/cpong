#ifndef BALL_H
#define BALL_H

#include <raylib.h>
#include <paddle.h>

typedef struct Ball
{
    int radius;
    int xSpeed;
    int ySpeed;
    Vector2 pos;
} Ball;

Ball *createBall();
void resetBall(Ball *b);
void handleCollision(Ball *b, Paddle *p1, Paddle *p2, int *score1, int *score2);
void drawBall(Ball *b);

#endif /* BALL_H */