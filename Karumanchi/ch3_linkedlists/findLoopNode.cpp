#include <iostream>
#include "linkedList.h"

using namespace std;

LinkedList ll;

int find_loop(){
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
		if(fast_ptr == slow_ptr){
			printf("Cycle detected!\n");
			return fast_ptr->data;
		}
		if(fast_ptr == NULL){
			printf("Non cyclic list!\n");
			return 0;
		}
	}

}

int main(){
	printf("Generating linked list.....\n");
	ll.cyclic_list();
	printf("List generated.\n");
	printf("Detecting cycle....\n");
	int node = find_loop();
	printf("The cycle occurs at Node: %d\n", node);
}