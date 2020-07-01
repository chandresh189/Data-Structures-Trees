/*
Dijkstra’s algorithm is used to find the length of an optimal path between two nodes in a 
graph.The term optimal can mean anything, shortest, cheapest, or fastest. If we start the 
algorithm with an initial node, then the distance of a node Y can be given as the distance 
from the initial node to that node.
1. Select the source node also called the initial node
2. Define an empty set N that will be used to hold nodes to which a shortest
   path has been found.
3. Label the initial node with 0, and insert it into N.
4. Repeat Steps 5 to 7 until the destination node is in N or there are no more
   labelled nodes in N.
5. Consider each node that is not in N and is connected by an edge from
   the newly inserted node.
6. (a) If the node that is not in N has no label then SET the label of the
   node = the label of the newly inserted node + the length of the edge.
   (b) Else if the node that is not in N was already labelled, then SET its new
   label = minimum (label of newly inserted vertex + length of edge, old
   label)
7. Pick a node not in N that has the smallest label assigned to it and add it
   to N.
   
Step 1: Set the label of D = 0 and N = {D}.
Step 2: Label of D = 0, B = 15, G = 23, and F = 5. Therefore, N = {D, F}.
Step 3: Label of D = 0, B = 15, G has been re-labelled 18 because minimum
		(5 + 13, 23) = 18, C has been re-labelled 14 (5 + 9). Therefore, N = {D,F, C}.
Step 4: Label of D = 0, B = 15, G = 18. Therefore, N = {D, F, C, B}.
Step 5: Label of D = 0, B = 15, G = 18 and A = 19 (15 + 4). Therefore, N ={D, F, C, B, G}.
Step 6: Label of D = 0 and A = 19. Therefore, N = {D, F, C, B, G, A}
Note that we have no labels for node E; this means that E is not reachable from D. Only the
nodes that are in N are reachable from B.
   
   
Step 1: Set the label of D = 0 and N = {D}.
Step 2: Label of D = 0, B = 15, G = 23, and F = 5. Therefore, N = {D, F}.
Step 3: Label of D = 0, B = 15, G has been re-labelled 18 because minimum
        (5 + 13, 23) = 18, C has been re-labelled 14 (5 + 9). Therefore, N = {D,F, C}.
Step 4: Label of D = 0, B = 15, G = 18. Therefore, N = {D, F, C, B}.
Step 5: Label of D = 0, B = 15, G = 18 and A = 19 (15 + 4). Therefore, N ={D, F, C, B, G}.
Step 6: Label of D = 0 and A = 19. Therefore, N = {D, F, C, B, G, A}
*/

#include<stdio.h>
#include<limits.h>
#define N 9
void Display(int dist[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d\t%d\n",i,dist[i]);
}
int MinDistance(int dist[],int sptset[])
{
	int min=INT_MAX,minindex;
	
	for(int i=0;i<N;i++)
	{
		if(sptset[i]==0 && dist[i]<=min)
		{
			min=dist[i];
			minindex=i;
		}
	}
	return minindex;
}
void Dijkstra(int graph[N][N],int src)
{
	int dist[N];
	int sptset[N];
	
	for(int i=0;i<N;i++)
	{
		dist[i]=INT_MAX;
		sptset[i]=0;	
	}
	
	dist[src]=0;
	
	for(int count=0;count<N-1;count++)
	{
		int u=MinDistance(dist,sptset);
		sptset[u]=1;
		for(int v=0;v<N;v++)
		{
			if(!sptset[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+ graph[u][v]<dist[v])
			{
				dist[v]=dist[u]+graph[u][v];
			}
		}
	}
	Display(dist,N);
}
int main()
{
	int graph[N][N]={{0,4,0,0,0,0,0,8,0},
					{4,0,8,0,0,0,0,11,0},
					{0,8,0,7,0,4,0,0,2},
					{0,0,7,0,9,14,0,0,0},
					{0,0,0,9,0,10,0,0,0},
					{0,0,4,14,10,0,2,0,0},
					{0,0,0,0,0,2,0,1,6},
					{8,11,0,0,0,0,1,0,7},
					{0,0,2,0,0,0,6,7,0}};
	Dijkstra(graph,2);
	
}
