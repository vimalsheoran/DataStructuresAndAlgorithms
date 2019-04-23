#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

class Heap{
public:
	vector <int> heap_ref;
	int heap_capacity;
	int pop();
	void push(int);
	void sort();
	void print_heap();
	int size();
	vector <int> heapify(Node*);
	int find_max_in_min_heap(); // Also min in max heap
private:
	int insertion_swap(vector <int> &, int);
	int deletion_swap(vector <int> &, int, int);
};

extern Heap heap;