#include "circularLinkedList.h"

int CLL::noOfNodes(Node *head){
	
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