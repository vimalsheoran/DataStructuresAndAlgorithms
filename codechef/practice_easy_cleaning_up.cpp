#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
	int test_cases;
	map <int, int> completed_index;
	cin >> test_cases;
	for(int i = 0; i < test_cases; i++){
		int total, completed, task_index;
		cin >> total >> completed;
		for(int j = 0; j < completed; j++){
			cin >> task_index;
			completed_index[task_index] = 1;
		}
		vector <int> task_chef;
		vector <int> task_asst;
		bool chef;
		chef = true;
		for(int k = 1; k <= total; k++){
			if(completed_index[k] != 1){
				if(chef){ 
					task_chef.push_back(k);
					chef = false;
				} else {
					task_asst.push_back(k);
					chef = true;
				}							
			}
		}
		completed_index.clear();
		vector <int>::iterator tc = task_chef.begin();
		vector <int>::iterator ta = task_asst.begin();
		for(; tc != task_chef.end(); tc++) printf("%d ", *tc);
		printf("\n");
		for(; ta != task_asst.end(); ta++) printf("%d ", *ta);
		printf("\n");
	}
}