#include <iostream>
#include <string>

using namespace std;

int main() {
	string text, pattern;	
	cin >> text >> pattern;
	int nLengthText = text.length();
	int nLengthPattern = pattern.length();

	int nCount = 0; bool bMatchFound = true;

	for (int i = 0; i < nLengthText; i++) {
		for (int j = 0; j < nLengthPattern; j++) {
			printf("%c %c\n", text[i+j], pattern[j]);
			if (text[i+j] != pattern[j]) {
				bMatchFound = false;
				break;
			}
			bMatchFound = true;
		}
		if(bMatchFound) nCount++;
	}
	printf("%d\n", nCount);
}