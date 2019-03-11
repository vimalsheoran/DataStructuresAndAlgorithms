// To check whether a given sequence of operations is valid for a stack
// Assuming that the stack is initially empty

#include <iostream>
#include <string.h>

using namespace std;

void check_sequence(char *sequence){
	int length = strlen(sequence);
	if(sequence[0] == 'x'){
		printf("Invalid, Underflow error\n");
		return;
	}
	int s_count = 0, x_count = 0;
	for(int i = 0; i < length; i++){
		if(sequence[i] == 's'){
			s_count++;
		}else{
			x_count++;
		}
	}

	if(s_count < x_count){
		printf("Invalid, Underflow error\n");
		return;
	}

	printf("Valid operation\n");
	return;
}

int main(){
	char sequence[100];
	cin >> sequence;
	check_sequence(sequence);
}