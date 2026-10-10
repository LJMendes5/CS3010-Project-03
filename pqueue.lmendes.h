#ifndef PQUEUE_H
#define PQUEUE_H

#include "list.lmendes.h"

typedef ListNode PQueueNode;

typedef struct {
    int priority;
    void *data;
} PQueueEntry;

void comparePriority(void *item1, void *item2, int *result);
int enqueue(PQueueNode **pqueue, int priority, void *data);
void *dequeue(PQueueNode **pqueue);
void *peek(PQueueNode *pqueue);
void printQueue(PQueueNode *pqueue, void (*printFunction)(void *));
int getMinPriority(PQueueNode *pqueue);
int queueLength(PQueueNode *pqueue);

#endif