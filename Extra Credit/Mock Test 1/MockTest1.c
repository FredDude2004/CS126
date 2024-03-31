#include <stdio.h>

#define max_size 100

int findSubset(int arr[], int N, int target_sum) {
    int iterations = 1;
    int num_indexes = 2;

    while (num_indexes <= N) {
        int current_sum = 0;
        int indexes[max_size]; // To store indexes of elements in the subset
        int num_elements = 0; // Number of elements in the subset

        for (int i = 0; i < N; i++) {
            current_sum += arr[i];
            indexes[num_elements++] = i + 1; // Store the index

            if (current_sum == target_sum && num_elements == num_indexes) {
                // Print the indexes of the subset
                for (int k = 0; k < num_elements; k++) {
                    printf("%d ", indexes[k]);
                }
                return 1;
            }

            // Adjust the current sum and indexes if the 
            // subset size exceeds the required number of elements
            while (current_sum > target_sum || num_elements > num_indexes) {
                current_sum -= arr[i - num_elements + 1];
                num_elements--;
            }
        }
        num_indexes++; // Increment the number of indexes for the next iteration
    }
    return 0;
}


int main(){
	int N, X, num;
	scanf("%d %d", &N, &X);

	int candies[N];
	for (int i = 0; i < N; i++){
		scanf("%d ", &num);
		candies[i] = num;
	}

	if (!findSubset(candies, N, X)) {
        printf("-1");
    }
}