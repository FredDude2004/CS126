#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sumOfDigits(int n) {
    int numDigits = (int)log10(n) + 1;
    int *arr = (int*)malloc(numDigits * sizeof(int));
    int sum = 0;

    for (int i = 0; i < numDigits; i++) {
        arr[i] = n % 10;
        n /= 10;
        sum += arr[i];
    }

    free(arr);
    return sum;
}

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n, fac, SumOfFacDig;
    printf("Enter an integer to find the factorial and sum of its digits: ");
    scanf("%d", &n);
    
    fac = (int)factorial(n);
    SumOfFacDig = sumOfDigits(fac);
    
    printf("Factorial of n: %d\nSummation of digits: %d\n", fac, SumOfFacDig);
}