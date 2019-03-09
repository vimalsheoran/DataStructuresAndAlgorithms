#include "linkedList.h"

using namespace std;

LinkedList ll;

void find_midpoint(){
	Node *fast, *slow;
	fast = slow = ll.head;
	int offset = 2;
	while(true){
		offset--;
		fast = fast->next;
		if(offset == 0){
			slow = slow->next;
			offset = 2;
		}
		if( fast == NULL ||
			fast->next == NULL){
			printf("Midpoint: %d\n",
				slow->data);
			break;
		}
	}
}

int main(){
	ll.generate_list();
	ll.print_list();
	find_midpoint();
	return 0;
}