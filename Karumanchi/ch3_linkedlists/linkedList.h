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
	void cyclic_list(int);
	Node* head = NULL;
};

extern LinkedList ll;