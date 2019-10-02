#include <iostream>

using namespace std;

int reverse_number(int number) {
	int reverse_number = 0;
	while (number > 0) {
		reverse_number = reverse_number*10 + number%10;
		number /= 10;
	}
	return reverse_number;
}

int main() {
	int test_cases;
	cin >> test_cases;
	while (test_cases--) {
		int num1, num2;
		cin >> num1 >> num2;
		int sum = reverse_number(num1) + reverse_number(num2);
		cout << reverse_number(sum) << endl;
	}
}