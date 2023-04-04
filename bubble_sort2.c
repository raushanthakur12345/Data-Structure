//Write a function to sort elements using Bubble Sort Algorithm
#include<stdio.h>
int inputArray(int a[], int n){
	printf("\n Enter %d elements",n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}

int outputArray(int a[], int n){
	printf("\n Array elements are:");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}

int sortModifiedBubble(int a[], int n){
	int swapped=0;
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j] > a[j+1]){
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				swapped = 1;
			}
			count++;
		}
		if(swapped == 0)
			break;
	}
	printf("\n Total number of iterations = %d",count);
}

int main(){
	int n;
	printf("\n Enter the size of the array:");
	scanf("%d",&n);
	int a[n];
	inputArray(a,n);
	printf("\n List of elements before sorting:");
	outputArray(a,n);
	
	sortModifiedBubble(a,n);
	
	printf("\n List of elements after sorting:");
	outputArray(a,n);
	return 0;
}