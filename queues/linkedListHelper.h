#include <iostream>

struct Node{
	int data;
	Node* next;
};

class LinkedList{
public:
	void enqueue(int data);
	void dequeue();
	bool isEmpty();
	bool isFull();
	void size();
	void display();
private:
	int numOfElements = 0;
	Node *front = NULL;
	Node *rear;
};

//extern LinkedList buffer;