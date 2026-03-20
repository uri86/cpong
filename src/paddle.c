#include <raylib.h>
#include <paddle.h>
#include <stdlib.h>

Paddle *createPaddle(int height, int width, Vector2 pos)
{
    Paddle *p = malloc(sizeof(Paddle));
    p->height = height;
    p->width = width;
    p->pos = pos;
    return p;
}

void movePaddle(Paddle *p, int x, int y)
{
    p->pos.x += x;
    p->pos.y += y;
}

void drawPaddle(Paddle *p, Color c)
{
    DrawRectangle(p->pos.x, p->pos.y, p->width, p->height, c);
}