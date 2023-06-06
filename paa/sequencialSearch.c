#include <stdio.h>

//Searches for a given value in a given array by sequential search
//Input: An array A[0..n − 1] and a search key K
//Output: The index of the first element in A that matches K or −1 if there are no matching elements
int sequencialSearch(int *A, int n, int k) {
    int i=0;
    while (i < n && A[i] != k) {
        i++;
    }
    if (i < n) {
        return i;
    }
    return -1;
}

//Implements sequential search with a search key as a sentinel
//Input: An array A of n elements and a search key K
//Output: The index of the first element in A[0..n − 1] whose value is equal to K or −1 if no such element is found
int sequencialSearch2(int *A, int n, int k) {
    A[n]=k;
    int i=0;
    while (A[i] != k) {
        i++;
    }
    if (i < n) {
        return i;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    int A[n+1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("\n%d", sequencialSearch(A, n, k));
    printf("\n%d", sequencialSearch2(A, n, k));
    return 0;
}