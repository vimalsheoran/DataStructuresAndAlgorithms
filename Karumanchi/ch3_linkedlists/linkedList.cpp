#include "linkedList.h"

void LinkedList::push(int data){
	Node *new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;

	if(head == NULL){
		head = new_node;
		return;
	}

	Node *temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = new_node;
	return;
}

void LinkedList::print_list(){
	if(head == NULL){
		printf("The list is empty\n");
		return;
	}

	Node *temp = head;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return;
}