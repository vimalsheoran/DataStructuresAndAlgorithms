#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N; int arr[N];
	for (int i = 0; i < N; i++) cin >> arr[i];
	int x;
	cin >> x;

	int left_most_index;
	int low = 0, high = N-1;

	while(low <= high) {

		int mid = low + (high - low)/2;

		if (arr[mid] == x) {
			left_most_index = mid;
			high = mid - 1;
			continue;
		}
		if (arr[mid] < x) {
			low = mid + 1;
			continue;
		}
		if (arr[mid] > x) {
			high = mid - 1;
			continue;
		}
	}

	printf("%d\n", left_most_index);
}