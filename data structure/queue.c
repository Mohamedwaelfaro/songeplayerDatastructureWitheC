#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void init_queue(Queue *q)
{
  q->front = -1;
  q->rear = -1;
}

int is_empty(Queue *q)
{
  return (q->front == -1 && q->rear == -1);
}

int is_full(Queue *q)
{
  return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(Queue *q, Song song)
{
  if (is_full(q))
  {
    printf("Error: queue is full\n");
    return;
  }
  if (is_empty(q))
  {
    q->front = 0;
    q->rear = 0;
  }
  else
  {
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
  }
  q->songs[q->rear] = song;
}

Song dequeue(Queue *q)
{
  if (is_empty(q))
  {
    printf("Error: queue is empty\n");
    Song null_song = {0, "", "", 0};
    return null_song;
  }
  Song dequeued_song = q->songs[q->front];
  if (q->front == q->rear)
  {
    q->front = -1;
    q->rear = -1;
  }
  else
  {
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
  }
  return dequeued_song;
}

void display_queue(Queue *q)
{
  if (is_empty(q))
  {
    printf("Queue is empty\n");
    return;
  }
  printf("Song Queue:\n");
  int i = q->front;
  while (i != q->rear)
  {
    printf("%d. %s - %s (%d seconds)\n", q->songs[i].id, q->songs[i].artist,
           q->songs[i].title, q->songs[i].duration);
    i = (i + 1) % MAX_QUEUE_SIZE;
  }
  printf("%d. %s - %s (%d seconds)\n", q->songs[i].id, q->songs[i].artist,
         q->songs[i].title, q->songs[i].duration);
}
