#include <raylib.h>
#include <paddle.h>
#include <ball.h>
#include <stdlib.h>
#include <player.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int targetFPS = 60;

    InitWindow(screenWidth, screenHeight, "cpong");
    SetTargetFPS(targetFPS);

    Player *p1 = createPlayer(KEY_W, KEY_S, 60, 10, 20, screenHeight / 2 - 30);
    Player *p2 = createPlayer(KEY_UP, KEY_DOWN, 60, 10, screenWidth - 30, screenHeight / 2 - 30);
    Ball *ball = createBall();

    int score1 = 0;
    int score2 = 0;
    const int paddleSpeed = 5;

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_R))
        {
            score1 = 0;
            score2 = 0;
            resetBall(ball);
        }

        movePlayer(p1, paddleSpeed);
        movePlayer(p2, paddleSpeed);

        ball->pos.x += ball->xSpeed;
        ball->pos.y += ball->ySpeed;

        handleCollision(ball, p1->paddle, p2->paddle, &score1, &score2);

        BeginDrawing();
        ClearBackground(BLACK);

        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, GRAY);
        DrawText(TextFormat("%02i", score1), screenWidth / 2 - 60, 20, 40, WHITE);
        DrawText(TextFormat("%02i", score2), screenWidth / 2 + 30, 20, 40, WHITE);
        DrawText("Press R to reset", 10, screenHeight - 30, 16, LIGHTGRAY);

        drawBall(ball);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}