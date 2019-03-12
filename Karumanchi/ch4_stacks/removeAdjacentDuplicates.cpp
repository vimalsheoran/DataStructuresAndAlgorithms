#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

stack <char> char_buff;

void check_duplicates(char base_val){
	if(char_buff.top() == base_val){
		char_buff.pop();
		return;
	}
	char new_top = char_buff.top();
	char_buff.pop();
	check_duplicates(new_top);
	char_buff.push(base_val);
}

void remove_adjacent(){
	if(char_buff.empty()){
		printf("Removed all elements");
		return;
	}
	char top = char_buff.top();
	char_buff.pop();
	printf("Comes here");
	check_duplicates(top);
	remove_adjacent();
}

void print_stack(){
	while(!char_buff.empty()){
		printf("%c ", char_buff.top());
		char_buff.pop();
	}
	printf("\n");
}

int main(){
	char input[] = {'m', 'i', 's', 's', 'i', 's', 's', 'i', 'p', 'p', 'i'};
	for(int i = 0; i < strlen(input); i++){
		printf("comes here");
		char_buff.push(input[i]);
	}
	remove_adjacent();
	print_stack();
}