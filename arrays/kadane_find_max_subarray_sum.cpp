#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;
	int a[N];
	for (int i = 0; i < N; i++) cin >> a[i];

	int curr_sum = a[0];
	int curr_max_sum = a[0];

	for (int i = 1; i < 2*N - 1; i++) {
		cout << curr_sum << endl;
		curr_sum = max(a[i%N], curr_sum+a[i%N]);
		curr_max_sum = max(curr_max_sum, curr_sum);
	}

	printf("%d\n", curr_max_sum);
}