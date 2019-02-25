// To generate a k-nary string of size n

#include <iostream>

using namespace std;

void kString(char *arr, int n, int k){

	if(n < 1){
		printf("%s\n", arr);
		return;
	}else{
		for(int i = 0; i < k; i++){
			arr[n-1] = i+'0';
			kString(arr, n-1, k);
		}
	}
}

int main(){
	int n, k;
	printf("Enter string size and no of digits: ");
	cin >> n >> k;

	char arr[n];

	kString(arr, n, k);
}