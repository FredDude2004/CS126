#include <stdio.h>
#include <stdlib.h>

int sumArrays(int ***ptrArray, int numArrays, int *rowsArray, int *colsArray) {
    int totalSum = 0;
    for (int nA = 0; nA < numArrays; nA++) {
        int rows = rowsArray[nA];
        int columns = colsArray[nA];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                totalSum += ptrArray[nA][i][j];
            }
        }
    }
    return totalSum;
}

int main() {
    int numArrays;
    int ***ptrArray;

    printf("Enter the number of arrays you want to add: \n");
    scanf("%d", &numArrays);

    ptrArray = (int ***)malloc(numArrays * sizeof(int **));
    if (ptrArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int rowsArray[numArrays];
    int colsArray[numArrays];

    for (int nA = 0; nA < numArrays; nA++) {
        int rows, columns;
        printf("How many rows and columns will this array have? (input: rows columns)\n");
        scanf("%d %d", &rows, &columns);

        ptrArray[nA] = (int **)malloc(rows * sizeof(int *));
        if (ptrArray[nA] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        for (int i = 0; i < rows; i++) {
            ptrArray[nA][i] = (int *)malloc(columns * sizeof(int));
            if (ptrArray[nA][i] == NULL) {
                printf("Memory allocation failed.\n");
                return 1;
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                printf("What will the value of the element at row: %d column: %d in array: %d be?\n", i + 1, j + 1, nA + 1);
                scanf("%d", &ptrArray[nA][i][j]);
            }
        }
        rowsArray[nA] = rows;
        colsArray[nA] = columns;
    }

    int sum = sumArrays(ptrArray, numArrays, rowsArray, colsArray);
    printf("The sum of the arrays is %d", sum);

    for (int nA = 0; nA < numArrays; nA++) {
        for (int i = 0; i < rowsArray[nA]; i++) {
            free(ptrArray[nA][i]);
        }
        free(ptrArray[nA]);
    }
    free(ptrArray);

    return 0;
}
