// To find the maximum lexicographical substring of a given string

#include <iostream>
#include <string>

using namespace std;

string max_lexicographic(string a){
	string max_subs = "";
	for(int i = 0; i < a.length(); i++)
		max_subs = max(max_subs, a.substr(i));
	return max_subs;
}

int main(){
	string a = "My name is Gilfoyle";
	cout << max_lexicographic(a);
}