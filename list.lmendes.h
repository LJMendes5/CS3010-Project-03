// jdh CS 3010 Fall 2026
#pragma once // I don't know what this does but the compiler got mad at me and told me to add it
// I think it makes it only included once in compilation

typedef struct ListNodeStruct {
  void *data;
  struct ListNodeStruct *next;
} ListNode;

typedef int (* ComparisonFunction)(void *, void *, void *);
typedef void (* PrintFunction)(void *);

int insertItem(ListNode **theList, void *item, ComparisonFunction compare);
void *findItem(ListNode *theList, void *item, ComparisonFunction compare);
void *removeItem(ListNode **theList, void *item, ComparisonFunction compare);
void *removeNthItem(ListNode **theList, int pos);
void *findNthItem(ListNode *theList, int pos);
int printList(ListNode *theList, PrintFunction print);
