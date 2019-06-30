#include <iostream>

using namespace std;

unsigned long factorial(int number){
	if(number == 0) return 1;
	return number*factorial(number-1);
}

int count_trailing_zeroes(long number){
	int count = 0;
	for(int i = 5; number/i >= 1; i *= 5)
		count += number/i;
	return count;
}

int main(){
	int input_length, input;
	cin >> input_length;
	while(input_length--){
		cin >> input;
		unsigned long fact = factorial(input);
		printf("%li\n", fact);
		int trailing_zeroes = count_trailing_zeroes(fact);
		printf("%d\n", trailing_zeroes);
	}
	// printf("Let's test exponent function\n");
	// cin >> a >> b;
	// long prod = exponent(a, b);
	// printf("%li\n", prod);
	// return 0;
}