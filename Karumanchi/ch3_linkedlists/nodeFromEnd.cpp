#include "linkedList.h"

using namespace std;

LinkedList ll;

void populate_list(int length){
	for(int i = 0; i < length; i++){
		int data = i%3;
		ll.push(data);
	}
	ll.print_list();
}

void find_match(int reverse_index){
	Node *current = ll.head, *index = ll.head;
	while(--reverse_index){
		if(current == NULL){
			printf("Index out of bounds\n");
			return;
		}
		current = current->next;
	}

	while(current->next != NULL){
		current = current->next;
		index = index->next;
	}

	printf("The element is %d\n", index->data);
	return;
}

int main(){

	populate_list(100);

	int reverse_index;

	while(true){
		printf("Welcome to node finder\n");
		printf("Enter the index from the end: ");
		cin >> reverse_index;

		find_match(reverse_index);
	}
}