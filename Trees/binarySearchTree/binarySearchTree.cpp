#include <iostream>
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
		while(iter->left != NULL || 
			iter->right != NULL){
			if(newNode->data > iter->data){
				iter = iter->right;
			}else if(newNode->data <= iter->data){
				iter = iter->left;
			}
		}
		if(newNode->data > iter->data){
			iter->right = newNode;
		}else{
			iter->left = newNode;
		}
	}
}

void BinaryTree::search(int data){
	Node *iter = root;
	while(true){
		if(iter == NULL){
			printf("No match found!\n");
			return;
		}else if(data == iter->data){
			printf("Match found!\n");
			return;
		}else if(data > iter->data){
			iter = iter->right;
		}else if(data < iter->data){
			iter = iter->left;
		}
	}
	
}

