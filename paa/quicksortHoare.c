#include <stdio.h>

//Hoare's Partition
int hoarePartition(int *A, int l, int r) {
    int p=A[l];
    int i=l, j=r+1;
    do {
        do {
            i++;
        } while(A[i]<p);
        do {
            j--;
        } while(A[j]>p);
        int aux=A[i];
        A[i]=A[j];
        A[j]=aux;
    } while(i<j);

    int aux=A[i]; // desfaz a ultima troca
    A[i]=A[j];
    A[j]=aux;

    aux=A[l];
    A[l]=A[j];
    A[j]=aux;
    return j;
}

//QuickSort
void quickSort(int *A, int l, int r) {
    if(l>r) return;
    int s=hoarePartition(A,l,r);
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