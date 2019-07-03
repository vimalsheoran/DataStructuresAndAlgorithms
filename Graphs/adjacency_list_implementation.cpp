#include <iostream>
#include <vector>

using namespace std;

struct Vertex {
	int value;
	vector <int> connected;
};

vector <Vertex> graph;

void generate_graph(int no_of_nodes);

int main(){
	int choice; 
	int no_of_nodes;

	while(true){
		printf("Welcome to graph.\n");
		printf("1. Create a new graph.\n");
		printf("2. Add an edge.\n");
		printf("3. Delete an edge.\n");
		printf("4. Check for edge.\n");

		printf("Enter your choice: ");
		cin >> choice;

		switch (choice){
			
			case 1:
			printf("Enter the total numbers of nodes: ");
			scanf("%d", &no_of_nodes);
			generate_graph(no_of_nodes);
			break;

			default:
			printf("Invalid choice!");
			break;
		}
	}
}

void generate_graph(int no_of_nodes){
	printf("Comes here");
	for(int i = 0; i < no_of_nodes; i++){
		printf("Comes here");
		graph[i].value = i;
	}
	return;
}