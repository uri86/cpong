#include <ball.h>
#include <raylib.h>
#include <collision.h>
#include <paddle.h>
#include <stdlib.h>

Ball *createBall()
{
    Ball *b = malloc(sizeof(Ball));
    b->radius = 8;
    resetBall(b);
    return b;
}

void resetBall(Ball *b)
{
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    b->pos.x = screenWidth / 2;
    b->pos.y = screenHeight / 2;
    b->xSpeed = GetRandomValue(0, 1) == 0 ? 3 : -3;
    b->ySpeed = GetRandomValue(-2, 2);
    if (b->ySpeed == 0)
        b->ySpeed = 1;
}

static int clampInt(int value, int min, int max)
{
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}

static void applyPaddleCollision(Ball *b, Paddle *p)
{
    b->xSpeed = -b->xSpeed;

    if (p->yVelocity == 0)
    {
        b->xSpeed = clampInt(b->xSpeed, -10, 10);
        return;
    }

    float contact = (b->pos.y - p->pos.y) / (float)p->height;
    float offset = (contact - 0.5f) * 2.0f;
    int yDelta = (int)(offset * 3.0f);
    b->ySpeed += yDelta;

    if ((p->yVelocity < 0 && b->ySpeed < 0) || (p->yVelocity > 0 && b->ySpeed > 0))
    {
        if (contact < 0.33f && p->yVelocity < 0)
            b->ySpeed -= 2;
        else if (contact > 0.66f && p->yVelocity > 0)
            b->ySpeed += 2;
        else
            b->ySpeed += (p->yVelocity < 0 ? -1 : 1);
    }
    else
    {
        if (b->ySpeed > 0)
            b->ySpeed = clampInt(b->ySpeed - 1, 1, 10);
        else
            b->ySpeed = clampInt(b->ySpeed + 1, -10, -1);
    }
    b->xSpeed += (p->yVelocity < 0 ? -1 : 1);
    b->xSpeed = clampInt(b->xSpeed, -12, 12);
    b->ySpeed = clampInt(b->ySpeed, -10, 10);
}

void handleCollision(Ball *b, Paddle *p1, Paddle *p2, int *score1, int *score2)
{
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    if (b->pos.y - b->radius <= 0)
    {
        b->pos.y = b->radius;
        b->ySpeed *= -1;
    }
    else if (b->pos.y + b->radius >= screenHeight)
    {
        b->pos.y = screenHeight - b->radius;
        b->ySpeed *= -1;
    }

    Rectangle r1 = {p1->pos.x, p1->pos.y, (float)p1->width, (float)p1->height};
    Rectangle r2 = {p2->pos.x, p2->pos.y, (float)p2->width, (float)p2->height};

    if (CheckCollisionCircleRec(b->pos, b->radius, r1) && b->xSpeed < 0)
        applyPaddleCollision(b, p1);

    if (CheckCollisionCircleRec(b->pos, b->radius, r2) && b->xSpeed > 0)
        applyPaddleCollision(b, p2);

    if (b->pos.x - b->radius <= 0)
    {
        (*score2)++;
        resetBall(b);
    }

    if (b->pos.x + b->radius >= screenWidth)
    {
        (*score1)++;
        resetBall(b);
    }
}

void drawBall(Ball *b)
{
    DrawCircleV(b->pos, b->radius, WHITE);
}