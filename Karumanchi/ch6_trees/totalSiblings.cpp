// An algorithm to find the total number of siblings for a given generic tree
// Author: Vimal Sheoran
// Date: March 27, 2019
// Comments: Pretty straigth forward
// T(n) = O(n)
// S(n) = O(1)

#include <cstdlib>

struct Node{
	int data;
	Node *first_child;
	Node *next_sibling;
};

int no_of_siblings(Node *node){
	if(node->next_sibling == NULL)
		return 0;
	int count = 0;
	while(node != NULL){
		count++;
		node = node->next_sibling;
	}
	return count;
}