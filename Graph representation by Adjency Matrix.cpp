#include<stdio.h>
#include<stdlib.h>
#define N 20
int main(){
	int mat[N][N]={0};
	int n,i,edges,s,d,j;
	char ch;
	printf("ENter number of vertex");
	scanf("%d",&n);
	fflush(stdin);
	printf("Enter your choice u for undirected and d for directed\n");
	scanf("%c",&ch);
	if(ch=='u')
	edges=n*(n-1)/2;
	else
	edges=n*(n-1);
	
	printf("Enter edges\n");
	for(i=0;i<edges;i++){
		printf("Enter source and destination or (0,0) for exit");
		scanf("%d%d",&s,&d);
		
		if(s==0 && d==0)
		break;
		
		mat[s][d]=1;
		if(ch=='u')
		mat[d][s]=1;
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",mat[i][j]);
			
		}
		printf("\n");
	}
	return 0;
}
