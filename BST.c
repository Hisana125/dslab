#include <stdio.h>
#include <stdlib.h>
struct Node{
        int data;
        struct Node *left, *right;
};
struct Node* createNode(int value){
        struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=value;
        newNode->left=newNode->right=NULL;
        return newNode;
}
struct Node* insert(struct Node* root,int value){
        if(root==NULL)
                return createNode(value);
        if(value<root->data)
                root->left=insert(root->left,value);
        else if(value>root->data)
                root->right=insert(root->right,value);
        return root;
}
struct Node* search(struct Node* root,int key){
        if(root==NULL||root->data==key)
        return root;
        if(key<root->data)
                return search(root->left,key);
        else
                return search(root->right,key);
}
void inorder(struct Node* root){
        if(root!=NULL){
                inorder(root->left);
                printf("%d",root->data);
                inorder(root->right);
        }
}
void preorder(struct Node* root){
        if(root!=NULL){
                printf("%d",root->data);
                preorder(root->left);
                preorder(root->right);
        }
}
void postorder(struct Node* root){
        if(root!=NULL){
                postorder(root->left);
                postorder(root->right);
                printf("%d",root->data);
        }
}
struct Node*findMin(struct Node* root){
        while(root->left!=NULL)
                root=root->left;
        return root;
}
struct Node* deleteNode(struct Node* root,int key){
        if(root==NULL)
                return root;
        if(key<root->data)
                root->left=deleteNode(root->left,key);
        else if(key>root->data)
                root->right=deleteNode(root->right,key);
        else{
                if(root->left==NULL){
                        struct Node* temp=root->right;
                        free(root);
                        return temp;
                }
                struct Node* temp=findMin(root->right);
                root->data=temp->data;
                root->right=deleteNode(root->right,temp->data);
        }
        return root;
}
int main(){
        struct Node* root=NULL;
        int choice,value;
        while(1){
                printf("\n===Binary Search Tree Operations===\n");
                printf("1.Insert a node\n");
                printf("2.Search for a node\n");
                printf("3.Inorder traversal\n");
                printf("4.Preorder traversal\n");
                printf("5.Postorder traversal\n");
                printf("6.Delete a node\n");
                printf("7.Exit\n");
                printf("Enter your choice:");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
                                printf("ENter value to insert:");
                                scanf("%d",&value);
                                root=insert(root,value);
                                printf("Node inserted.\n");
                                break;
                        case 2:
                                printf("Enter value to search:");
                                scanf("%d",&value);
                                if(search(root,value))
                                        printf("Node found in the tree.\n");
                                else
                                        printf("Node not found.\n");
                                break;
                        case 3:
                                printf("Inorder traversal:");
                                inorder(root);
                                printf("\n");
                                break;
                        case 4:
                                printf("Preorder traversal:");
                                preorder(root);
                                printf("\n");
                                break;
                        case 5:
                                printf("Postorder traversal:");
                                postorder(root);
                                printf("\n");
                                break;
                        case 6:
                                printf("Enter value to delete:");
                                scanf("%d",&value);
                                root=deleteNode(root,value);
                                printf("Node deleted(if found).\n");
                                break;
                        case 7:
                                printf("Exiting program.\n");
                                exit(0);
                        default:
                                printf("Invalid choice! Please try again.\n");
                }
        }
        return 0;
}

