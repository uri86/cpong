#include <raylib.h>
#include <paddle.h>
#include <player.h>
#include <stdlib.h>

Player *createPlayer(KeyboardKey up, KeyboardKey down, int height, int width, int x, int y)
{
    Player *p = malloc(sizeof(Player));
    Vector2 v = {x, y};
    p->paddle = createPaddle(height, width, v);
    p->up = up;
    p->down = down;
    return p;
}

void movePlayer(Player *p, int speed)
{
    if (IsKeyDown(p->up))
        movePaddle(p->paddle, 0, -speed);
    if (IsKeyDown(p->down))
        movePaddle(p->paddle, 0, speed);
    drawPaddle(p->paddle, WHITE);
}
