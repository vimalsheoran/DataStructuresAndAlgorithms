// Simple algorithm to find if two trees are identical

struct Node{
	int data;
	Node *left;
	Node *right;
}

bool are_identical(Node *root1, Node *root2){
	if (root1 == NULL &&
		root2 == NULL)
		return true;
	if (root1 == NULL ||
		root2 == NULL)
		return false;
	return (root1->data == root2->data &&
		are_identical(root1->left, root2->left) &&
		are_identical(root1->right, root2->right));
}