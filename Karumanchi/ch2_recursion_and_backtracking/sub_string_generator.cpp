/**
* Genrerate all possible substrings from the given 
* string "ABC"
*/

#include <iostream>
#include <cstring>

using namespace std;

void generate_substring(string base, string input_string, int curr_index) {
	if (curr_index == 3) {
		cout << base << endl;
		return;
	}
	generate_substring(base, input_string, curr_index+1);
	generate_substring(base+input_string[curr_index], input_string, curr_index+1);
}

int main() {
	generate_substring("", "ABC", 0);
}