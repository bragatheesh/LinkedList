#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct node;

int init();

int cleanup();

struct node* createNewNode(int name, int value);

int getLinkedListLength();

void printLinkedList();

#endif
