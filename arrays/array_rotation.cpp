/**
* Demonstrating two techniques to rotate an array.
*/

#include <iostream>

using namespace std;

void print_array(int *arr) {
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Swap based rotation, worst case complexity = O(n*n)
void rotate_simple_swap(int k) {
	int a[5] = {1, 2, 3, 4, 5};
	for (int i = 0; i < k%5; i++) {
		for (int j = 1; j < 5; j++) {
			int temp = a[j-1];
			a[j-1] = a[j];
			a[j] = temp;
		}
	}
	print_array(a);
}

// Reversal based rotation, worst case complexity = O(n)
// Works on a simple principle, reverse array from 0, k
// then reverse from k, n-1 and finally reverse the entire
// array.

void reverse_array(int *arr, int start_index, int end_index) {
	while (start_index < end_index) {
		int temp = arr[start_index];
		arr[start_index] = arr[end_index];
		arr[end_index] = temp;
		start_index++; end_index--;
	}
}

void rotate_reversal_technique(int k) {
	k = k%5;
	int a[5] = {1, 2, 3, 4, 5};
	reverse_array(a, 0, k-1);
	reverse_array(a, k, 4);
	reverse_array(a, 0, 4);
	print_array(a);
}

int main() {
	int rotations = 2;
	int a[5] = {1, 2, 3, 4, 5};
	rotate_simple_swap(rotations);
	rotate_reversal_technique(rotations);
}