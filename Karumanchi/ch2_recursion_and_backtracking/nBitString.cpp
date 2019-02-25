// Classic backtracking example
// Generating a binary string of length n

#include <iostream>

using namespace std;

void binaryString(char *arr, int n){
	if(n < 1){
		printf("%s\n", arr);
		return;
	}else{
		arr[n-1] = '0'; binaryString(arr, n-1);
		arr[n-1] = '1'; binaryString(arr, n-1);
	}
}

int main(){
	int n;
	printf("Enter the number strings: ");
	cin >> n;
	char arr[n];
	binaryString(arr, n);
}