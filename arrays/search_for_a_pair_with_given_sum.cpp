#include <iostream>
#include <map>

using namespace std;

void search_for_pair_sorted(int arr[], int N, int sum) {
	int i = 0, j = N-1;
	while(i < j) {
		if (arr[i] + arr[j] == sum) {
			cout << "Pair found: " << arr[i] << " " << arr[j] << endl;
			break;
		}
		if (arr[i] + arr[j] > sum) {
			j--;
		}
		if (arr[i] + arr[j] < sum ) {
			i++;
		}
	}
}

void search_for_pair_unsorted(int arr[], int N, int sum) {
	map <int, int> search_buff;
	for (int i = 0; i < N; i++) {
		search_buff[arr[i]] = 1;
	}
	for (int i = 0; i < N; i++) {
		if (search_buff[sum - arr[i]] == 1) {
			cout << "Pair found: " << arr[i] << " " << sum-arr[i] << endl;
			break;
		}
	}
}

int main() {

	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) cin >> arr[i];

	int sum; cin >> sum;
	int sorted; cin >> sorted;

	if (sorted == 1) {
		search_for_pair_sorted(arr, N, sum);
	} else {
		search_for_pair_unsorted(arr, N, sum);
	}
}