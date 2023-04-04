//Linear Search
#include<stdio.h>

int searchLinear(int a[], int n, int x){
	for(int i=0;i<n;i++){
		if(a[i] == x)
			return i;
	}
	return -1;
}

int main(){
	int n;
	printf("\n Enter size of the array:");
	scanf("%d",&n);
	int a[n];
	printf("\n Enter %d elements",n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int x;
	printf("\n Enter the searching element");
	scanf("%d",&x);
	int p = searchLinear(a,n,x);
	if(p!=-1)
		printf("\n Element found at %d position",p+1);
	else
		printf("\n Element not found");
	return 0;
}