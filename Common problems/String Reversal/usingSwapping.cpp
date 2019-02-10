#include <iostream>
#include <string.h>

using namespace std;

// Time Complexity = O(n)
// Space Complexity = O(1)

void ReverseString(char *inputString, int inputStringLength){
	
	int indexFirst = 0;
	int indexLast = inputStringLength-1;

	while(indexFirst != indexLast){
		char temp = inputString[indexFirst];
		inputString[indexFirst] = inputString[indexLast];
		inputString[indexLast] = temp;
		indexLast--; indexFirst++;
	}

	printf("%s\n", inputString);
}

int main(){
	char inputString[100];
	printf("Enter the string to reverse: ");
	cin >> inputString;

	ReverseString(inputString, strlen(inputString));
}