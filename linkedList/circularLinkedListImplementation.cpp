#include <iostream>
#include "circularLinkedList.h"

using namespace std;

CLL cll;

int main(){

	int choice, data, node_count;

	while(true){

		printf("1. Insert Node at beginning\n");
		printf("2. Insert Node at end\n");
		printf("3. Delete Node at beginning\n");
		printf("4. Delete Node at end\n");
		printf("5. Print list\n");
		printf("6. Print Number of nodes\n");

		printf("Enter your choice: ");
		cin >> choice;

		switch(choice){

			case 1:
			printf("Enter the data: ");
			cin >> data;
			cll.insert_beginning(data);
			cll.print_contents();
			break;

			case 2:
			printf("Enter the data: ");
			cin >> data;
			cll.insert_end(data);
			cll.print_contents();
			break;

			case 3:
			cll.delete_beginning();
			cll.print_contents();
			break;

			case 4:
			cll.delete_end();
			cll.print_contents();
			break;

			case 5:
			cll.print_contents();
			break;

			case 6:
			node_count = cll.count_nodes();
			printf("Total number of nodes is %d\n", 
				node_count);
			break;
		}
	}
}