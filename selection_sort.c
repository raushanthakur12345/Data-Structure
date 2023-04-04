//Write a function to sort elements using Selection Sort Algorithm
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

int sortSelection(int a[], int n){
	int count=0, pivot,l;
	for(int i=0;i<n;i++){
		pivot = a[i];
		l=i;
		for(int j=i+1;j<n;j++){
			if(a[j] < pivot){
				pivot = a[j];
				l = j;
			}
			count++;
		}
		if(i !=l ){
			int t = a[i];
			a[i] = a[l];
			a[l] = t;
		}
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
	
	sortSelection(a,n);
	
	printf("\n List of elements after sorting:");
	outputArray(a,n);
	return 0;
}