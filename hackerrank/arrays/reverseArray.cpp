#include <iostream>

using namespace std;

int main(){
	int i, n;
	cin >> n;
	int arr[n];
	for(i = n-1; i >= 0; i--){
		cin >> arr[i];
	}
	for(i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}