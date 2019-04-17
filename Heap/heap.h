#include <cstdlib>
#include <vector>

using namespace std;

class Heap{
public:
	vector <int> heap_ref;
	int heap_capacity;
	void pop();
	void push(int);
	void sort();
	void print_heap();
	int size();
private:
	int insertion_swap(vector <int> &, int);
	int deletion_swap(vector <int> &, int, int);
};

extern Heap heap;