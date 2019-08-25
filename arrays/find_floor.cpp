#include <iostream>

using namespace std;

int find_floor(int arr[], int N, int x) {

	int low = 0, high = N-1;

	if (arr[N-1] < x) return N-1;

	while (low <= high) {
		int mid = low + (high - low)/2;
		if (arr[mid] == x)
			return arr[mid];
		if (arr[mid] < x && arr[mid+1] > x)
			return arr[mid];
		if (arr[mid-1] < x && arr[mid] > x)
			return arr[mid-1];
		if (x < arr[mid])
			high = mid - 1;
		if (x > arr[mid])
			low = mid + 1;
	}
	return -1;
}

int main() {

	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) cin >> arr[i];
	int x;
	cin >> x;

	int floor = find_floor(arr, N, x);
	cout << floor << endl;
}