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

int main() {
    int n;
    binary(n);
}