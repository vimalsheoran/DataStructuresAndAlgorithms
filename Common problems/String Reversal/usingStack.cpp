#include <iostream>
#include <stack>
#include <string.h>

// Time Complexity of the solution O(n)
// Space Complexity of the solution O(n)

using namespace std;

void ReverseString(char *inputString, int inputStringLength){

	stack <char> stringBuffer;

	for(int i = 0; i < inputStringLength; i++){
		stringBuffer.push(inputString[i]);
	}

	for(int i = 0; i < inputStringLength; i++){
		inputString[i] = stringBuffer.top();
		stringBuffer.pop();
	}

	printf("%s\n", inputString);
}

int main()
{
	char inputString[100];
	cout << "Enter a string to reverse: ";
	cin >> inputString;

	ReverseString(inputString, strlen(inputString));	
}

