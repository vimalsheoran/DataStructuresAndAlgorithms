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
		temp = heap_ref[(i-2/2)];
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