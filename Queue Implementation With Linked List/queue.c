#include "queue.h"

typedef struct Node {
  unsigned int value;
  struct Node *next;
} Node;

void initialize(Queue *ptr) {

  ptr = (Queue*)malloc(sizeof(Node));
  ptr->front = NULL;
  ptr->back = NULL;
}

void enqueue(Queue *sor, int num) {

  Node *tmp;
  tmp = malloc(sizeof(Node));
  tmp->value = num;
  tmp->next = NULL;

  if (!isEmpty(sor)) {
    sor->back->next = tmp;
    sor->back = tmp;
  }
  else {
    sor->front = sor->back = tmp;
  }
}

void dequeue(Queue *sor) {

  if (sor->front == NULL) {
    return;
  }

  Node *tmp;
  tmp = sor->front;
  sor->front = sor->front->next;
  free(tmp);

  if (sor->front == NULL) {
    sor->back = NULL;
  }
}

void empty(Queue *ptr) {

  Node *current = ptr->front;
  Node *upcoming;
  while (current != NULL) {
    upcoming = current->next;
    free(current);
    current = upcoming;
  }
  ptr->front = NULL;
  ptr->back = NULL;
}

bool isEmpty(Queue *ptr) {
  return (ptr->front == NULL) ? true : false;
}

int front(Queue *ptr) {
  return (isEmpty(ptr)) ? -1 : ptr->front->value;
}

int back(Queue *ptr) {
  return (isEmpty(ptr)) ? -1 : ptr->back->value;
}

int length(Queue *ptr) {

  int length = 0;
  Node *current_elem;
  current_elem = ptr->front;
  while (current_elem != NULL) {
    current_elem = current_elem->next;
    length++;
  }
  return length;
}

void display(Queue *ptr) {

  Node *current_element;
  current_element = ptr->front;

  if(current_element == NULL) {
    printf("A sor üres\n");
    return;
  }
  while (current_element != NULL) {
    printf("%d -> ",current_element->value); 
    current_element = current_element->next;
  }
  printf("nil\n");
}