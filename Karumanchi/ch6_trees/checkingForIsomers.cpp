// An algorithm for checking isomorphic trees
// Author: Vimal Sheoran
// Date: March 27, 2019
// Comments: Basic
// T(n) = O(n)
// S(n) = O(n), size of the recursive stack

#include <cstdlib>

using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

bool is_isomorphic(Node *root1, Node *root2){
	if (root1 == NULL && root2 == NULL)
		return true;
	if ((root1 == NULL && root2 != NULL )||
		(root1 != NULL && root2 == NULL))
		return false;
	return (is_isomorphic(root1->left, root2->left) &&
			is_isomorphic(root1->right, root2->right));
}

bool is_quasimorphic(Node *root1, Node *root2){
	if (root1 == NULL && root2 == NULL)
		return true;
	if ((root1 == NULL && root2 != NULL )||
		(root1 != NULL && root2 == NULL))
		return false;
	return ((is_quasimorphic(root1->left, root2->left) &&
			is_quasimorphic(root1->right, root2->right)) ||
			(is_quasimorphic(root1->left, root2->right) &&
			is_quasimorphic(root1->right, root2->left)));	
}