#include <cstdlib>

struct Node{
	int data;
	Node* left; 
	Node* right;
};

class BinaryTree{
public:
	void insert(int);
	void search(int);
	void findMax();
	void findMin();
	int findHeight(Node*);
	void levelOrderTraversal(Node *);
	void preorderTraversal(Node *);
	void inorderTraversal(Node *);
	void postorderTraversal(Node *);
	void deleteNode(Node*, int);
	void deleteTree(Node *);
	int noOfLeaves(Node *);
	int diameter(Node *);
	void dispAllPaths(Node *, int*, int);
	bool checkForBst(Node *);
	Node* getRoot();
	int getSum(Node *);
	Node* leastCommonAncestor(Node*, int, int);
	Node* root = NULL;
private:
	Node* getMax(Node*);
	int noOfGrandChildren(Node*, int);
	Node* searchParent(Node*, int);
	void printArray(int*, int);
};

extern BinaryTree bst;