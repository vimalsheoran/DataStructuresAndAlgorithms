#include <iostream>
#include <vector>

using namespace std;

int graph[100][100];

void populate_graph(){
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			graph[i][j] = -1;
		}
	}
}

void add_edge(){
	int m, n, w;
	printf("Enter the vertices: ");
	cin >> m >> n;
	if (m > 99 || n > 99) {
		printf("Out of bounds, lower limit 0, upper limit 99.\n");
		return;
	}
	printf("Enter the weight of the edge: ");
	cin >> w;
	graph[m][n] = w;
	printf("Successfully added edge.\n");
	return;
}

void delete_edge(){
	int m, n;
	printf("Enter vertices: ");
	cin >> m >> n;
	if (m > 99 || n > 99) {
		printf("Out of bounds, lower limit 0, upper limit 99.\n");
		return;
	}
	graph[m][n] = -1;
	printf("Successfully deleted an edge.\n");
	return;
}

void detect_edge(){
	int m, n;
	printf("Enter vertices: ");
	cin >> m >> n;
	if (m > 99 || n > 99) {
		printf("Out of bounds, lower limit 0, upper limit 99.\n");
		return;
	}
	if (graph[m][n] == -1) {
		printf("No edge detected.\n");
	} else {
		printf("Edge found. Weight = %d\n", graph[m][n]);
	}
	return;
}

int main(){
	populate_graph();
	int choice;
	while(true){
		printf("1. Add edge.\n");
		printf("2. Delete edge.\n");
		printf("3. Check for an edge.\n");
		printf("Enter your choice: ");
		cin >> choice;

		switch(choice){

			case 1:
			add_edge();
			break;

			case 2:
			delete_edge();
			break;

			case 3:
			detect_edge();
			break;
		}
	}
}