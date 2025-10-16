#include<stdio.h>
int main(){
	int arr[6]={20,10,40,3,56,2},max;
	printf("\n");
	max=arr[0];
	for(int i=1;i<5;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	printf("\nThe maximum element in the array is:%d\n",max);
	return 0;
}
