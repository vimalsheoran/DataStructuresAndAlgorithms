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

Node* BinaryTree::searchParent(Node *root, int childVal){
	if(root == NULL) return root;
	if (root->left->data == childVal ||
		root->right->data == childVal) return root;
	if(childVal <= root->data) 
		searchParent(root->left, childVal);
	if(childVal > root->data) 
		searchParent(root->right, childVal);
}

int BinaryTree::noOfGrandChildren(Node* parent, int childVal){
	int grandChildren = 0;
	
	Node *child = parent->left->data == childVal 
				? parent->left : parent->right;

	if(child->left != NULL && child->right !=NULL)
		grandChildren = 2;
	if(child->left != NULL || child->right != NULL)
		grandChildren = 1;
	return grandChildren;
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

Node* BinaryTree::getMax(Node *root){
	if(root->right == NULL)
		return root;
	root = root->right;
	getMax(root);
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

bool BinaryTree::checkForBst(Node* root){
	
	if(root == NULL) return true;
	if(root->left == NULL && root->right == NULL) return true;

	if(root->left == NULL){
		bool check = root->data < root->right->data
		?true
		:false;

		return check;

	}else if(root->right == NULL){
		bool check = root->data >= root->left->data
		?true
		:false;

		return check;
	}

	if( root->data >= root->left->data &&
		root->data < root->right->data){ 
		return true;
	}else{return false;}

	checkForBst(root->left);
	checkForBst(root->right);
}

void BinaryTree::deleteNode(Node* root, int valToDelete){

	if(root == NULL){
		printf("No node found to delete\n");
		return;
	}

	if(valToDelete < root->data){
		deleteNode(root->left, valToDelete);
	}else if(valToDelete > root->data){
		deleteNode(root->right, valToDelete);
	}

	if(root->data == valToDelete){
		if( root->left == NULL &&
			root->right == NULL){
			Node* parent = searchParent(root, root->data);
			if(parent->left == root) 
				parent->left = NULL;
			if(parent->right == root)
				parent->right = NULL;
			delete root;
		}else if(root->left == NULL){
			Node* temp = root;
			root = root->right;
			delete temp;
		}else if(root->right == NULL){
			Node* temp = root;
			root = root->left;
			delete temp;
		}else{
			Node *maxLeftSubTree = getMax(root);
			int tempData = maxLeftSubTree->data;
			Node* parentMax = searchParent(root, tempData);
			deleteNode(root, maxLeftSubTree->data);
			parentMax->right = NULL;
			root->data = tempData;
		}
	}

	return;
	
	// Node *parentNode = searchParent(root, valToDelete);
	// Node *child;
	// Node *grandChild;

	// if(parentNode == NULL){
	// 	printf("The tree is empty, nothing to delete\n");
	// 	return;
	// }

	// int grandChildren = noOfGrandChildren(parentNode, valToDelete);

	// if(valToDelete == parentNode->left->data)
	// 		child = parentNode->left;
	// if(valToDelete == parentNode->right->data)
	// 		child = parentNode->right;

	// if(grandChildren == 0){
	// 	free(child);
	// 	if(parentNode->left == 0)
	// 		parentNode->left = NULL;
	// 	if(parentNode->right == 0)
	// 		parentNode->right = NULL;
	// }

	// if(grandChildren == 1){

	// 	if(child->left != NULL) grandChild = child->left;
	// 	if(child->right != NULL) grandChild = child->right;

	// 	if(parentNode->left == child){
	// 		parentNode->left = grandChild;
	// 		free(child);
	// 	}

	// 	if(parentNode->right == child){
	// 		parentNode->right = grandChild;
	// 		free(child);
	// 	}
	// }

	// if(grandChildren == 2){
	// 	Node *maxLeftSubTree = getMax(child);
	// 	int tempData = maxLeftSubTree->data;
	// 	deleteNode(maxLeftSubTree->data);	
	// 	child->data = tempData;
	// }
}

void BinaryTree::deleteTree(Node *root){
	if(root == NULL){
		return;
	}else{
		deleteTree(root->left);
		deleteTree(root->right);
		free(root);
		return;
	}
}

int BinaryTree::noOfLeaves(Node *root){
	if(root == NULL)
		return 0;
	
	int leafCount = 0;
	std::queue <Node*> nodeBuffer;
	nodeBuffer.push(root);

	while(!nodeBuffer.empty()){
		Node* current = nodeBuffer.front();
		if (current->left == NULL &&
			current->right == NULL)
			leafCount++;
		if(current->left != NULL) nodeBuffer.push(current->left);
		if(current->right != NULL) nodeBuffer.push(current->right);
		nodeBuffer.pop();
	}

	return leafCount;
}

int BinaryTree::diameter(Node *root){
	if(root == NULL)
		return 0;
	
	// Finding the size of the root chord
	int rootChord = findHeight(root->left)+
		findHeight(root->right)+
		1;

	// Finding the size of the left sub tree chord
	int lstChord = diameter(root->left);
	int rstChord = diameter(root->right);

	return std::max(
		rootChord, 
		std::max(lstChord, rstChord));
}

void BinaryTree::dispAllPaths(Node *root, int *pathArr, int pathLen){
	if(root == NULL)
		return;
	pathArr[pathLen] = root->data;
	pathLen++;
	if (root->left == NULL &&
		root->right == NULL){
		printArray(pathArr, pathLen);
	}else{
		if(root->left != NULL)
			dispAllPaths(root->left, pathArr, pathLen);
		if(root->right != NULL)
			dispAllPaths(root->right, pathArr, pathLen);
	}
}

void BinaryTree::printArray(int *array, int arrLen){
	for(int i = 0; i < arrLen; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}