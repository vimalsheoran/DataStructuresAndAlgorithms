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

void LinkedList::insert_head(int data){
	if(head == NULL){
		set_head(data);
		return;
	}
	Node *new_node = new Node();
	new_node->data = data;
	new_node->next = head;
	head = new_node;
	return;
}

void LinkedList::insert_middle(int data, Node *prev_node){
	if(head == NULL){
		set_head(data);
		return;
	}
	Node *new_node = new Node();
	new_node->data = data;
	printf("This is the prev node data: %d\n", prev_node->data);
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	return;
}

void LinkedList::insert_end(int data, Node *prev_node){
	if(head == NULL){
		set_head(data);
		return;
	}
	Node *new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	prev_node->next = new_node;
	return;
}

void LinkedList::set_head(int data){
	Node *new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	head = new_node;
	return;
}

void LinkedList::generate_list(){
	Node *prev_node;
	for(int i = 0; i < 10; i++){
		Node *new_node = new Node();
		new_node->data = i;
		new_node->next = NULL;
		if(head == NULL){
			head = new_node;
			prev_node = new_node;
		}else{
			prev_node->next = new_node;
			prev_node = new_node;
		}
	}
	return;
}