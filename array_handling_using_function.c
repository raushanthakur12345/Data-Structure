#include<stdio.h>
int inputarray(int a[], int n)
{
   printf("\nEnter %d element ", n);
   for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
   }
}
int outputarray(int a[], int n){
    printf("\nArray element are : ");
    for(int i=0; i<n; i++){
        printf("%d",a[i]);
    }
}
int searchlinear(int a[], int n, int x){
    for(int i=0; i<n; i++){
        if(a[i] == x){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    printf("\nEnter the size of the array : ");
    scanf("%d", &n);
    int a[n];
    inputarray(a,n);
    outputarray(a,n);
    int v;
    printf("\nEnter a number to be searched : ");
    scanf("%d",&v);
    if(searchlinear(a,n,v)==-1)
    printf("\nElement not found");
    else
    printf("\nElement found");
    return 0;
}