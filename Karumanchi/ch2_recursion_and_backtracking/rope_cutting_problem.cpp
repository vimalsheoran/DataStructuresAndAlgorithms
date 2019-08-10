/*
* Given a rope of size n, and a set of integers {a, b, c}
* find out the maximum number of pieces this rope can be
* cut into.
*
* For example, if n = 5, {a = 5, b = 2, c = 1} maximum number
* of pieces this rope can be cut into is 5, (with c).
*/

#include <iostream>

using namespace std;

int cut_rope(int n, int a, int b, int c) {
	if (n == 0) return 0;
	if (n < 0) return -1;
	int res = max(
		max(
			cut_rope(n-a, a, b, c),
			cut_rope(n-b, a, b, c)
		),
		cut_rope(n-c, a, b, c)
	);
	if (res == -1) return -1;
	return res+1;
}

int main() {
	printf("%d\n", cut_rope(5,5,2,1));
}