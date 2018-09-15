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

	addNodes(10240);

	//printLinkedList();
	
	printf("Linked list lenght after all adds: %d\n", getLinkedListLength());
	
clean:
	if(cleanup() != 0) {
		printf("Error, cleanup failed\n");
		return -1;
	} else {
		printf("Cleanup success\n");
		return 0;
	}

}
