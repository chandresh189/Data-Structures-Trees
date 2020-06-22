//Fast Searching, Insertion
//Without Recursion
#include <bits/stdc++.h>
using namespace std;

struct tree {
	struct tree *left, *right;
	int data;
	int thread;
}*root=NULL;

struct tree* InsertNode(struct tree *root, struct tree* ptr, struct tree* rt) {
	if(root == NULL) {
		root = ptr;
		if(rt != NULL) {
			root->right = rt;
			root->thread = 1;
		}
	}
	else if(ptr->data < root->data) {
		root->left = InsertNode(root->left, ptr, root);
	}
	else {
		if(root->thread == 1) {
			root->right = InsertNode(NULL, ptr, rt);
			root->thread = 0;
		}
		else {
			root->right = InsertNode(root->right, ptr, rt);
		}
	}
	return root;
}

void CreateThreadedTree() {
	struct tree *ptr;
	int n;
	cout<<"Enter element to be inserted else -1 to terminate\n";
	cin>>n;
	while(n!=-1) {
		ptr = (struct tree *)malloc(sizeof(struct tree));
		ptr->data = n;
		ptr->left = NULL;
		ptr->right = NULL;
		ptr->thread = 0;
		
		root = InsertNode(root, ptr, NULL);
		cout<<"Enter element to be inserted else -1 to terminate\n";
		cin>>n;
	}
}

void Inorder(){
	struct tree *ptr, *prev;
	ptr = root;
	do {
		while(ptr != NULL) {
			prev = ptr;
			ptr = ptr->left;
		}
		if(prev != NULL) {
			cout<<prev->data<<" ";
			ptr = prev->right;
			while(ptr != NULL && prev->thread == 1) {
				cout<<ptr->data<<" ";
				prev = ptr;
				ptr = ptr->right;
			}
		}
	}while(ptr != NULL);
}

int main()
{
	CreateThreadedTree();
	cout<<"Tree Created";
	Inorder();
	return 0;
}

