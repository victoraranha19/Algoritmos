#include <stdio.h>

//Bubble Sort
int bubbleSort(int *A, int tam) {
    for (int i=0; i<tam-1; i++) {
        for(int j=0; j<tam-1-i; j++) {
            if(A[j+1]<A[j]) {
                int aux = A[j+1];
                A[j+1] = A[j];
                A[j] = aux;
            }
        }
    }
}

int main() {
    int n=6;
    int Vetor[6] = {1,2,3,4,5,6};
    bubbleSort(Vetor, n);
	return 0;
}