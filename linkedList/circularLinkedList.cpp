#include "circularLinkedList.h"

int CLL::no_of_nodes(){
	
	if(head == NULL){
		return 0;
	}
	Node *current = head;
	int count = 0;
	do{
		count++;
		current = current->next;
	}while(current != head);
	return count;
}

void CLL::print_list(){
	if(head == NULL){
		printf("The list is empty.\n");
		return;
	}
	Node *current = head;
	do{
		printf("%d ", current->data);
		current = current->next;
	}while(current != head);
	printf("\n"); return;
}

void CLL::push(int data){
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	if(head == NULL){
		new_node->next = head;
		head = new_node;
		return;
	}
	Node *current = head;
	while(current->next != head){
		current = current->next;
	}
	current->next = new_node;
	new_node->next = head;
	return;
}

void CLL::pop(){
	if(head == NULL){
		printf("The list is empty nothing to delete.\n");
		return;
	}
	Node* current = head;
	while(current->next->next != head){
		current = current->next;
	}
	Node *to_delete = current->next;
	current->next = head;
	free(to_delete);
	return;
}

void CLL::insert_head(int data){
	if(head == NULL){
		push(data);
		return;
	}
	Node* new_node = new Node();
	new_node->data = data;

	new_node->next = head->next;
	head = new_node;
	return;
}


