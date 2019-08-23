#include <iostream>

using namespace std;

void binarySearch(int arr[], int l, int h, int x) {

	while (l <= h) {
		int mid = l + (h-l)/2;

		if (arr[mid] == x) {
			printf("%d\n", mid);
			break;
		} else if (arr[mid] > x) {
			h = mid - 1;
			continue;
		} else {
			l = mid + 1;
			continue;
		}
	}
}

int main() {

	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) cin >> arr[i];
	int x;
	cin >> x;

	int i = 0;

	while (arr[i] < x) {
		if (i == 0) {
			i = 2;
		} else {
			i *= 2;
		}
	}

	if (arr[i] == x) printf("%d\n", i);
	else binarySearch(arr, i/2, i, x);
}