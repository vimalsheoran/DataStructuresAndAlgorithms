#include <iostream>
#include <queue>
#include "binarySearchTree.h"

void BinaryTree::insert(int data){
	if(root == NULL){
		root = new Node();
		root->data = data;
		return;
	}else{
		Node *newNode = new Node();
		Node *iter = root;
		newNode->data = data;
		while(true){
			if(newNode->data > iter->data){
				if(iter->right == NULL){
					iter->right = newNode;
					return;
				}else{
					iter = iter->right;
				}
			}else{
				if(iter->left == NULL){
					iter->left = newNode;
					return;
				}else{
					iter = iter->left;
				}
			}
		}
	}
}

void BinaryTree::search(int data){
	Node *iter = root;
	while(true){
		if(iter == NULL){
			printf("No match found!\n");
			free(iter);
			return;
		}else if(data == iter->data){
			printf("Match found!\n");
			free(iter);
			return;
		}else if(data > iter->data){
			iter = iter->right;
		}else if(data < iter->data){
			iter = iter->left;
		}
	}
}

void BinaryTree::findMax(){
	if(root == NULL){
		printf("The tree is empty\n");
		return;
	}else{
		Node *iter = root;
		while(iter->right != NULL){
			iter = iter->right;
		}
		printf("The Maximum element in the tree is: %d\n",
			iter->data);
		return;
	}
}

void BinaryTree::findMin(){
	if(root == NULL){
		printf("The tree is empty\n");
		return;
	}else{
		Node *iter = root;
		while(iter->left != NULL){
			iter = iter->left;
		}
		printf("The Minimum element in the tree is: %d\n",
			iter->data);
		return;
	}
}

int BinaryTree::findHeight(Node *root){
	if(root == NULL) return -1;
	return std::max(findHeight(root->left), findHeight(root->right)) + 1;
}

Node* BinaryTree::getRoot(){
	return root;
}

void BinaryTree::levelOrderTraversal(Node *root){
	
	if(root == NULL){
		printf("The tree is empty\n");
		return;
	}

	std::queue <Node*> nodeBuffer;
	nodeBuffer.push(root);

	while(!nodeBuffer.empty()){
		Node* current = nodeBuffer.front();
		printf("%d ", current->data);
		if(current->left != NULL) nodeBuffer.push(current->left);
		if(current->right != NULL) nodeBuffer.push(current->right);
		nodeBuffer.pop();
	}

	printf("\n"); return;
}

void BinaryTree::preorderTraversal(Node* root){
	if(root == NULL) return;
	printf("%d ", root->data);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void BinaryTree::inorderTraversal(Node* root){
	if(root == NULL) return;
	preorderTraversal(root->left);
	printf("%d ", root->data);
	preorderTraversal(root->right);
}

void BinaryTree::postorderTraversal(Node* root){
	if(root == NULL) return;
	preorderTraversal(root->left);
	preorderTraversal(root->right);
	printf("%d ", root->data);
}