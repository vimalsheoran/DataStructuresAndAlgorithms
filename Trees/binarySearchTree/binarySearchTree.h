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
	Node* getRoot();
	Node* root = NULL;
//private:
};

extern BinaryTree bst;