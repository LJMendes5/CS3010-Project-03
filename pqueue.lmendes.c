#include "pqueue.lmendes.h"
#include <stdlib.h>

void comparePriority(void *item1, void *item2, int *result) {
    PQueueEntry *entry1 = (PQueueEntry *) item1;
    PQueueEntry *entry2 = (PQueueEntry *) item2;

    if (entry1->priority < entry2->priority)
        *result = -1;
    else if (entry1->priority > entry2->priority)
        *result = 1;
    else
        *result = 0;
}

int enqueue(PQueueNode **pqueue, int priority, void *data) {
    PQueueEntry *entry = malloc(sizeof(PQueueEntry));

    if (entry == NULL)
        return 0;

    entry->priority = priority;
    entry->data = data;

    insertItem(pqueue, entry, comparePriority);

    return 0;
}

void *dequeue(PQueueNode **pqueue) {
    if (*pqueue == NULL)
        return NULL;

    PQueueEntry *entry = removeNthItem(pqueue, 0);

    if (entry == NULL)
        return NULL;

    void *data = entry->data;
    free(entry);

    return data;
}

void *peek(PQueueNode *pqueue) {
    if (pqueue == NULL)
        return NULL;

    PQueueEntry *entry = (PQueueEntry *) pqueue->data;

    return entry->data;
}

void printQueue(PQueueNode *pqueue, void (*printFunction)(void *)) {
    while (pqueue != NULL) {
        printFunction(((PQueueEntry*) pqueue->data)->data);
        pqueue = pqueue->next;
    }
}