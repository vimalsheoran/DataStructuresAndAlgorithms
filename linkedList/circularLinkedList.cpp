#include "circularLinkedList.h"

int CLL::no_of_nodes(Node *head){
	
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

void CLL::print_list(Node* head){
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