#include <iostream>

using namespace std;

int find_pivot(int arr[], int N) {
	int low = 0, high = N-1;
	if (arr[low] < arr[high]) return -1;
	while (low <= high) {
		int mid = low + (high - low)/2;
		if (arr[mid] < arr[mid-1]) return mid-1;
		if (arr[mid] > arr[mid+1]) return mid;
		if (arr[mid] < arr[low]) high = mid - 1;
		if (arr[mid] > arr[high]) low = mid + 1;
	}

	return -1;
}

int main() {

	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) cin >> arr[i];

	int pivot = find_pivot(arr, N);
	cout << pivot << endl;
}