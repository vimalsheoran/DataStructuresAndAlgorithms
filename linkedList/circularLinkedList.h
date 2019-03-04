#include <cstddef>
#include <iostream>

struct Node{
	int data;
	Node* next;
};

class CLL{
public:
	int no_of_nodes(Node*);
	void print_list(Node*);
	void push(Node*, int);
	Node* root = NULL;
private:
	int list_length = 0;
};

extern CLL cll;