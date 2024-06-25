#ifndef LINKED_CIRC_LIST_H
#define LINKED_CIRC_LIST_H
#include <stdbool.h>

typedef struct list TCircList;

TCircList *TCircList_create();

bool TCircList_insert(TCircList *, int);

void TCircList_print(TCircList *);
int findSafePosition(int N, int M);

#endif