#include <iostream>
#include <algorithm>

using namespace std;

bool search_pair(int arr[], int low, int high, int sum) {
	int l = low, h = high;
	while (l < h) {
		if (arr[l] + arr[h] == sum) {
			cout << arr[l] << " " << arr[h] << " ";
			return true;
		}
		if (arr[l] + arr[h] > sum) {
			h--;
		}
		if (arr[l] + arr[h] < sum) {
			l++;
		}
	}
	return false;
}

void search_for_triplet_sorted(int arr[], int N, int sum) {
	for (int i = 0; i < N; i++) {
		bool pair_found = search_pair(arr, i+1, N-1, sum - arr[i]);
		if (pair_found) {
			cout << arr[i] << ", triplet found" << endl;
		}
	}
}

void search_for_triplet_unsorted(int arr[], int N, int sum) {
	sort(arr, arr+N);
	cout << endl;
	search_for_triplet_sorted(arr, N, sum);
}

int main() {

	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int sum; cin >> sum;
	int flag; cin >> flag;

	if (flag == 1) {
		search_for_triplet_sorted(arr, N, sum);
	} else {
		search_for_triplet_unsorted(arr, N, sum);
	}
}