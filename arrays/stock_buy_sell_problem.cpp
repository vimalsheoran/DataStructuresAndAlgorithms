#include <iostream>

using namespace std;

int a[7] = {1, 5, 3, 8, 12, 11, 17};

int main () {
	int N;
	cin >> N;
	int a[N]; for (int i = 0; i < N; i++) cin >> a[i];

	int min_index = -1;
	bool min_found = false;
	if (a[0] < a[1]) {
		min_index = 0;
		min_found = true;
	}

	for (int i = 1; i < N; i++) {
		if (i == N-1) {
			if (min_found == true) {
				cout << "(" << min_index << " " << N-1 << ")" << " ";
			}
		} else {
			if (min_found == true) {
				if (a[i] > a[i+1] && a[i] > a[i-1]) {
					cout << "(" << min_index << " " << i << ")" << " ";
					min_found = false;
				}
			} else {
				if (a[i] < a[i+1] && a[i] <= a[i-1]) {
					min_index = i;
					min_found = true;
				}
			}
		}
	}
}