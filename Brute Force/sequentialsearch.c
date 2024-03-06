#include<stdio.h>

int sequentialSearch(int a[],int n,int k){
    int i;
    for(i=0;i<n;i++){
        if(a[i]==k){
            return i;
        }
    }
    return -1;
}

void main(){
    int n,i,k;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d numbers to be added in the array:\n",n);
    for(i=0;i<n;i++){
        printf("Enter %d element:",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter number to be searched in the list:");
    scanf("%d",&k);
    if (sequentialSearch(a,n,k)==-1){
        printf("Element not found");
    }else{
        printf("Element is found at index %d",sequentialSearch(a,n,k));
    }
}