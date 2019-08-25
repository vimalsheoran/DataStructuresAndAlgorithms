#include <iostream>

using namespace std;

int main () {

	int a;
	cin >> a;

	if (a == 0 || a == 1) {
		cout << a << endl;
		return 0;
	}

	int low = 0, high = a;

	while (low < high) {
		int mid = low + (high - low)/2;
		if (mid == (a/mid)) {
			cout << mid << endl;
			return 0;
		}
		if (mid > (a/mid)) low = mid+1;
		if (mid < (a/mid)) high = mid-1;
	}
}
