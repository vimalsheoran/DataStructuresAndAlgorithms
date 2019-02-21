#include <iostream>
#include <vector>

using namespace std;

void solve(int *arr, int noOfElements, int noOfRotations){
	int firstElement;

	if(noOfRotations > noOfElements)
		noOfRotations %= noOfElements;

	for(int i = 0; i < noOfRotations; i++){
		firstElement = arr[0];
		for(int j = 0; j < noOfElements - 1; j++){
			arr[j] = arr[j+1];
		}
		arr[noOfElements - 1] = firstElement;
	}
	for(int k = 0; k < noOfElements; k++)
		printf("%d ", arr[k]);
	printf("\n");

}

int main(){

	int noOfElements, noOfRotations;
	cin >> noOfElements >> noOfRotations;
	int arr[noOfElements];

	for(int i = 0; i < noOfElements; i++)
		cin >> arr[i];

	solve(arr, noOfElements, noOfRotations);
}