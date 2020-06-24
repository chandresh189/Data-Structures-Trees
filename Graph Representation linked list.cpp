#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
		char data;
		Node *next;
};
int main()
{
	int n,ne;
	Node **start, *current, *nn;
	cout<<"Enter number of vertex";
	cin>>n;
	start = new(Node *);
//	start = (Node **)malloc(n*sizeof(Node *));
	for(int i=0;i<n;i++)
	start[i] = NULL;
	
	for(int i=0;i<n;i++) {
		printf("Enter Number of Neighbour of %c node\n",65+i);
		cin>>ne;
		
		while(ne--) {
			fflush(stdin);
			nn = new(Node);
			cout<<"Enter data part ";
			cin>>nn->data;
			fflush(stdin);
			nn->next = nullptr;
			
			if(start[i] == nullptr) {
				start[i] = nn;
				current = nn;
			}
			else {
				current->next = nn;
				current = nn;
			}
		}
	}
	for(int i=0;i<n;i++) {
		printf("%c-----> ",65+i);
		current = start[i];
		while(current != nullptr) {
			cout<<current->data<<" ";
			current = current->next;
		}
		cout<<"\n";
	}
	return 0;
}
