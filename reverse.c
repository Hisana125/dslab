#include<stdio.h>
int main(){
	int arr[5]={2,4,8,12,16};
	printf("Printing Array Elements:\n");
	for(int i=0;i<5;i++){
		printf("%d\t",arr[i]);
	}
	printf("Printing reversed elements:\n");
	for(int i=4;i>=0;i--){
		printf("%d\t",arr[i]);
	}
	return 0;
}
