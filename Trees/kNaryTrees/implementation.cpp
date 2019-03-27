#include "kNaryTree.h"

KNaryTree kTree;

int main(){
	int choice;
	int data, parent;

	while(true){
		printf("1.  Add to the tree\n");
		printf("2.  Print tree\n");

		printf("Enter your choice: ");
		cin >> choice;

		switch(choice){

			case 1:
			printf("Enter the data you want to insert: ");
			cin >> data;
			printf("Enter the parent: ");
			cin >> parent;
			if(kTree.root == NULL){
				printf("No root detected, creating one for you...\n");
				kTree.init_tree(data);
				break;
			}
			kTree.add_node(data, parent, kTree.root);
			break;

			case 2:
			printf("Printing the tree...\n");
			kTree.print_tree(kTree.root);
			cout << "" << endl;

			case 3:
			printf("Running test...\n");
			kTree.init_tree(2);
			kTree.add_node(3, 2, kTree.root);
			kTree.add_node(4, 2, kTree.root);
			kTree.add_node(5, 3, kTree.root);
			break;
		}
	}
}