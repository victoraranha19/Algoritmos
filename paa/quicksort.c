#include <stdio.h>

int lomutoPartition(int *A, int l, int r) {
    int p=A[l];
    int s=l;
    for(int i=l+1; i<=r; i++) {
        if(A[i]<p) {
            s++;
            int aux=A[s];
            A[s]=A[i];
            A[i]=aux;
        }
    }
    int aux=A[l];
    A[l]=A[s];
    A[s]=aux;
    return s;
}

//QuickSort
void quickSort(int *A, int l, int r) {
    if(l>r) return;
    int s=lomutoPartition(A,l,r);
    quickSort(A,l,s-1);
    quickSort(A,s+1,r);
}

int main() {
    int n=7;
    int Arr[7] = {5,3,6,2,2,1,6};

    quickSort(Arr,0,n-1);

    for(int i=0;i<n;i++) {
        printf("%d ", Arr[i]);
    }
    return 0;
}