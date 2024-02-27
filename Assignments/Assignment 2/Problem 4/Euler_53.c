#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial(unsigned int n) {
    if (n == 0 || n == 1)
        return 1;
    else    
        return n * factorial(n - 1);
}

long long combinatoric(int n, int r) {
    long long C[n+1][r+1];
    int i, j;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= (i < r ? i : r); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    return C[n][r];
}

int main() {
    int count = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = i + 1; j <= 100; j++) {
            if (combinatoric(j, i) > 1000000) {
                count++;
            }
        }
    }

    printf("There will be %d not necessarily distinct values of (n r) for 1 <= n <= 100 that are greater than 1000000", count);
    return 0;
}
