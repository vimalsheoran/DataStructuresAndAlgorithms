#include <cstddef>

struct Node{
	int data;
	Node* next;
};

class CLL{
public:
	int noOfNodes(Node*);
private:
	Node* root = NULL;
};

extern CLL cll;