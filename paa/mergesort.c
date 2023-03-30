#include <stdio.h>

//Merge
void merge(int *B, int *C, int *A, int n) {
    int p=n/2;
    int q=n-p;
    int i=0,j=0,k=0;
    while(i<p && j<q) {
        if(B[i]<=C[j]) {
            A[k++]=B[i++];
        }
        else {
            A[k++]=C[j++];
        }
    }
    if(i==p) {
        while(j<q) {
            A[k++]=C[j++];
        }
    }
    else {
        while(i<q) {
            A[k++]=B[i++];
        }
    }
}

//MergeSort
void mergeSort(int *A, int n) {
    if(n>1) {
        int half1=n/2;
        int half2=n-half1;
        int B[half1], C[half2];
        for(int i=0;i<half1;i++) {
            B[i]=A[i];
        }
        for(int i=half1,j=0;i<n;i++) {
            C[j++]=A[i];
        }
        mergeSort(B,half1);
        mergeSort(C,half2);
        merge(B,C,A,n);
    }
}

int main() {
    int n=7;
    int Arr[7] = {3,2,1,6,7,8,5};
    mergeSort(Arr, n);
    for(int i=0;i<n;i++) {
        printf("%d ", Arr[i]);
    }
    return 0;
}