#include <iostream>
#include <set>
#include <map>

using namespace std;

map <int, bool> duplicate_lookup;
set <int> query_set;

void find_no_of_ones(int s, int &e, int &o){
	try {
		duplicate_lookup.at(s); return;
	} catch (out_of_range& err) {
		int count = 0;
		int temp = s;
		while (s != 0) {
			s &= (s-1);
			count++;
		}
		printf("total no of ones in %d: %d\n", temp, count);
		if (count) {
			if (count%2 == 0) e++; else o++;
		}
		printf("%d %d\n", e, o);
	}
}

void manage_set(int s, int &e, int &o){
	find_no_of_ones(s, e, o);
	set<int>::iterator it = query_set.begin();
	for (; it != query_set.end(); it++) {
		int xor_value = s ^ *it;
		find_no_of_ones(xor_value, e, o);
		duplicate_lookup[xor_value] = true;
		query_set.insert(xor_value);
	}
	query_set.insert(s);
}

int main(){
	int t, q;
	scanf("%d", &t);
	int a = 0, b = 0;
	// for(int i = 1; i <= 128; i++){
	// 	find_no_of_ones(i, a, b);
	// 	printf("%d %d\n", a, b);
	// }
	for (int i = 0 ; i < t; i++) {
		scanf("%d", &q);
		int e = 0, o = 0, s;
		for (int j = 1; j <= 128; j++) {
			// scanf("%d", &s);
			try {
				duplicate_lookup.at(j);
			} catch (out_of_range& err) {
				manage_set(j, e, o);
				duplicate_lookup[j] = true;
			}
		}
	}
}

// Another way to look at things
// This was slow, so f it
// #include <iostream>
// #include <set>

// using namespace std;

// set <int> query_set;

// void find_no_of_ones(int s, int &e, int &o){
// 	int count = 0;
// 	while (s != 0) {
// 		s &= (s-1);
// 		count++;
// 	}
// 	if (count) {
// 		if (count%2 == 0) e++; else o++;
// 	}
// }

// void manage_set(int s){
// 	set<int>::iterator it = query_set.begin();
// 	for (; it != query_set.end(); it++) {
// 		int xor_value = s ^ *it;
// 		query_set.insert(xor_value);
// 	}
// 	query_set.insert(s);
// 	it = query_set.begin();
// 	int e = 0, o = 0;
// 	for (; it != query_set.end(); it++) {
// 		find_no_of_ones(*it, e, o);
// 	}
// 	printf("%d %d\n", e, o);
// }

// int main(){
// 	int t, q;
// 	scanf("%d", &t);
// 	for (int i = 0 ; i < t; i++) {
// 		scanf("%d", &q);
// 		int s;
// 		for (int j = 0; j < q; j++) {
// 			scanf("%d", &s);
// 			manage_set(s);
// 		}
// 	}
// }

// The wrong answer approach
// What's wrong is wrong
// #include <iostream>
// #include <set>
// #include <map>

// using namespace std;

// map <int, bool> duplicate_lookup;
// set <int> query_set;

// void find_no_of_ones(int s, int &e, int &o){
// 	int count = 0;
// 	while (s != 0) {
// 		s &= (s-1);
// 		count++;
// 	}
// 	if (count) {
// 		if (count%2 == 0) e++; else o++;
// 	}
// }

// void manage_set(int s, int &e, int &o){
// 	find_no_of_ones(s, e, o);
// 	set<int>::iterator it = query_set.begin();
// 	for (; it != query_set.end(); it++) {
// 		int xor_value = s ^ *it;
// 		try {
// 			duplicate_lookup.at(xor_value);
// 		} catch (out_of_range& err) {
// 			find_no_of_ones(xor_value, e, o);
// 			duplicate_lookup[xor_value] = true;
// 			query_set.insert(xor_value);
// 		}
// 	}
// 	query_set.insert(s);
// }

// int main(){
// 	int t, q;
// 	scanf("%d", &t);
// 	for (int i = 0 ; i < t; i++) {
// 		scanf("%d", &q);
// 		int e = 0, o = 0, s;
// 		for (int j = 0; j < q; j++) {
// 			scanf("%d", &s);
// 			try {
// 				duplicate_lookup.at(s);
// 				find_no_of_ones(s, e, o);
// 			} catch (out_of_range& err) {
// 				manage_set(s, e, o);
// 				duplicate_lookup[s] = true;
// 			}
// 			printf("%d %d\n", e, o);
// 		}
// 	}
// }