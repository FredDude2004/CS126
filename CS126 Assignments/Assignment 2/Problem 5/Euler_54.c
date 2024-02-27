#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// returning the reverse of a given number
int reverse(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

// Checking if the number is the same backwards and forewards
int isPalindrome(int n) {
    if (n == reverse(n)) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

// Checking if the given number is a Lychrel number
int isLychrel(int n) {
    for (int i = 0; i < 50; i++) {
        if (isPalindrome(n) == TRUE) {
            return FALSE;
        }
        else {
            n += reverse(n);
        }
    }
    return TRUE;
}

int main() {
    int count = 0;
    // Iterating through every number that is below 10,000 and checking if it is a Lychrel number
    for (int n = 10; n <= 10000; n++) {
        if (isLychrel(n) == TRUE) {
            count++; // counting it if it is a Lychrel number
        }
    }

    // Printing out the count
    printf("There are %d Lychrel numbers below 10,000\n", count);
    return 0;
}
