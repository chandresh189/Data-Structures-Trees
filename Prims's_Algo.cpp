#include <iostream>
int main()
{
	int n, i, j, ne = 1, min, mincost = 0, a, u, b, v;
	int cost[10][10];
	int visited[10]={0};
	std::cout<<"Enter number of Node:\n";
	std::cin>>n;
	std::cout<<"Enter Adjacency Matrix:\n";
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			std::cout<<"Enter ("<<i<<","<<j<<") Node: ";
			std::cin>>cost[i][j];
			if(cost[i][j] == 0) {
				cost[i][j] = 999;
			}
		}
	}
	visited[1] = 1;
	
	while(ne < n) {
		for(i=1, min=999; i<=n; i++) {
			for(j=1; j<=n; j++) {
				if(cost[i][j]<min) {
					if(visited[i] != 0) {
						min = cost[i][j];
						a = u = i;
						b = v = j;
					}
				}
			}
		}
		if(visited[u] == 0 || visited[v] == 0) {
			std::cout<<"Edge "<<ne++<<": ("<<a<<", "<<b<<")  cost:"<<min<<"\n";
			mincost += min;
			visited[b] = 1;
		}
		cost[a][b] = cost[b][a] = 999;
	}
	std::cout<<"Minimum cost : "<<mincost<<"\n";
	return 0;
}


/*
Test Case
Enter number of Node: 3
Enter Adjacency Matrix:
Enter (1,1) Node: 0
Enter (1,2) Node: 2
Enter (1,3) Node: 3
Enter (2,1) Node: 2
Enter (2,2) Node: 0
Enter (2,3) Node: 4
Enter (3,1) Node: 3
Enter (3,2) Node: 4
Enter (3,3) Node: 0
Edge 1: (1, 2)  cost: 2
Edge 2: (1, 3)  cost: 3
Minimum cost : 5
*/
