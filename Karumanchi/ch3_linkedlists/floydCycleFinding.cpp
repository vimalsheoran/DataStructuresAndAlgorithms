#include <iostream>
#include "linkedList.h"

using namespace std;

LinkedList ll;

void find_cycle(){
	Node *slow_ptr, *fast_ptr;
	slow_ptr = fast_ptr = ll.head;

	int offset = 2;
	int pace = 0;

	while(true){
		pace++;
		fast_ptr = fast_ptr->next;
		if(pace == offset){
			slow_ptr = slow_ptr->next;
			pace = 0;
		}
		if(fast_ptr = slow_ptr){
			printf("Cycle detected!\n");
			return;
		}
		if(fast_ptr == NULL){
			printf("Non cyclic list!\n");
			return;
		}
	}

}

int main(){
	printf("Generating linked list.....\n");
	ll.cyclic_list(10);
	printf("List generated.\n");
	printf("Detecting cycle....\n");
	find_cycle();
}
