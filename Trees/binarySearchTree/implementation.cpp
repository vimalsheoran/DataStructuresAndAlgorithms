#include <iostream>
#include "binarySearchTree.h"

using namespace std;

BinaryTree bst;

int main(){
	
	int data, choice;

	while(1){
		printf("1. Insert an element\n");
		printf("2. Search for an element\n");

		printf("\n\nEnter your choice: ");
		cin >> choice;

		switch(choice){

			case 1:
			printf("\n\nEnter data to be inserted: ");
			cin >> data;
			bst.insert(data);
			break;

			case 2:
			printf("\n\nEnter data to be searched for: ");
			cin >> data;
			bst.search(data);
			break;

			default:
			printf("Enter a valid option\n");
			break;
		}
	}
}
