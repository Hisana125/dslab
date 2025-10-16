#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX];
int front=-1,rear=-1;
void enqueue(int value){
	if(rear==MAX-1){
		printf("Queue Overflow!\n");
		return;
	}
	if(front==-1)front=0;
	rear++;
	queue[rear]=value;
	printf("Inserted %d\n",value);
}
void dequeue(){
	if(front==-1||front>rear){
		printf("Queue Underflow!\n");
		return;
	}
	printf("Deleted: %d\n",queue[front]);
	front++;
	if(front>rear){
		front=rear=-1;
	}
}
void display(){
	if(front==-1){
		printf("Queue is empty.\n");
		return;
	}
	printf("Queue elements:");
	for(int i=front;i<=rear;i++)
	{
		printf("%d",queue[i]);
	}
	printf("\n");
}
int main(){
	int choice,value;
	while(1){
		printf("\nQueue Menu:\n");
		printf("\n1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter value to insert:");
				scanf("%d",&value);
				enqueue(value);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid choice.Try again.\n");
		}
	}
	return 0;
}

