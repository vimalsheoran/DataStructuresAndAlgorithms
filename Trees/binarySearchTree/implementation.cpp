#include <iostream>
#include "binarySearchTree.h"

using namespace std;

BinaryTree bst;

int main(){
	
	int data, choice;
	bool flag;

	while(1){
		printf("1.  Insert an element\n");
		printf("2.  Search for an element\n");
		printf("3.  Show mininum element\n");
		printf("4.  Show maximum element\n");
		printf("5.  Calculate Height of the tree\n");
		printf("6.  Perform Level Order Traversal\n");
		printf("7.  Perform PreOrder Traversal\n");
		printf("8.  Perform InOrder Traversal\n");
		printf("9.  Perform PostOrder Traversal\n");
		printf("10. Check for BST\n");
		printf("11. Delete Node\n");

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

			case 5:
			printf("The height of the tree is %d\n",
				bst.findHeight(bst.root));
			break;

			case 6:
			bst.levelOrderTraversal(bst.root);
			break;

			case 7:
			bst.preorderTraversal(bst.root);
			printf("\n"); break;

			case 8:
			bst.inorderTraversal(bst.root);
			printf("\n"); break;

			case 9:
			bst.postorderTraversal(bst.root);
			printf("\n"); break;

			case 10:
			flag = bst.checkForBst(bst.root);
			if(flag) printf("The tree is a binary search tree\n");
			else printf("The tree is not a binary search tree\n");
			break;

			case 11:
			printf("\nEnter data to be deleted: ");
			cin >> data;
			bst.deleteNode(bst.root, data);
			break;

			default:
			printf("Enter a valid option\n");
			break;
		}
	}
}
