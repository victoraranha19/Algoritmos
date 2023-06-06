#include <stdio.h>
#include <math.h>

//Implements the sieve of Eratosthenes
//Input: A positive integer n > 1
//Output: Array L of all prime numbers less than or equal to n

int main() {
    int n;
    scanf("%d", &n);
    int A[n];

    for (int p = 2; p <= n; p++) {
        A[p]=p;
    }
    for (int p = 2; p <= floor(sqrt(n)); p++) {
        if(A[p]!=0) {
            int j=p*p;
            while(j<=n) {
                A[j]=0;
                j+=p;
            }
        }
    }
    int q=-1;
    for (int p = 2; p <= n; p++) {
        if(A[p]!=0) {
            q++;
        }
    }
    int L[q];
    for (int p = 2; p <= n; p++) {
        if(A[p]!=0) {
            //printf("%d ", A[p]);
            L[q]=A[p];
            q++;
        }
    }

    return 0;
}