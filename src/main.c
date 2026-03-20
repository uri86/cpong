#include <raylib.h>
#include <paddle.h>
#include <stdlib.h>
#include <player.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "cpong");
    SetTargetFPS(60);

    Player *p1 = createPlayer(KEY_W, KEY_S, 60, 10, 20, 20);
    Player *p2 = createPlayer(KEY_UP, KEY_DOWN, 60, 10, screenWidth - 30, 20);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Hello world!", 190, 200, 20, WHITE);
        movePlayer(p1, 1);
        movePlayer(p2, 1);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}