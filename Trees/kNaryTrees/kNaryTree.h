#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

struct Node{
	int data;
	vector <Node*> children;
};

class KNaryTree{
public:
	void add_node(int, int, Node*);
	void print_tree(Node*);
	Node* search_node(int, Node*);
	Node* root = NULL;
	void init_tree(int);
private:
};

extern KNaryTree kTree;