#include <iostream>
#include <cstddef>

struct Node{
	int data;
	Node* next;
};

class LinkedList{
public:
	void push(int);
	void print_list();
	void insert_head(int);
	void insert_middle(int, Node*);
	void insert_end(int, Node*);
	void cyclic_list();
	void generate_list();
	Node* head = NULL;
private:
	void set_head(int);
};

extern LinkedList ll;