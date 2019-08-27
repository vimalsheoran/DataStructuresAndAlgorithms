#include <bits/stdc++.h>

using namespace std;

void bubble_sort(int arr[], int N) {
	int outer_loop_counter = 0;
	for (int i = 0; i < N; i++) {
		outer_loop_counter++;
		int swap_counter = 0;
		for (int j = 0; j < N-1; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
				swap_counter++;
			}
		}
		if (swap_counter == 0) break;
	}

	cout << "Iterations made: " << outer_loop_counter << endl;

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {

	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) cin >> arr[i];

	bubble_sort(arr, N);
}