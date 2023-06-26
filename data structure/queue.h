#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 100

typedef struct Song
{
  int id;
  char title[50];
  char artist[50];
  int durati on;
} Song;

typedef struct Queue
{
  Song songs[MAX_QUEUE_SIZE];
  int front, rear;
} Queue;

void init_queue(Queue *q);
int is_empty(Queue *q);
int is_full(Queue *q);
void enqueue(Queue *q, Song song);
Song dequeue(Queue *q);
void display_queue(Queue *q);

#endif