// An algorithm to find the maximum sum amongst all levels.

#include <queue>

struct Node{
	int data;
	Node *left;
	Node *right;
}

int max_level_sum(Node *root){
	if(root == NULL)
		return 0;

	int result = 0;

	queue <Node*> node_buff;
	node_buff.push(root);

	while(!node_buff.empty()){
		int count = node_buff.size();
		int sum = 0;
		
		while(count--){
			Node *current = node_buff.front();
			sum += current->data;

			if(current->left != NULL)
				node_buff.push(current->left);
			if(current->right != NULL)
				node_buff.push(current->right);

			node_buff.pop();
		}

		result = max(result, sum);
	}
}