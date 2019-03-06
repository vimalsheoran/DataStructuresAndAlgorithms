#include "linkedList.h"

using namespace std;

LinkedList ll;

void reverse_list(){
	Node* head = ll.head;
	Node* prev = NULL;
	while(head->next != NULL){
		Node* next = head->next;
		Node *temp = head;
		temp->next = prev;
		prev = temp;
		head = next; 
	}
	head->next = prev;
	ll.head = head;
}

int main(){
	ll.generate_list();
	ll.print_list();
	reverse_list();
	ll.print_list();
}