#include <iostream>

using namespace std;

void insertion_sort(int arr[], int N) {

	for (int i = 1; i < N; i++) {
		int key = arr[i];
		int j = i-1;
		while (j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}

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
	
	insertion_sort(arr, N);	
}