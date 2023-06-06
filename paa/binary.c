#include <stdio.h>

//Input: A positive decimal integer n
//Output: The number of binary digits in n’s binary representation
int binary(int n) {
    int count=1;
    while(n>1) {
        n/=2;
        count++;
    }
    return count;
}

//Input: A positive decimal integer n
//Output: The number of binary digits in n’s binary representation
int binRec(int n) {
    if(n==1) {
        return 1;
    }
    return binRec(n/2)+1;
}

int main() {
    int n;
    printf("\n%d",binary(n));
    printf("\n%d",binRec(n));
}