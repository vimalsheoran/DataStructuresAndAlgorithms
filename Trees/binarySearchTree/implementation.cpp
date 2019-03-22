#include <iostream>
#include "binarySearchTree.h"

using namespace std;

BinaryTree bst;

int main(){
	
	int data, choice;
	bool flag;
	Node *ancestor;

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
		printf("12. Delete Tree\n");
		printf("13. No of leaves\n");
		printf("14. Calculate diameter of the tree\n");
		printf("15. Display all paths\n");
		printf("16. Get sum of all elements\n");
		printf("17. Find common ancestor\n");
		printf("18. Find all ancestors\n");

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

			case 12:
			if(bst.root == NULL){
				printf("\nThe tree is already empty, nothing to delete");
				break;
			}
			bst.deleteTree(bst.root);
			break;

			case 13:
			data = bst.noOfLeaves(
				bst.root);
			printf("No of leaves is: %d\n", data);
			break;

			case 14:
			data = bst.diameter(
				bst.root);
			printf("The diameter of the tree is: %d\n",
				data);
			break;

			case 15:
			if(bst.root == NULL){
				printf("The tree is empty\n");
				break;
			}
			int *pathArr;
			bst.dispAllPaths(bst.root, pathArr, 0);
			break;

			case 16:
			data = bst.getSum(bst.root);
			printf("Sum of all elements: %d\n", data);
			break;

			case 17:
			printf("Enter the two numbers\n");
			int a, b;
			cin >> a >> b;
			ancestor = bst.leastCommonAncestor(
				bst.root, a, b);
			printf("The ancestor is: %d\n", ancestor->data);
			break;

			case 18:
			printf("Enter the value for finding ancestors\n");
			cin >> data;
			bst.allAncestors(
				bst.root,
				data);
			break;

			default:
			printf("Enter a valid option\n");
			break;
		}
	}
}
