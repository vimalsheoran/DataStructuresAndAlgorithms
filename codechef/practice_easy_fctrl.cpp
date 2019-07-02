#include <iostream>

using namespace std;

void count_zero(int n){
	int count = 0;
	for(int i = 5; n/i >= 1; i *= 5){
		count += n/i;
	}
	printf("%d\n", count);
}

int main(){
	int input_size, num;
	cin >> input_size;
	for(int i = 0; i < input_size; i++){
		cin >> num;
		count_zero(num);
	}
}
