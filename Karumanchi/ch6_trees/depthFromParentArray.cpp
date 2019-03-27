// An algorithm to find the depth of a tree from a given parent array
// Author: Vimal Sheoran
// Date: March 27, 2019
// Comments: Follow notes for explanation
// T(n) = O(n2)
// S(n) = O(1)
/*
	A parent has the following property,
	P[i] contains the parent of the i-th node in the tree.

	example:
	P       = [-1, 0, 1, 6, 6, 0, 0, 2, 7]
	indexes = [0, 1, 2, 3, 4, 5, 6, 7, 8]

						0
					  / | \
					 6	5  1
					/       \
                   3         2
                  /           \
                 4             7
                                \
                                 8
*/

#include <iostream>

using namespace std;

int find_depth(int *parent_arr, int  size){
	
	int curr_depth, max_depth, j;
	max_depth = 0;

	for(int i = 0; i < size; i++){
		curr_depth = 0; j = i;
		while(parent_arr[j] != -1){
			curr_depth++;
			j = parent_arr[j];
		}

		if(curr_depth > max_depth)
			max_depth = curr_depth;
	}

	return curr_depth;
}

int main(){
	int size;
	int arr[100];

	printf("Enter the size of the parent array: ");
	cin >> size;
	printf("Enter the elements of the parent array (max 100), space separated: ");
	
	for(int i = 0; i < size; i++){
		cin >> arr[i]
	}

	int depth = find_depth(arr, size);
	printf("Depth of the given tree is: %d\n", depth);
}