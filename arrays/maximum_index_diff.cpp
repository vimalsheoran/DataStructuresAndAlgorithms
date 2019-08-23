#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) cin >> arr[i];

	int LMin[N], RMax[N];
	
	LMin[0] = arr[0];
	for (int i = 1; i < N; i++) {
		LMin[i] = min(arr[i], LMin[i-1]);
	}

	RMax[N-1] = arr[N-1];
	for (int i = N-2; i >= 0; i--) {
		RMax[i] = max(arr[i], RMax[i+1]);
	}

	int i = 0, j = 0, max_diff = -1;
	while (i < N && j < N) {
		if (LMin[i] < RMax[j]) {
			max_diff = max(max_diff, j-i);
			j++;
		} else {
			i++;
		}
	}

	cout << max_diff << endl;
}