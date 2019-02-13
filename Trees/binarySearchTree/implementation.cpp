#include <iostream>
#include "binarySearchTree.h"

using namespace std;

BinaryTree bst;

int main(){
	
	int data, choice;

	while(1){
		printf("1. Insert an element\n");
		printf("2. Search for an element\n");
		printf("3. Show mininum element\n");
		printf("4. Show maximum element\n");

		printf("\nEnter your choice: ");
		cin >> choice;

		switch(choice){

			case 1:
			printf("\nEnter data to be inserted: ");
			cin >> data;
			bst.insert(data);
			break;

			case 2:
			printf("\nEnter data to be searched for: ");
			cin >> data;
			bst.search(data);
			break;

			case 3:
			bst.findMin();
			break;

			case 4:
			bst.findMax();
			break;

			default:
			printf("Enter a valid option\n");
			break;
		}
	}
}
