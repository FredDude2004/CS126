#include <stdio.h>

int reverse_array(int arr[], int m, int size)
{
    int subset_size = size - m;
    int index = 0;
    int subset[subset_size]; // Storage for the reversed subset

    // Reversing and saving the subset of the array
    for (int i = m; i < size; i++)
    {
        subset[subset_size - 1 - (i - m)] = arr[i];
    }
    // Combining both of the arrays
    for (int i = m; i < size; i++)
    {
        arr[i] = subset[index];
        index++;
    }
    // Printing the result
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

int main()
{
    int size, M;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    printf("Enter the index at which you want the array to be reversed: ");
    scanf("%d", &M);
    M++; // Incrementing to so that we don't have to mess with it later
    
    int index = 0;
    int ARR[size];
    printf("Enter the numbers in the array separated by a space (1 2 3): ");
    while (index < size && scanf("%d", &ARR[index]) == 1)
    {
        index++;
    }
    
    reverse_array(ARR, M, size);
    
    return 0;
}
