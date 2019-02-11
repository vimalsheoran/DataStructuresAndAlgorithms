#include "linkedListHelper.h"

// LinkedList::front = NULL;
// LinkedList::numOfElements = 0;

void LinkedList::enqueue(int data){
	
	if(isFull()){
		printf("The buffer is full\n");
		return;
	}else{ 
		Node *newNode = new Node();
		newNode->data = data;
		if(isEmpty()){
			rear = front;
			newNode->next = NULL;
			rear = newNode;
			front = newNode;
			numOfElements++; return;
		}else{
			newNode->next = NULL;
			rear->next = newNode;
			rear = newNode;
			numOfElements++; return;
		}
	}
}

void LinkedList::dequeue(){

	if(isEmpty()){
		printf("The buffer is empty\n");
		return;
	}else if(front == rear){
		Node *lastNode = front;
		free(lastNode);
		rear = front = NULL;
		numOfElements--; return;
	}else{
		Node* current = front;
		front = front->next;
		free(current);
		numOfElements--; return;
	}
}

bool LinkedList::isEmpty(){
	return numOfElements == 0 ? true : false;
}

bool LinkedList::isFull(){
	return numOfElements == 5 ? true : false;
}

void LinkedList::size(){
	printf("The size of the queue is: %d\n", numOfElements);
	return;
}

void LinkedList::display(){
	Node* start = front;
	while(start != NULL){
		printf("%d ", start->data);
		start = start->next;
	}
	printf("\n"); return;
}