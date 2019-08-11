#include <iostream>

using namespace std;

int sum_of_digits(int n) {
	int count = 0;
	while (n >= 10) {
		count += n%10;
		n /= 10;
	}
	return count + n;
}

int digital_root(int input) {
	if (input < 10) return input;
	digital_root(sum_of_digits(input));
}

int main () {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << digital_root(n) << endl;
	}
	return 0;
}