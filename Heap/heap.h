#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

struct Node{
	int data;
	Node* left_child;
	Node* right_child;
}

class Heap{
public:
	vector <int> heap_ref;
	int heap_capacity;
	int pop();
	void push(int);
	void sort();
	void print_heap(Node*);
	int size();
	vector <int> heapify()
private:
	int insertion_swap(vector <int> &, int);
	int deletion_swap(vector <int> &, int, int);
};

extern Heap heap;