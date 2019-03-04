#include "linkedList.h"

using namespace std;

LinkedList ll;

int main(){
	for(int i = 0; i < 10; i++){
		ll.push(i);
	}

	ll.print_list();
}