#include<stdio.h>
int main(){
	int arr[5],sum=0;
	printf("Enter 5 elements:\n");
	for(int i=0;i<5;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<5;i++){
		sum+=arr[i];
	}
	printf("sum of all elements=%d\n",sum);
	return 0;
}
