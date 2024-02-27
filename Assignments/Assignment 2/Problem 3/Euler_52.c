#include <stdio.h>
#include <stdlib.h>

#define DIGITS 10

// Compare function for sorting arrays
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Checks if two arrys of integers are the same
int areArraysEqual(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}

// Converts an integer into an array of integers 
int* toArray(int n) {
    int *arr = malloc(DIGITS * sizeof(int));
    int numDigits = 0;

    while (n > 0) {
        arr[numDigits] = n % 10;
        n /= 10;
        numDigits++;
    }

    return arr;
}

// Checks if n contains the same digits as 2n, 3n, 4n, 5n, and 6n
int checkSameDigits(int n) {
    int *arr1 = toArray(n);
    qsort(arr1, DIGITS, sizeof(int), compare);

    int TRUE = 1;
    for (int i = 2; i <= 6; i++) {
        int *arr2 = toArray(n * i);
        qsort(arr2, DIGITS, sizeof(int), compare);

        if (areArraysEqual(arr1, arr2, DIGITS) == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int FOUND = 0;
    // Start looping through posotive integers to see if they contain the same digits
    for (int i = 10; FOUND == 0; i++) {
        if (checkSameDigits(i) == 1) {
            FOUND = i;
        }
    }

    printf("The smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits is %d", FOUND);
    return 0;
}  
