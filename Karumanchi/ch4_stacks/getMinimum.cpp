#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

stack <int> main_stack;
stack <int> aux_stack;

void generate_stack(int push_val){
	if (main_stack.empty() &&
		aux_stack.empty()){
		main_stack.push(push_val);
		aux_stack.push(push_val);
	}else{
		main_stack.push(push_val);
		if(push_val <= aux_stack.top())
			aux_stack.push(push_val);
	}
	return;
}

void pop_stack(){
	if( main_stack.top() == 
		aux_stack.top())
		aux_stack.pop();
	main_stack.pop();
	return;
}

void get_minimum(){
	printf("Minimum: %d\n", aux_stack.top());
}

int main(){
	
	int stack_size;
	printf("Enter a stack size: ");
	cin >> stack_size;

	for(int i = 0; i < stack_size; i++){
		int push_val = (rand()%20) + 1;
		generate_stack(push_val);
	}

	get_minimum();
}