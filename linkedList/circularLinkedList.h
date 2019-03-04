#include <cstddef>
#include <iostream>

struct Node{
	int data;
	Node* next;
};

class CLL{
public:
	int no_of_nodes();
	void print_list();
	void push(int);
	void pop();
	void insert_head(int);
	void delete_head();
private:
	Node* head = NULL;
	int list_length = 0;
};

extern CLL cll;