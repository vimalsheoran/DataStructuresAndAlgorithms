#include "heap.h"
#include <iostream>

void Heap::push(int data){
	if (heap_ref.empty()){
		heap_ref.push_back(data);
		return;
	} else {
		heap_ref.push_back(data);
		int i = heap_ref.size() - 1;
		while(i > 0){
			i = insertion_swap(heap_ref, i);
		}
	}
	return;
}

int Heap::pop(){
	int head;
	if(heap_ref.empty()){
		printf("The heap is empty, nothing to remove.\n");
		return 0;
	} else if(heap_ref.size() == 1){
		head = heap_ref[0];
		heap_ref.clear();
		return head;
	} else {
		int curr_size = heap_ref.size();
		head = heap_ref[0];
		heap_ref[0] = heap_ref[curr_size - 1];
		heap_ref.pop_back();
		curr_size = heap_ref.size();
		int i = 0;
		while(i < curr_size && i != -1){
			i = deletion_swap(heap_ref, i, curr_size);
		}
		return head;
	}
}

void Heap::print_heap(){
	for(int i = 0; i < heap_ref.size(); i++){
		printf("%d ", heap_ref.at(i));
	}
	printf("\n");
	return;
}

int Heap::insertion_swap(vector <int> &heap_ref, int i){
	int temp;
	if(i%2 == 0){
		temp = heap_ref[(i-2)/2];
		if(heap_ref[(i-2)/2] < heap_ref[i]){
			heap_ref[(i-2)/2] = heap_ref[i];
			heap_ref[i] = temp;
			i = (i - 2)/2;
		} else {
			return 0;
		}
	} else {
		temp = heap_ref[(i-1)/2];
		if(heap_ref[(i-1)/2] < heap_ref[i]){
			heap_ref[(i-1)/2] = heap_ref[i];
			heap_ref[i] = temp;
			i = (i - 1)/2;
		} else {
			return 0;
		}
	} return i;
}

int Heap::deletion_swap(vector <int> &heap_ref, int i, int curr_size){
	int temp;
	int lci = (2*i) + 1;
	int rci = (2*i) + 2;
	if(lci >= curr_size && rci >= curr_size)
		return -1;
	int gci = (heap_ref[lci] < heap_ref[rci]) ? rci : lci;
	if(heap_ref[i] < heap_ref[gci]){
		temp = heap_ref[i];
		heap_ref[i] = heap_ref[gci];
		heap_ref[gci] = temp;
		return gci;
	} else {
		return -1;
	}
}

void Heap::sort(){
	int curr_size = heap_ref.size();
	int last_index = curr_size-1;
	int top;
	vector <int> sorted_heap; 
	for(int i = 0; i < curr_size; i++){
		top = pop();
		sorted_heap.push_back(top);
		last_index--;
	}
	for(int i = 0; i < curr_size; i++){
		printf("%d ", sorted_heap[i]);
	} printf("\n");
	return;
}

vector <int> Heap::heapify(Node *root){
	vector <int> non_heapified;
	if(!root){
		printf("No reference provided to the tree.");
		return non_heapified;
	}
	queue <Node*> level_order_q;
	level_order_q.push(root);
	while(!level_order_q.empty()){
		Node *top = level_order_q.front();
		if(top->left)
			level_order_q.push(top->left);
		if(top->right)
			level_order_q.push(top->right);
		heap_ref.push_back(top->data);
		level_order_q.pop();
	}
}

int Heap::find_max_in_min_heap(){
	if(!heap_ref.size()){
		printf("Empty heap");
		return 0;
	}
	int max, lci;
	for(int i = 0; i < heap_ref.size() - 1;){
		lci = (2*i) + 1;
		if(lci < heap_ref.size()){
			max = heap_ref[lci];
			printf("max: %d\n", max);
			i = lci;
		} else {
			max = heap_ref[i];
			i++;
		}
	} return max;
}