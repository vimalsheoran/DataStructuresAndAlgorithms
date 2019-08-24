#include <iostream>

using namespace std;

int binary_search(int arr[], int low, int high, int x) {
	while (low <= high) {
		int mid = low + (high - low)/2;

		if (arr[mid] == x) return mid;

		if (arr[mid] > x) {
			high = mid-1;
			continue;
		}

		if (arr[mid] < x) {
			low = mid+1;
			continue;
		}
	}
	return -1;
}

int find_pivot(int arr[], int low, int high) {
	if (low > high) return -1;
	if (low == high) return low;

	int mid = low + (high-low)/2;

	if (mid < high && arr[mid] > arr[mid+1]) {
		return mid;
	}

	if (mid > low && arr[mid-1] > arr[mid]) {
		return mid-1;
	}

	if (arr[low] >= arr[mid]) {
		return find_pivot(arr, low, mid-1);
	}

	return find_pivot(arr, mid+1, high);
}

int main() {

	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) cin >> arr[i];
	int x;
	cin >> x;

	int pivot;
	pivot = find_pivot(arr, 0, N);
	int s1 = binary_search(arr, 0, pivot, x);
	int s2 = binary_search(arr, pivot+1, N-1, x);
	// Assumes that all inputs are distinct
	cout << max(s1, s2) << endl;
}