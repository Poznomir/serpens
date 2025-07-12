#include <stdio.h>

struct Pair{
  int x;
  int y;
};

typedef struct Node {
  Pair position;
  struct Node* next;
} Node;

struct Snake{
  Node* head;
  Node* tail;
  int lenght = 2;
  int direction = 3;
};

void init_snake(Snake* snake) {
  snake -> head = NULL;
  snake -> tail = NULL;
  snake -> lenght = 0;
}

void add_to_front(Snake* snake, Pair position) {

}

void remove_back() {

}

free_snake() {

}
