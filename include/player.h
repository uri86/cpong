#ifndef PLAYER_H
#define PLAYER_H

#include <paddle.h>

typedef struct Player
{
    Paddle *paddle;
    KeyboardKey up;
    KeyboardKey down;
} Player;

Player *createPlayer(KeyboardKey up, KeyboardKey down, int width, int height, int x, int y);
void movePlayer(Player *p, int speed);

#endif /* PLAYER_H */