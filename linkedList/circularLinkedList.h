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
private:
	Node* root = NULL;
	int list_length = 0;
};

extern CLL cll;