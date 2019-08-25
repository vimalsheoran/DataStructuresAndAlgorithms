#include <iostream>

using namespace std;

int find_peak(int *arr, int low, int high, int size) {
	int mid = low + (high - low)/2;
	int peak_right, peak_left;
	if (low > high) return -1;
	if (mid == 0 && arr[mid] > arr[mid+1]) return mid;
	if (mid == size-1 && arr[mid] > arr[mid-1]) return mid;
	if (arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]) {
		return mid;
	}
	if (arr[mid] < arr[mid-1]) {
		peak_left = find_peak(arr, low, mid-1, size);
	}
	if (arr[mid] < arr[mid+1]) {
		peak_right = find_peak(arr, mid+1, high, size);
	}
	return max(peak_right, peak_left);
}

int main() {

	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int peak = find_peak(arr, 0, N-1, N);
	cout << peak << endl;
}