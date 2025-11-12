#include <stdio.h>
#define SIZE 100
int parent[SIZE];
void makeSet(int n){
        for(int i=0;i<n;i++)
                parent[i]=i;
}
int find(int x){
        if(parent[x]!=x)
                parent[x]=find(parent[x]);
        return parent[x];
}
void unionSet(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px!=py)
                parent[py]=px;
}
int main(){
        int x,n,y,choice;
        printf("Enter number of elements:");
        scanf("%d",&n);
        makeSet(n);
        do{
                printf("\n1.Union\n2.Find\n3.Display Parents.\n4.Exit\nEnter your choice:");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
                                printf("Enter two elements to union:");
                                scanf("%d%d",&x,&y);
                                unionSet(x,y);
                                break;
                        case 2:
                                printf("Enter element to find its parent:");
                                scanf("%d",&x);
                                printf("Parent of %d is %d\n",x,find(x));
                                break;
                        case 3:
                                printf("Parent array:");
                                for(int i=0;i<n;i++)
                                        printf("%d",parent[i]);
                                printf("\n");
                                break;
                }
        }while(choice!=4);
        return 0;
}
