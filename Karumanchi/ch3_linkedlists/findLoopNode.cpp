#include <iostream>
#include "linkedList.h"

using namespace std;

LinkedList ll;

int find_loop(int *length){
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
			int counter = 1;
			fast_ptr = fast_ptr->next;
			while(fast_ptr != slow_ptr){
				fast_ptr = fast_ptr->next;
				counter++;
			}
			*length = counter;
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
	int length = 0;
	int node = find_loop(&length);
	printf("The cycle occurs at Node: %d\n", node);
	printf("Length of the loop is %d\n", node);
}