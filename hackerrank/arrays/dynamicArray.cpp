/*
Solution to the following problem,
https://www.hackerrank.com/challenges/dynamic-array/problem
*/

#include <iostream>
#include <vector>

using namespace std;

void solve(int n, int noOfOps){

	vector <vector <int>> seqList(n);
	int query, a1, a2, lastAnswer=0, size, index;

	for(int i = 0; i < noOfOps; i++){
		cin >> query >> a1 >> a2;
		switch(query){

			case 1:		
			a1 = (a1^lastAnswer)%n;
			seqList[a1].push_back(a2);
			break;
			
			case 2:
			a1 = (a1^lastAnswer)%n;
			size = seqList[a1].size();
			index = a2%size;
			lastAnswer = seqList[a1][index];
			printf("%d\n", lastAnswer);
			break;
		}

	}
}

int main(){
	int n, noOfOps;
	cin >> n >> noOfOps;

	solve(n, noOfOps);
}