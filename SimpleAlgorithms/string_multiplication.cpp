#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void print_vector(vector<int>vec) {
	vector<int>::iterator it = vec.end() - 1;
	while(it >= vec.begin()) {
		if (*it != 0) cout << *it;
		it--; 
	}
	cout << endl;
}

void multiply_strings(string num1, string num2) {
	vector <int> product(num1.size() + num2.size(), 0);
	int multiplication = 0, carry = 0;
	for (int i = num2.size() - 1; i >= 0; i--) {
		int b = num2[i] - '0';
		int offset = (num2.size() - 1) - i;
		for (int j = num1.size() - 1; j >= 0; j--) {
			int a = num1[j] - '0';
			multiplication = (a*b) + carry + product[offset];
			carry = multiplication/10;
			product[offset] = multiplication%10;
			multiplication = 0;
			offset++;
		}
	}
	print_vector(product);
}

int main() {
	string num1, num2;
	cin >> num1 >> num2;
	multiply_strings(num1, num2);
}