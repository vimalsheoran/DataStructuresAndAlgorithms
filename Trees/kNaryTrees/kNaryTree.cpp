#include "kNaryTree.h"
#include "queue"

void KNaryTree::add_node(int data, int parent, Node *root){
	queue <Node *> node_data;
	node_data.push(root);
	Node *curr_node;
	while(!node_data.empty()){
		curr_node = node_data.front();
		if(curr_node->data == parent){
			Node *new_node = new Node();
			new_node->data = data;
			curr_node->children.push_back(new_node);
			return;
		}
		for(int i = 0; i < curr_node->children.size(); i++){
			node_data.push(curr_node->children.at(i));
		}
		node_data.pop();
	}
	Node *new_node = new Node();
	new_node->data = data;
	curr_node->children.push_back(new_node);
	return;
}

void KNaryTree::print_tree(Node *root){
	if(root == NULL)
		return;
	queue <Node *> node_data;
	node_data.push(root);
	while(!node_data.empty()){
		Node *curr_node = node_data.front();
		printf("%d ", curr_node->data);
		for(int i = 0; i < curr_node->children.size(); i++){
			node_data.push(curr_node->children.at(i));
		}
		node_data.pop();
	}
	return;
}

void KNaryTree::init_tree(int data){
	root = new Node();
	root->data = data;
	return;
}