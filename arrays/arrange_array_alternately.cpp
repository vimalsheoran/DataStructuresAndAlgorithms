#include <iostream>

using namespace std;

void rearrange(int *arr, int start_index, int N) {
	if (start_index+1 >= N) return;
	int max = start_index;
	int min = start_index;

	for (int i = start_index+1; i < N; i++) {
		if (arr[i] > arr[max]) max = i;
	}

	int temp = arr[max];
	arr[max] = arr[start_index];
	arr[start_index] = temp;

	for (int i = start_index+1; i < N; i++) {
		if (arr[i] < arr[min]) min = i;
	}

	temp = arr[min];
	arr[min] = arr[start_index+1];
	arr[start_index+1] = temp;
}

int main() {

	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N;) {
		rearrange(arr, i, N);
		i += 2;
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}