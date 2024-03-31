#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

void tokenizeString(char *str, char *delimiters, char *tokenized[]) {
    char *token = strtok(str, delimiters);
    int i = 0; 
    while (token != NULL) {
        tokenized[i++] = token;
        token = strtok(NULL, delimiters);
    }
    tokenized[i] = NULL;
}

bool isUnique(char *word, char *uniqueWords[]) {
    for (int i = 0; uniqueWords[i] != NULL; i++) {
        if (strcmp(word, uniqueWords[i]) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    char inputString[MAX_WORDS];
    char *delimiters = " ,.?!-\""; // Delimiters for tokenization
    char *uniqueWords[MAX_WORDS] = {NULL}; // Array to store unique words
    int uniqueWordCount = 0;

    printf("Enter a string: \n");
    fgets(inputString, sizeof(inputString), stdin);

    // Tokenize input string
    char *tokenized[MAX_WORDS] = {NULL};
    tokenizeString(inputString, delimiters, tokenized);

    // Check uniqueness of words
    for (int i = 0; tokenized[i] != NULL; i++) {
        if (isUnique(tokenized[i], uniqueWords)) {
            uniqueWords[uniqueWordCount++] = tokenized[i];
        }
    }

    printf("Number of unique words: %d\n", uniqueWordCount);

    return 0;
}
