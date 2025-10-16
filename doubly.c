#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
}Node;
Node* head=NULL;
Node* createNode(int data) {
	Node* newNode=
		(Node*)malloc(sizeof(Node));
	if(!newNode) {
		printf("Memory allocation failed.\n");
		exit(1);
	}
	newNode->data=data;
	newNode->prev=NULL;
	newNode->next=NULL;
	return newNode;
}
void insertAtBeginning(int data) {
	Node* newNode=createNode(data);
	if(head==NULL) {
		head=newNode;
	}else {
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
	}
	printf("Inserted %d at the beginning.\n",data);
}
void insertAtEnd(int data) {
	Node* newNode=createNode(data);
	if(head==NULL) {
		head=newNode;
	}else {
		Node* temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newNode;
		newNode->prev=temp;
	}
	printf("Inserted %d at the end.\n",data);
	return;
}
void deleteNode(int value) {
	Node* temp=head;
	while(temp!=NULL && temp->data!=value)
		temp=temp->next;
	if(temp==NULL) {
		printf("Value %d not found in the list.\n",value);
		return;
	}
	if(temp->prev==NULL) {
		head=temp->next;
		if(head!=NULL)
			head->prev=NULL;
	}else {
		temp->prev->next=temp->next;
	}
	if(temp->next!=NULL) {
		temp->next->prev=temp->prev;
		free(temp);
		printf("Deleted node with value %d.\n",value);
	}
}
void displayList() {
	if(head==NULL) {
		printf("List is empty.\n");
		return;
	}
	Node* temp=head;
	printf("Doubly Linked List:");
	while(temp!=NULL) {
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main() {
	int choice,value;
	while(1) {
		printf("\n---Menu---\n");
		printf("1.insert at Beginning\n");
		printf("2.Insert at End\n");
		printf("3.Delete a Node\n");
		printf("4.Display\n");
		printf("5.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice) {
case 1:
	printf("Enter value insert at beginning:");
	scanf("%d",&value);
	insertAtBeginning(value);
	break;
case 2:
	printf("Enter value to insert at end:");
	scanf("%d",&value);
	insertAtEnd(value);
	break;
case 3:
	printf("Enter value to delete:");
	scanf("%d",&value);
	deleteNode(value);
	break;
case 4:
	displayList();
	break;
case 5:
	printf("Exiting program.\n");
	exit(0);
default:
	printf("Invalid choice.Try again.\n");
		}
	}
	return 0;
}






	
