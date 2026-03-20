#include <raylib.h>
#include <paddle.h>
#include <stdlib.h>
#include <collision.h>

Paddle *createPaddle(int height, int width, Vector2 pos)
{
    Paddle *p = malloc(sizeof(Paddle));
    p->height = height;
    p->width = width;
    p->pos = pos;
    p->yVelocity = 0;
    return p;
}

void movePaddle(Paddle *p, int x, int y)
{
    WallCollision collision = hasBoarderCollision(p);
    int actualMoveY = 0;

    if (collision != RIGHT && x > 0)
        p->pos.x += x;
    if (collision != LEFT && x < 0)
        p->pos.x += x;
    if (collision != TOP && y < 0)
    {
        p->pos.y += y;
        actualMoveY = y;
    }
    if (collision != BOTTOM && y > 0)
    {
        p->pos.y += y;
        actualMoveY = y;
    }

    p->yVelocity = actualMoveY;
}

void drawPaddle(Paddle *p, Color c)
{
    DrawRectangle(p->pos.x, p->pos.y, p->width, p->height, c);
}

WallCollision hasBoarderCollision(Paddle *p)
{
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    if (p->pos.y <= 0)
        return TOP;
    if (p->pos.x <= 0)
        return LEFT;
    if (p->pos.y + p->height >= screenHeight)
        return BOTTOM;
    if (p->pos.x + p->width >= screenWidth)
        return RIGHT;

    return NONE;
}