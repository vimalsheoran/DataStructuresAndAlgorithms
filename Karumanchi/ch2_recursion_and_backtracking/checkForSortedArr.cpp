// Using recursion to check for a sorted array

#include <iostream>

using namespace std;

bool checkArray(int *arr, int n){
	if(n == 1)
		return true;
	else{
		if(arr[n-1] > arr[n-2])
			return checkArray(arr, (n-1));
		else
			return false;
	}
}

int main(){
	bool flag;
	int arr[5] = {2, 1, 3, 4, 5};
	flag = checkArray(arr, 5);
	if(flag){
		printf("Array is sorted.\n");
	}else{
		printf("Array is unsorted.\n");
	}
}