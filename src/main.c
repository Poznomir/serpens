#include "raylib.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define RIGHT 3
#define DOWN 6
#define LEFT 9
#define UP 12

#define HEAD 2
#define BODY 1
#define APPLE -1
#define EMPTY 0

typedef struct Node {
  int x;
  int y;
  struct Node* next;
} Node;

typedef struct Snake {
  Node* head;
  Node* tail;
  int length;
  int direction;
} Snake;


void add_to_front(Snake* snake, int x, int y) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;
  
  if(snake->length == 0)
    snake->tail = newNode;
  else
    snake->head->next = newNode;
  
  snake->head = newNode;
    
}

void init_snake(Snake* snake, int board[10][10]) {
// here should be function choosing start
  board[5][4] = HEAD;
 // board[4][4] = BODY;
  snake->length = 1;
  snake->direction = 3;

 // add_to_front(snake, 4, 4);
  add_to_front(snake, 5, 4);
//  
}

void remove_back(Snake* snake) {
  Node* lastNode = snake->tail;
  lastNode = lastNode->next;
  free(lastNode);
}

int main(void)
{
    const int boardWidth = 10;
    const int boardHeight = 10;

    int board[boardWidth][boardHeight] = {};

    const int screenWidth = boardWidth*40;
    const int screenHeight = boardHeight*40;

    InitWindow(screenWidth, screenHeight, "Serpens");

    SetTargetFPS(120);
    
    Vector2 position = { 5 * 40.0f, 4 * 40.0f };
    
    Snake* snake;
    
    init_snake(snake, board);
    
    int iter = 0;
    while (!WindowShouldClose())
    {
        usleep(10000);
        iter++;
        
        if (IsKeyDown(KEY_RIGHT)) snake->direction = RIGHT;
        if (IsKeyDown(KEY_LEFT)) snake->direction = LEFT;
        if (IsKeyDown(KEY_UP)) snake->direction = UP;
        if (IsKeyDown(KEY_DOWN)) snake->direction = DOWN;
      
        if(iter == 100) {
          iter = 0;
          if(snake->direction == RIGHT)
            position.x += 40.0f;
          if(snake->direction == LEFT)
            position.x += -40.0f;
          if(snake->direction == UP)
            position.y += 40.0f;
          if(snake->direction == DOWN)
            position.y += -40.0f;
        }
      
        BeginDrawing();

          ClearBackground(RAYWHITE);

          DrawRectangle(position.x , position.y , 40, 40, BLACK);
        
        EndDrawing();
      }

    CloseWindow();
    
    return 0;
}
