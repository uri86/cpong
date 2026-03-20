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
    int dy = 0;
    if (IsKeyDown(p->up))
        dy = -speed;
    else if (IsKeyDown(p->down))
        dy = speed;

    movePaddle(p->paddle, 0, dy);
    drawPaddle(p->paddle, WHITE);
}
