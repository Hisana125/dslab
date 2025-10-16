#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push(int value){
	if(top==MAX-1){
		printf("Stack overflow! Cannot push %d\n",value);
	}else{
	top++;
	stack[top]=value;
	printf("%d pushed onto the stack.\n",value);
}
}
int pop(){
	if(top==-1){
		printf("Stack underflow! Cannot pop.\n");
	}else{
		printf("%d popped from stack\n",stack[top]);
	top--;
}
}
void display(){
       if(top==-1){
       printf("Stack is empty.\n");
       }else{
	printf("Stack elements: ");
 for(int i=top;i>=0;i--){
 printf("%d",stack[i]);
 }
printf("\n");
       }
}
int main(){
	int choice,value;
	while(1)
	{printf("\n--Stack Menu --\n");
	printf("1.push\n");
	printf("2.pop\n");
	printf("3.display\n");
	printf("4.exit\n");
	printf("Enter your choice:");
	scanf("%d",&choice);

	switch(choice){
		case 1:
			printf("Enter value to push:");
			scanf("%d",&value);
			push(value);break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			printf("Exiting program\n");
			exit(0);
		default:
		printf("Invalid choice.Please try again.\n");
		}
	}
		return 0;
	}
