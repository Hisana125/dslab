#include<stdio.h>
int main(){
	int arr[5],n,found=0;
	printf("enter elements:\n");
	for(int i=0;i<5;i++){
		scanf("%d",&arr[i]);
	}
	printf("\n Enter the element to search:");
	scanf("%d",&n);
	for(int i=0;i<5;i++){
		if(arr[i]==n){
			found=1;
			printf("Element %d found at %d",n,i++);
			break;
		}
	}
	if(!found){
		printf("Element not found");
	}
	return 0;
}
