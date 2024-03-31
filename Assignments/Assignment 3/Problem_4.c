/*
Write a program called arraypointer.c that demonstrates two facts:
i. Arrays themselves are not passed to functions, but a pointer to the first element of the
array is what is passed.
ii. Ints and floats are directly passed to functions.
Your output should be compelling evidence printed out to the terminal window (standard out). Note
that you can use any type of array that you would like.
The grade for testing on this program will be based on the variety of inputs that you use as input (ie
using one example isn’t good enough for full points on the testing portion).
You can consider using the sizeof command. → we discussed this in class.
If you use the sizeof command on an array inside a function, this might end in a warning
note: declared here. This is an allowable warning.
*/

#include <stdio.h>

// arrays are passed as pointers
void modifyArray(int *arr, int size) {
    printf("Inside modifyArray function:\n");
    printf("Size of array received: %lu bytes\n", sizeof(arr)); // sizeof pointer, not array
    printf("Size of each element in the array: %lu bytes\n", sizeof(*arr));
    printf("Array elements before modification:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < size; ++i) {
        arr[i] *= 2;
    }

    printf("Array elements after modification:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

// ints and floats are directly passed
void modifyIntFloat(int x, float y) {
    printf("Inside modifyIntFloat function:\n");
    printf("Size of int passed: %lu bytes\n", sizeof(x));
    printf("Size of float passed: %lu bytes\n", sizeof(y));
    printf("Value of int before modification: %d\n", x);
    printf("Value of float before modification: %f\n", y);

    // Modifying int and float
    x *= 2;
    y *= 2;

    printf("Value of int after modification: %d\n", x);
    printf("Value of float after modification: %f\n\n", y);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    printf("Inside main function:\n");
    printf("Size of array in main: %lu bytes\n", sizeof(arr));
    printf("Size of each element in the array: %lu bytes\n\n", sizeof(arr[0]));

    // Passing an actual array to the function, but it is received as a pointer
    modifyArray(arr, arrSize);

    int x = 10;
    float y = 3.14;

    printf("Inside main function:\n");
    printf("Size of int in main: %lu bytes\n", sizeof(x));
    printf("Size of float in main: %lu bytes\n\n", sizeof(y));

    modifyIntFloat(x, y);

    return 0;
}
