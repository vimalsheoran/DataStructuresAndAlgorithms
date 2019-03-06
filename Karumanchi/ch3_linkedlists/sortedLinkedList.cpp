#include "linkedList.h"

using namespace std;

LinkedList ll;

void do_sorted_entry(int data){
	if(ll.head == NULL){
		ll.push(data);
		return;
	}else if(data <= ll.head->data){
		ll.insert_head(data);
		return;
	}else{
		Node *temp_node = ll.head;

		while(temp_node->next != NULL){
			if(temp_node->next->data < data)
				temp_node = temp_node->next;
			else
				break;
		}
		if(temp_node->next == NULL){
			ll.insert_end(data, temp_node);
			return;
		}
		ll.insert_middle(data, temp_node);
		return;	
	}
}

int main(){
	printf("Welcome to sorted linked lists!\n");
	printf("Just start entering integers and you will see your list populate!\n");
	int data;
	while(true){
		cin >> data;
		do_sorted_entry(data);
		ll.print_list();
	}
}