#include <iostream>
#include <vector>
#define vector_iterator std::vector<int>::iterator

using namespace std;

void print_factorial(vector<int>factorial) {
	vector_iterator it = factorial.end() - 1;
	while (it >= factorial.begin()) {
		cout << *it;
		it--;
	}
	cout << endl;
}

void calc_factorial(int number) {
	if (number == 1 || number == 0) {
		cout << 1 << endl;
		return;
	}
	vector<int>factorial;
	factorial.push_back(1);
	int j = 2;
	while (j <= number) {
		vector_iterator it = factorial.begin();
		int carry = 0;
		while (it != factorial.end()) {
			int arith = ((*it)*j)+carry;
			carry = arith/10;
			*it = arith%10;
			it++;
		}
		while (carry) {
			factorial.push_back(carry%10);
			carry /= 10;
		}
		j++;
	}
	print_factorial(factorial);
}

int main() {
	int number;
	cin >> number;
	calc_factorial(number);
}