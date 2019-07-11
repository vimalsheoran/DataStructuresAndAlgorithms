#include <iostream>
#include <vector>
#include <queue>

// This graph is intended to be undirected

using namespace std;

struct Vertex {
	int value;
	vector <int> connected;
};

vector <Vertex*> graph;

/*
* Helper functions
*/

void search_for_base_target(int base, int target){
	if(base >= graph.size()){
		for(int i = graph.size() - 1; i <= base; i++){
			Vertex *temp = (Vertex *)malloc(sizeof(Vertex));
			temp->value = i;
			graph.push_back(temp);
		}
	}
	if(target >= graph.size()){
		for(int i = graph.size() - 1; i <= target; i++){
			Vertex *temp = (Vertex*)malloc(sizeof(Vertex));
			temp->value = i;
			graph.push_back(temp);
		}
	}
}

void debug_graph(){
	int size = graph.size();
	for(int i = 0; i < size; i++){
		int index_val = graph[i]->value;
		int connected_edges = graph[i]->connected.size();
		printf("%d\n", index_val);
		printf("Connected edges are: ");
		for(int j = 0; j < connected_edges; j++){
			printf("%d ", graph[i]->connected[j]);
		}
		printf("\n");
	}
}

void remove_connected_vertex(int base, int target){
	vector <int>::iterator it = graph[base]->connected.begin();
	for(; it != graph[base]->connected.end(); it++){
		if(target == *it){
			graph[base]->connected.erase(it);
			break;
		}
	}
}

/*
	Higher order Functions
*/

void generate_graph(){
	int no_of_nodes;
	cin >> no_of_nodes;
	for(int i = 0; i < no_of_nodes; i++){
		Vertex* temp = (Vertex*) malloc (sizeof(Vertex));
		temp->value = i;
		graph.push_back(temp);
	}
}

void add_edge(){
	int base, target;
	cin >> base >> target;
	search_for_base_target(base, target);
	graph[base]->connected.push_back(target);
	graph[target]->connected.push_back(base);
	printf("Successfully added an edge.\n");
}

void delete_edge(){
	int base, target;
	cin >> base >> target;
	if(base >= graph.size() || target >= graph.size() || !graph.size()){
		printf("Cannot delete base or target out of bounds.\n");
		return;
	}
	remove_connected_vertex(base, target);
	remove_connected_vertex(target, base);
	printf("Successfully removed an edge.\n");
}

bool check_for_edge(){
	int base, target;
	cin >> base >> target;
	if(base >= graph.size() || target >= graph.size()){
		printf("Either base or target or both don't exist in the graph.");
		return false;
	}
	bool found = false;
	vector<int>::iterator it = graph[base]->connected.begin();
	while(it != graph[base]->connected.end()){
		if(*it == target) found = true;
		it++;
	}
	return found;
}

void breadth_first_search(int start_vertex){
	if(!graph.size()) {
		printf("Graph is empty.\n"); return;
	}
	bool visited[graph.size()];
	for(int i = 0; i < graph.size(); i++) visited[i] = false;
	queue <int> traversal_queue;
	visited[start_vertex] = true; 
	traversal_queue.push(start_vertex);
	vector<int>::iterator it;
	while(!traversal_queue.empty()) {
		int curr_val = traversal_queue.front();
		traversal_queue.pop();
		it = graph[curr_val]->connected.begin();
		while(it != graph[curr_val]->connected.end()){
			if(!visited[*it]){
				visited[*it] = true;
				traversal_queue.push(*it); 
			}
			it++;
		}
		printf("%d ", curr_val);
	}
	printf("\n");
}

int main(){
	int choice;
	bool exists; 

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
			generate_graph();
			break;

			case 2:
			printf("Enter the base vertex and target vertex: ");
			add_edge();
			break;

			case 3:
			printf("Enter the base vertex and target vertex: ");
			delete_edge();
			break;

			case 4:
			printf("Enter the base vertex and target vertex: ");
			exists = check_for_edge();
			if(exists) printf("Edge found!\n"); else printf("No edge found :-(\n");
			break;

			case 5:
			debug_graph();
			break;

			case 6:
			printf("This is a test for checking out BFS algorithm implementation.\n");
			generate_graph();
			choice = 6;
			while (choice--) {
				add_edge();
			}
			breadth_first_search(2);
			break;

			default:
			printf("Invalid choice!");
			break;
		}
	}
}