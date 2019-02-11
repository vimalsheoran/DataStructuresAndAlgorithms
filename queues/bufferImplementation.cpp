#include <iostream>
#include "linkedListHelper.h"

using namespace std;

LinkedList buffer;

int main(){

	int data, choice;
	bool flag;

	while(true){

		printf("********   Menu  **********\n");
		printf("*      1. Enqueue         *\n");
		printf("*      2. Dequeue         *\n");
		printf("*      3. Check if empty  *\n");
		printf("*      4. Check if full   *\n");
		printf("*      5. Check Size      *\n");
		printf("*      6. Display         *\n");
		printf("***************************\n");

		printf("\nEnter your choice: ");
		cin >> choice;
		switch(choice){
			
			case 1:
			printf("Enter data to enqueue: ");
			cin >> data;
			buffer.enqueue(data);
			break;

			case 2:
			buffer.dequeue();
			break;

			case 3:
			flag = buffer.isEmpty();
			if(flag){
				printf("The queue is empty\n");
				break;
			}printf("The queue is not empty\n");
			break;

			case 4:
			flag = buffer.isFull();
			if(flag){
				printf("The queue is full\n");
				break;
			}printf("The queue is not full\n");
			break;

			case 5:
			buffer.size();
			break;

			case 6:
			buffer.display();
			break;

			default:
			printf("Invalid choice, try again\n");
			break;
		}
	}
}