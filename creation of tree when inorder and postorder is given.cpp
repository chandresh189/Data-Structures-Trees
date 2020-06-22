#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
	Node *left, *right;
	int data;
}*root=nullptr;

Node *NewNode(int data) {
	Node *ptr = new Node;
	ptr->data = data;
	ptr->left = nullptr;
	ptr->right = nullptr;
	return ptr;
}

void InOrder(Node *root) {
	if(root == nullptr)
	return;
	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
}

Node* Construct(int start, int last, vector <int> postorder, int &pindex, unordered_map <int, int> &map) {
	if(start > last)
	return nullptr;
	
	Node* root = NewNode(postorder[pindex--]);
	int index = map[root->data];
	
	root->right = Construct(index+1, last, postorder, pindex, map);
	
	root->left = Construct(start, index-1, postorder, pindex, map);
	
	return root;
}

Node* ConstructBinaryTree(vector <int> inorder, vector <int> postorder) {
	int n = inorder.size();
	unordered_map <int, int> map;
	for(int i = 0; i<n; i++) {
		map[inorder[i]] = i;
	}
	
	int pindex = n-1;
	
	return Construct(0,n-1,postorder,pindex,map);
}

int main() {
	vector <int> inorder = {4,2,1,7,5,8,3,6};
	vector <int> postorder = {4,2,7,8,5,6,3,1};
	root = ConstructBinaryTree(inorder, postorder);
	InOrder(root);
	return 0;
}
