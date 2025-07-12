#include "raylib.h"

#define RIGHT 3
#define DOWN 6
#define LEFT 9
#define UP 12

#define HEAD 2
#define BODY 1
#define APPLE -1


int main(void)
{
    const int boardWidth = 10
    const int boardHeight = 10 

    int board[boardWidth][boardHeight] = {};

    const short screenWidth = boardWidth*40;
    const short screenHeight = boardHeight*40;

    InitWindow(screenWidth, screenHeight, "Serpens");

    SetTargetFPS(120);
    
    while (!WindowShouldClose())
    {
      
        BeginDrawing();

          ClearBackground(RAYWHITE);

          DrawRectangle(headPosition.x , headPosition.y , 40, 40, BLACK);
        
        EndDrawing();
      }

    CloseWindow();
    
    return 0;
}
