#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

struct Node;

typedef struct Queue {
  struct Node *front;
  struct Node *back;
} Queue;

void initialize(Queue *qptr);

void enqueue(Queue *sor, int num);

void dequeue(Queue *sor);

void empty(Queue *ptr);

bool isEmpty(Queue *ptr);

int front(Queue *ptr);

int back(Queue *ptr);

int length(Queue *ptr);

void display(Queue *ptr);

#endif