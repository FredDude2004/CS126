#include <stdio.h>

#define ROWS 100
#define COLS 100

int maxAdjSum(int data[ROWS][COLS], int row, int index) {
    int a = data[row + 1][index];
    int b = data[row + 1][index + 1];
    return (a >= b) ? a + data[row][index] : b + data[row][index];
}

int main() {
    // Creating a 2D array to store the triangle
    int data[ROWS][COLS] = {0}; // Initialize the array to 0

    // Opening triangle.txt in read mode
    FILE *triangle = fopen("triangle.txt", "r");
    if (triangle == NULL) {
        printf("File could not be opened");
        return 1;
    }

    // Saving data in a 2D array
    int row = 0;
    while (row < ROWS && fscanf(triangle, "%d", &data[row][row]) != EOF) {
        for (int j = 1; j <= row; j++) {
            fscanf(triangle, "%d", &data[row][j]);
        }
        row++;
    }

    // Closing triangle.txt
    fclose(triangle);

    // Iterating through the triangle from the second last row
    for (int i = ROWS - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            // Adding maximum of adj up the triangle until I'm at the top
            data[i][j] = maxAdjSum(data, i, j);
        }
    }

    // Printing the max
    printf("The maximum total from top to bottom of triangle.txt is %d", data[0][0]);

    return 0;
}
