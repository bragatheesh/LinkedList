#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

int addNodes(int numOfNodes) {
	int count = 1;
	while(count != numOfNodes + 1) {
	
		if(createNewNode(count,count) != NULL) {
			if(getLinkedListLength() > 0) {

				//printf("Added %d %d successfully\n", count, count);
			} else {

				printf("Error adding new node %d %d\n", count, count);
				return -1;
			}

		} else {
			printf("Error adding new node %d %d\n", count, count);
			return -1;
		}
	count++;
	}

	return count;
}

int main() {

	if(init() != 0) {
		printf("Error, init failed\n");
		return -1;
	} else {
		printf("Init success\n");
	}

	addNodes(10);

	printLinkedList();
	
	printf("Linked list length after all adds: %d\n", getLinkedListLength());

	if(!deleteNode(3,3)) {
		printLinkedList();
	
		printf("Linked list length after deleting node 3: %d\n", getLinkedListLength());
	}

	if(!deleteNode(10,10)) {
		printLinkedList();
	
		printf("Linked list length after deleting node 10: %d\n", getLinkedListLength());
	}

	if(!deleteNode(0,8)) {
		printLinkedList();
	
		printf("Linked list length after deleting node 0: %d\n", getLinkedListLength());
	}

	if(!deleteNode(1,1)) {
		printLinkedList();
	
		printf("Linked list length after deleting node 1: %d\n", getLinkedListLength());
	}



clean:
	if(cleanup() != 0) {
		printf("Error, cleanup failed\n");
		return -1;
	} else {
		printf("Cleanup success\n");
		return 0;
	}

}
