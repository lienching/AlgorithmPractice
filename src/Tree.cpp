#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
public:
	Node(int data=0): data(data){
		child.clear();
	}
	void printData() const {
		cout << data << " ";
	}
	
	int data;
	vector<Node*> child;
};

void dfs(Node* node){
	node->printData();
	for(int i=0; i<node->child.size(); ++i)
		dfs(node->child[i]);
}

void bfs(Node* root){
	queue<Node*> queue;
	while(!queue.empty()) queue.pop();
	queue.push(root);

	while(!queue.empty()){
		Node* tmp = queue.front();
		queue.pop();
		tmp->printData();
		for(int i=0; i<tmp->child.size(); ++i)
			queue.push(tmp->child[i]);
	}
}

int main(){
	Node *root, *node2, *node3, *node4, *node5, *node6;

	//  build the tree
	root = new Node(1);
	node2 = new Node(2);
	node3 = new Node(3);
	node4 = new Node(4);
	node5 = new Node(5);
	node6 = new Node(6);
	
	root->child.push_back(node2);
	root->child.push_back(node3);
	node2->child.push_back(node4);
	node2->child.push_back(node5);
	node3->child.push_back(node6);
	
	// DFS
	cout << "DFS: ";
	dfs(root);
	cout << endl;

	// BFS
	cout << "BFS: ";
	bfs(root);
	cout << endl;
	
	return 0;
}

