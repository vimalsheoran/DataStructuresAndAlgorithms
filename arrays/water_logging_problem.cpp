#include <iostream>
#include <vector>

using namespace std;

// void calculate_water_logged(int i, int j, int &total, vector<int>submerged) {
// 	int k = a[i] < a[j] ? i : j;
// 	vector<int>::iterator it = submerged.begin();
// 	for (; it != submerged.end(); it++) {
// 		total += a[k] - a[*it];
// 	}
// }

/** Efficient alternative */
void find_tapped_water_efficient(int arr[], int n) {

	int lmax[n], rmax[n];
	lmax[0] = arr[0];
	for (int i = 1; i < n; i++) {
		lmax[i] = max(arr[i], lmax[i-1]);
	}

	rmax[n-1] = arr[n-1];
	for (int i = n-2; i >= 0; i--) {
		rmax[i] = max(arr[i], rmax[i+1]);
	}

	int water_trapped = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < lmax[i] && arr[i] < rmax[i]) {
			water_trapped += (min(lmax[i], rmax[i]) - arr[i]);
		}
	}

	printf("%d\n", water_trapped);
}

int main() {
	
	vector<int>submerged;
	int total_water_logged = 0;

	int N; cin >> N;
	int arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];

	find_tapped_water_efficient(arr, N);

	// for (int i = 0; i < 7; i++) {
	// 	if (a[i] > a[i+1]) {
	// 		int j = i + 1;
	// 		while (a[j] < a[i] && a[j] < a[j+1] && j < 9) {
	// 			submerged.push_back(j);
	// 			j++;
	// 		}
	// 		calculate_water_logged(i, j, total_water_logged, submerged);
	// 		submerged.clear();
	// 		i = j-1;
	// 	}
	// }

	printf("%d\n", total_water_logged);
}