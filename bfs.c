#include <stdio.h>
#define MAX 20
int queue[MAX],front=-1,rear=-1;
int visited[MAX]={0};
void enqueue(int vertex){
        if(rear==MAX-1)
                printf("Queue Overflow\n");
        else {
                if(front==-1)
                        front=0;
                rear++;
                queue[rear]=vertex;
        }
}
int dequeue(){
        int vertex;
        if(front==-1||front>rear)
                return -1;
        else{
                vertex=queue[front];
                front++;
                return vertex;
        }
}
void BFS(int adj[MAX][MAX],int n,int start){
        int i,vertex;
        enqueue(start);
        visited[start]=1;
        printf("Breadth First Search Traversal:");
        while((vertex=dequeue())!=-1){
                printf("%d",vertex);
                for(i=1;i<=n;i++){
                        if(adj[vertex][i]==1&&visited[i]==0){
                                enqueue(i);
                                visited[i]=1;
                        }
                }
        }
}
int main(){
        int n,adj[MAX][MAX],i,j,start;
        printf("Enter number of vertices:");
scanf("%d",&n);
        printf("Enter the adjacency matrix:\n");
        for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                        scanf("%d",&adj[i][j]);
                }
        }
        printf("Enter the starting vertex:");
        scanf("%d",&start);
        BFS(adj,n,start);
        return 0;
}
