#include <iostream>
#include <stack>

using namespace std;

stack <int> main_stack;

void reverse_stack(){
	int stack_size = main_stack.size();
	int element_buff[stack_size-1];
	int i = 0;
	while(!main_stack.empty()){
		element_buff[i] = main_stack.top();
		main_stack.pop();
		i++;
	}
	while(i >= 0){
		main_stack.push(
			element_buff[i]
		);
		i--;
	}
	return;
}

void print_stack(){
	while(!main_stack.empty()){
		printf("%d\n", main_stack.top());
		main_stack.pop();
	}
	return;
}

int main(){
	int size, val;
	printf("Enter stack size: ");
	cin >> size;

	while(size--){
		cin >> val;
		main_stack.push(val);
	}

	reverse_stack();
	printf("Reversed stack,\n");
	print_stack();
}