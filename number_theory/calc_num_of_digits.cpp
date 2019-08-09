#include <iostream>
#include <cmath>

using namespace std;

// Iterative Approach

void iterative_method(int n) {
	int count = 0;
	while (n != 0) {
		n /= 10;
		count++;
	}
	printf("USED ITERATIVE METHOD: %d\n", count);
}

// Recursive Approach

int recursive_method(int n) {
	if (n == 0) return 0;
	return 1 + recursive_method(n/10);
}

// Logarithmic Approach

int	 logarithmic_method(int n) {
	return floor(log10(n)+1);
}

int main() {
	int number, c;
	printf("Enter your number: ");
	cin >> number;

	iterative_method(number);
	c = recursive_method(number);
	printf("USED RECURSIVE METHOD: %d\n", c);
	c = logarithmic_method(number);
	printf("USED LOGARITHMIC METHOD: %d\n", c);
}