#include <stdio.h>
#include <string.h>

// Function to generate all possible subsets of a string
void generateSubsets(char *str, int start, int end, char *subset, int index) {
    // Print current subset
    for (int i = 0; i < index; i++) {
        printf("%c", subset[i]);
    }
    printf("\n");

    // Generate subsets including the current character
    for (int i = start; i < end; i++) {
        subset[index] = str[i];
        generateSubsets(str, i + 1, end, subset, index + 1);
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline character
    str[strcspn(str, "\n")] = '\0';

    int length = strlen(str);
    char subset[length];

    printf("All possible subsets of \"%s\":\n", str);
    generateSubsets(str, 0, length, subset, 0);

    return 0;
}
