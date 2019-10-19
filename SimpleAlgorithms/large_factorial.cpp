#include <iostream>
#include <vector>

using namespace std;

void print_factorial(vector <int> factorial) {
	vector<int>::iterator it = factorial.end() - 1;
	while (it >= factorial.begin()) {
		cout << *it; it--;
	}
	cout << endl;
}

void calculate_factorial(int num) {
	vector <int> factorial;
	factorial.push_back(1);
	int i = 2;
	while (i <= num) {
		int carry = 0;
		vector<int>::iterator it = factorial.begin();
		while (it != factorial.end()) {
			cout << "DEBUG" << " " << i << endl;
			int product_eff = (*it)*i + carry;
			cout << "*it" << " " << *it << endl;
			cout << "product_eff" << " " << product_eff << endl;
			*it = product_eff%10;
			carry = product_eff/10;
			cout << "carry" << " " << carry << endl;
			it++;
		}
		if (carry != 0) factorial.push_back(carry);
		i++;
	}
	print_factorial(factorial);
}

int main() {

	int num;
	cin >> num;
	calculate_factorial(num);
}