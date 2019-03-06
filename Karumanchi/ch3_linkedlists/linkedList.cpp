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

void LinkedList::cyclic_list(){
	Node *cycle_point;
	Node *prev_node = head;
	for(int i = 0; i < 9; i++){
		Node *new_node = new Node();
		new_node->data = i;
		new_node->next = NULL;

		if(head == NULL){
			head = new_node;
			prev_node = new_node;
		}else{
			Node *temp = prev_node;
			temp->next = new_node;
			prev_node = new_node;
		}

		if(i == 5){
			cycle_point = new_node;
		}
	}

	Node *last_node = new Node();
	last_node->data = 9;
	prev_node->next = last_node;
	last_node->next = cycle_point;
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