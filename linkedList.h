#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct node;

int init();

int cleanup();

int addToLinkedList(struct node* new);

struct node* createNewNode(int name, int value);

int getLinkedListLenght();

#endif
