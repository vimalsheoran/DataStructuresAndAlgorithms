#include <iostream>
#include "heap.h"

using namespace std;

Heap heap;

int main(){
	int choice, data;
	while(true){
		printf("// heap implementation\n");
		printf("1. Push into the heap\n");
		printf("2. Pop from the heap\n");
		printf("3. Perform heap sort\n");
		cin >> choice;
		switch(choice){
			
			case 1:
			printf("Enter the element you want to insert to your heap ");
			cin >> data;
			heap.push(data);
			heap.print_heap();
			break;

			case 2:
			heap.pop();
			heap.print_heap();
			break;

			case 7:
			heap.push(8);
			heap.push(6);
			heap.push(7);
			heap.push(5);
			break;

			case 8:
			printf("The size of the heap is: %d\n", heap.heap_ref.size());
			break;

			case 9:
			heap.print_heap();
			break;
		}
	}
}