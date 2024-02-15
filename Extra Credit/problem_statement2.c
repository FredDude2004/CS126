#include <stdio.h>
#include <string.h>

int is_palindrome(int num) {
    if (num < 0) // Negative numbers can't be palindromes
        return 1;

    int length;
    if (num >= 100)
        length = 3;
    else if (num >= 10)
        length = 2;
    else // (num >= 0)
        length = 1;

    char str1[length + 1], str2[length + 1], reversed[length + 1]; // +1 for the null terminator

    sprintf(str1, "%d", num);
    sprintf(str2, "%d", num);

    for (int i = 0; i < length; i++) // Reversing the array to compare them
    {
        reversed[i] = str2[length - i - 1]; 
    }
    reversed[length] = '\0'; // Add the null terminator

    return strcmp(str1, reversed);
}

int main() {
    int n, o;
    printf("Enter the number you want to check is a palindrome: ");
    scanf("%d", &n);

    o = is_palindrome(n);
    if (o == 0)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
