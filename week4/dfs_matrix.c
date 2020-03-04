#include<stdio.h>
#include<stdlib.h>

int G[50][50], visited[50], n, count=0;

void DFS(int i) {
	int j;
	printf("\n%d", i);
	visited[i] = 1;
	
	for(j=0; j<n; j++) {
		count++;
		if(!visited[j] && G[i][j]==1)
			DFS(j);
	}
}

int main() {
	int i, j;
	FILE *fp;
	fp = fopen("dfs_mat.txt", "a");
	
	printf("Enter number of vertices: ");
	scanf("%d", &n);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(i==j) G[i][j]=0;
			else G[i][j]=1;
			//scanf("%d", &G[i][j]);
	for(i=0; i<n; i++) visited[i]=0;
	DFS(0);
	printf("\n");
	fprintf(fp, "%d %d\n", n, count);
	fclose(fp);
	return 0;
}
