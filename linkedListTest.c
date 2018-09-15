#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"


int main() {

	if(init() != 0) {
		printf("Error, init failed\n");
		return -1;
	} else {
		printf("Init success\n");
	}
	

	if(createNewNode(1,1) != NULL) {
		if(getLinkedListLength() > 0) {

			printf("Added 1 1 successfully\n");
		} else {

			printf("Error adding new node 1 1\n");
			goto clean;
		}

	} else {
		printf("Error adding new node 1 1\n");
		goto clean;
	}

	printLinkedList();



clean:
	if(cleanup() != 0) {
		printf("Error, cleanup failed\n");
		return -1;
	} else {
		printf("Cleanup success\n");
		return 0;
	}

}
