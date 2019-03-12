#include <iostream>
#include <stack>

using namespace std;

stack <int> main_stack;

void push_back(int data_to_push){
	int top_val;
	if(main_stack.empty()){
		main_stack.push(data_to_push);
		return;
	}
	top_val = main_stack.top();
	main_stack.pop();
	push_back(data_to_push);
	main_stack.push(top_val);
}

void reverse_stack(){
	int top_val;
	if(main_stack.empty())
		return;
	top_val = main_stack.top();
	main_stack.pop();
	reverse_stack();
	push_back(top_val);
}

void print_stack(stack <int> disp_stack){
	while(!disp_stack.empty()){
		printf("%d ", disp_stack.top());
		disp_stack.pop();
	}
	printf("\n");
}

int main(){
	int input, size;
	printf("Enter the size of your stack: ");
	cin >> size;
	printf("Start adding %d values\n", size);
	while(size--){
		cin >> input;
		main_stack.push(input);	
	}
	printf("This is the original stack\n");
	print_stack(main_stack);
	printf("This is the reversed stack\n");
	reverse_stack();
	print_stack(main_stack);
}