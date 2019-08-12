// Leader is an element in the array such that it has no
// element greater than it on the right hand side of it.

#include <iostream>

using namespace std;

void find_leaders(int *arr, int N) {
	int curr_max = arr[N-1];
	printf("%d ", curr_max);
	for (int i = N - 2; i >= 0; i--) {
		if (arr[i] > curr_max) {
			curr_max = arr[i];
			printf("%d ", curr_max);
		}
	}
	printf("\n");
}

int main() {
	int N;
	cout << "Enter the size of the array: ";
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	find_leaders(arr, N);
}