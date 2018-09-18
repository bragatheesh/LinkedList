#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

//single linked list


struct node {

	int name;
	int value;
	struct node* next;

};

struct node* head = NULL;
struct node* current = NULL;

int init() {

	head = malloc(sizeof(struct node));
	if(head == NULL){

		printf("Error allocating space for head node\n");
		return -1;
	}

	head->name = 0;
	head->value = 0;
	head->next = NULL;
	
	current = head;

	return 0;
}


int cleanup() { //still need to decrement head value

	if(head == NULL) {
		printf("Nothing to cleanup\n");
		return 0;
	} else {
		
		struct node* temp = head;
		struct node* tempNext = NULL;
		
		while(temp->next != NULL) {
			tempNext = temp->next;
			free(temp);
			temp = tempNext;
		}

		free(temp);
		free(head);
		
		return 0;
	}
}

int addToLinkedList(struct node* new) {

	if(current == NULL) {
		printf("Error, no head node initialized. Call init() first\n");
		return -1;
	}

	current->next = new;
	current = new;
	
	head->value++;
	
	return 0;
}

struct node* createNewNode(int name, int value) {

	if(head == NULL){

		printf("Error, head node not initialized. Please call init first\n");
		return NULL;
	}


	struct node* new = malloc(sizeof(struct node));
	if(new == NULL) {
		printf("Error allocating space for new node\n");
		return NULL;
	}

	new->name = name;
	new->value = value;
	new->next = NULL;

	if(addToLinkedList(new) == 0) {

		return new;
	}
	else {
		printf("Error adding new node to linkedlist\n");
		return NULL;
	} 
}



int deleteNode(int name, int value) { //find ndoe to delete by matching name value pair, probably not a good idea unless name, value pair are unique or name is unique

	struct node* temp, *prev;
	int found = 0;
	prev = head;
	temp = head;

	if(name == head->name && value == head->value) {
	
		printf("Error, cannot delete HEAD node\n");
		return -1;
	}

	while(temp->next != NULL) {

		if(temp->name == name && temp->value == value) {
			prev->next = temp->next;
			free(temp);
			head->value--;
			found = 1;
		} else {
			prev = temp;
			temp = temp->next;
		}

	}
	
	if(found == 0 && temp->name == name && temp->value == value) { //case where we delete the last node of the list
		prev->next = NULL;
		free(temp);
		head->value--;
		found = 1;
	}

	if(found)
		return 0;
	else
		return -1;
}



int getLinkedListLength() {
	if(head == NULL) {
		printf("Head not initialized, call init first\n");
		return -1;
	}
	return head->value;
}


void printLinkedList() {
	if(head == NULL) {
		printf("Head not initialized, call init first\n");
		return;
	}

	struct node* temp = head;
	int count = 1;
	
	printf("\n\nHEAD\nNAME: %d\nVALUE: %d\n\n", temp->name, temp->value);
	temp = temp->next;

	while(temp->next != NULL) {
		printf("NODE: %d\nNAME: %d\nVALUE: %d\n\n", count, temp->name, temp->value);
		count++;
		temp = temp->next;
	}
	
	printf("NODE: %d\nNAME: %d\nVALUE: %d\n\n", count, temp->name, temp->value);

}


/*int main(int argc, char** argv) {

printf("hello world\n");

printf("creating a new linekd list\n");

struct node* first = malloc(sizeof(struct node));
if(first == NULL) {
	printf("error allocating memory for node\n");
	return -1;
}

first->name = 0;
first->value = 1;
first->next = NULL;
printf("First node's name: %d\nFirst node's value: %d\n", first->name, first->value);

free(first);
return 0;
}*/
