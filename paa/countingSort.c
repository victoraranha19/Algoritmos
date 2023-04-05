#include <stdio.h>

void countingSort(int *A, int tam) {
    int output[tam];

    int max = A[0];
    for (int i = 1; i < tam; i++) {
        if (A[i] > max)
            max = A[i];
    }

    int count[max+1];
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < tam; i++) {
        count[A[i]]++;
    }
    //printArray(count, max+1);
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = tam - 1; i >= 0; i--) {
        output[count[A[i]] - 1] = A[i];
        count[A[i]]--;
    }

    for (int i = 0; i < tam; i++) {
        A[i] = output[i];
    }
}

void printArray(int *A, int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", A[i]);
    }
}

int main() {
    int n=8;
    int Arr[8]={5,4,3,5,5,1,4,9};

    countingSort(Arr, n);
    printArray(Arr, n);
    return 0;
}