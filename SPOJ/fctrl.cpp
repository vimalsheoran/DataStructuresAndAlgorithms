#include <iostream>

using namespace std;

int main() {
	int number;
	cin >> number;

	int zero_count = 0;
	int tester = 5;
	while (tester <= number) {
		zero_count += number/tester;
		tester *= 5;
	}
	cout << zero_count << endl;
}