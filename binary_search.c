//Binary Search
#include<stdio.h>
int searchBinary(int a[], int n, int x){
	int l,h,mid;
	l=0;
	h=n-1;
	while(l<=h){
		mid = (l+h)/2;
		if(x == a[mid])
			return mid;
		else if(x>a[mid])
			l = mid + 1;
		else
			h = mid - 1;
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
	int p = searchBinary(a,n,x);
	if(p!=-1)
		printf("\n Element found at %d position",p+1);
	else
		printf("\n Element not found");
	return 0;
}