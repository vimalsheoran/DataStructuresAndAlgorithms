// Check if a string is palindrome or not

#include <iostream>
#include <cstdlib>
#include <stack>
#include <string.h>

using namespace std;

char palindrome[100];
stack <char> char_buff;

void check_for_palindrome(char *str){
	int length = strlen(str);
	int i = 0;
	int j = length - 1;

	if(length%2 == 0){
		while(i <= (length/2 - 1)){
			if(str[i] != str[j]){
				printf("Not a palindrome\n");
				return;
			}
			i++; j--;
		}
	}else{
		while(i != j){
			if(str[i] != str[j]){
				printf("Not a palindrome\n");
				return;
			}
			i++; j--;	
		}
	}

	printf("String is palindrome\n");
	return;
}

void check_with_stack(char *str){
	int length = strlen(str);
	int fill_index, compare_index;
	
	if(length%2 == 0){
		fill_index = (length/2 - 1);
		compare_index = fill_index + 1;
	}else{
		fill_index = ((length-1)/2 - 1);
		compare_index = fill_index + 2;
	}

	for(int i = 0; i <= fill_index; i++){
		char_buff.push(str[i]);
	}
	
	for(int i = compare_index; i < length; i++){
		if(str[i] != char_buff.top()){
			printf("Not a palindrome\n");
			return;
		}
		char_buff.pop();
	}

	printf("String is palindrome\n");
	return;
}

int main(){
	printf("Enter a string: ");
	scanf("%s", palindrome);

	check_for_palindrome(palindrome);
	check_with_stack(palindrome);
}