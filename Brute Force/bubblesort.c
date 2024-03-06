#include<stdio.h>

void bubbleSort(int a[],int n){
    int i,j,temp; 
    for(i=0;i<n;i++){
        for(j=1;j<n-i;j++){
            if(a[j]<a[j-1]){
                temp=a[j-1];
                a[j-1]=a[j];
                a[j]=temp;
            }
        }
    }
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
    bubbleSort(a,n);
    printf("Sorted array is:");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    
}