#include <iostream>
#include <stack>
#include <cstring>
#define stack_char std::stack<char>

using namespace std;

stack_char parser_stack;

bool is_operator(char symbol) {
	if (   symbol == '+' 
		|| symbol == '-' 
		|| symbol == '*' 
		|| symbol == '/' 
		|| symbol == '^' 
		|| symbol == '(' 
		|| symbol == ')'
	) return true;
	return false;
}

int get_precendence(char symbol) {
	if (symbol == '(' || symbol == ')')
		return 0;
	if (symbol == '+' || symbol == '-')
		return 1;
	if (symbol == '*' || symbol == '/')
		return 2;
	if (symbol == '^')
		return 3; 
}

void empty_on_close() {
	while (parser_stack.top() != '(' && !parser_stack.empty()) {
		cout << parser_stack.top();
		parser_stack.pop();
	}
	parser_stack.pop();
}

void handle_operator(char symbol) {
	if (parser_stack.empty() || symbol == '(') {
		parser_stack.push(symbol); return;
	}
	if (symbol == ')') {
		empty_on_close();
	} else {
		int symbol_precedence = get_precendence(symbol);
		if (symbol_precedence > get_precendence(parser_stack.top())) {
			parser_stack.push(symbol);
		} else {
			int symbol_precedence = get_precendence(symbol);
			while (symbol_precedence <= get_precendence(parser_stack.top()) && !parser_stack.empty()) {
				cout << parser_stack.top();
				parser_stack.pop();
			}
			parser_stack.push(symbol);
		}
	}
}

void convert_expression(char *expression) {
	int exp_length = strlen(expression);
	for (int i = 0; i < exp_length; i++) {
		if (!is_operator(expression[i])) {
			cout << expression[i];
		} else {
			handle_operator(expression[i]);
		}
	}
	while (!parser_stack.empty()) {
		char next_symbol = parser_stack.top();
		if (next_symbol != '(' || next_symbol != ')') {
			cout << next_symbol;
		}
		parser_stack.pop();
	}
	cout << endl;
}

int main() {
	char expression[400];
	cin >> expression;
	convert_expression(expression);
}

