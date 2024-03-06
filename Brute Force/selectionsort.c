#include<stdio.h>

void selectionSort(int a[],int n){
    int i,j,minim;
    for(i=0;i<n-1;i++){
        minim=i;
        int temp;
        for(j=i;j<n;j++){
            if(a[minim]>a[j]){
                minim=j;
            }
        }
        temp=a[i];
        a[i]=a[minim];
        a[minim]=temp;

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
    selectionSort(a,n);
    printf("Sorted array is:");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    
}