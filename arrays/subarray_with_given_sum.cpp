#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int sum;
	cin >> sum;

	int curr_start_index = 0;
	int curr_sum = 0;

	for (int i = 0; i < N; i++) {
		curr_sum += arr[i];
		if (curr_sum == sum) {
			cout << curr_start_index << " " << i << endl;
			return 0;
		}
		if (curr_sum > sum) {
			while (curr_sum > sum) {
				curr_sum -= arr[curr_start_index];
				curr_start_index++;
			}
			if (curr_sum == sum) {
				cout << curr_start_index << " " << i << endl;
				return 0;
			}
		}
	}
}