#include <iostream>

using namespace std;

void selection_sort(int arr[], int N) {
	for (int i = N-1; i >= 0; i--) {
		int curr_max_index = 0;
		for (int j = 0; j <= i; j++) {
			curr_max_index = (arr[curr_max_index] > arr[j]) ? curr_max_index : j; 
		}
		int temp = arr[curr_max_index];
		arr[curr_max_index] = arr[i];
		arr[i] = temp;
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	cout << endl;
}

int main() {

	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) cin >> arr[i];

	selection_sort(arr, N);
}