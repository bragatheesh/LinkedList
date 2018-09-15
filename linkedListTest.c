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

	
	
	
	
	
	
	
	
	
	
	
	if(cleanup() != 0) {
		printf("Error, cleanup failed\n");
		return -1;
	} else {
		printf("Cleanup success\n");
		return 0;
	}

}
