
#include<stdio.h>

#define INFY 9999

int main(){
	int vertex,edges,i,j,k,a,b,count=1,min,totcost=0,u,v,q,w,t;
	printf("\nEnter the no.of vertices : ");
	scanf("%d",&vertex);
	int mat[vertex+1][vertex+1];
	for(i=1;i<=vertex;i++){
		for(j=1;j<=vertex;j++){
			mat[i][j]=INFY;
		}
	}
	printf("\nEnter the no.of edges : ");
	scanf("%d",&edges);
	printf("\nTake input : ");
	for(i=1;i<=edges;i++){
		scanf("%d%d%d",&q,&w,&t);
		mat[q][w]=t;
		mat[w][q]=t;
	}
	for(i=1;i<=vertex;i++){
 		for(j=1;j<=vertex;j++){
 			printf(" %d",mat[i][j]);
		 }
		 printf("\n");
	 }
	
	int visited[vertex+1];
	for(i=1;i<=vertex;i++){
		visited[i]=0;
	}
	printf("\nEnter the starting vertex : ");
	int start;
	scanf("%d",&start);
	visited[start]=1;
	
	while(count<vertex){
		for(i=1,min=INFY;i<=vertex;i++){
			for(j=1;j<=vertex;j++){
				if(mat[i][j]<min){
					if(visited[i]!=0){
						min = mat[i][j];
						a=u=i;
						b=v=j;
					}
					if(visited[u]==0 || visited[v]==0){
						printf("\nEdge %d : %d->%d = %d",count++,a,b,min);
						totcost+=min;
						visited[b]=1;
					}
				}
			}
			mat[a][b]=mat[b][a]=INFY;
		}
	}	
	
	printf("\nTotal cost is : %d",totcost);
	return 0;
	
}