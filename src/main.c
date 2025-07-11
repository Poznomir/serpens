#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Moving ball");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 4.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 4.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 4.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 4.0f;

        
        BeginDrawing();

          ClearBackground(RAYWHITE);

          DrawCircleV(ballPosition, 75, RED);
        
        EndDrawing();
      }

    CloseWindow();
    
    return 0;
}
