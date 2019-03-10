#include "linkedList.h"

using namespace std;

LinkedList ll;

void reverse_pair(Node *head){
	while(true){
		if( head == NULL || 
			head->next == NULL){
			break;
		}
		int data_curr = head->data;
		head->data = head->next->data;
		head->next->data = data_curr;
		head = head->next->next;
	}
}

int main(){
	ll.generate_list();
	ll.print_list();
	reverse_pair(ll.head);
	ll.print_list();
}