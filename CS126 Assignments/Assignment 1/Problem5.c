/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and
return an array of the non-overlapping intervals that cover all the intervals in the input. Ask for
user input so that it works on any user input of the format below.
Sample 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Sample 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
Constraints:
1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_of_intervals;
    printf("How many intervals will be given: ");
    while ((scanf("%d", &num_of_intervals) != 1) || num_of_intervals < 0)
    {
        printf("Invalid input: Please enter a positive integer: "); // Making sure input is valid 
        while (getchar() != '\n');  // Clear input buffer 
    }

    int intervals[num_of_intervals][2];

    for (int i = 0; i < num_of_intervals; i++)  // Taking user input 
    {
        int x1, x2;
        if (i == 0)
            printf("Enter first interval (Format [x,y]): ");   
        else if (i == num_of_intervals - 1)
            printf("Enter last interval (Format [x,y]): ");
        else
            printf("Enter next interval (Format [x,y]): ");

        while (getchar() != '\n');  // Clear input buffer 
        while (scanf(" [%d,%d]", &x1, &x2) != 2) 
        {
            printf("Invalid input: Please enter an interval with the specified format: ");  // Making sure input is valid
            while (getchar() != '\n');  // Clear input buffer 
        }
        intervals[i][0] = x1;
        intervals[i][1] = x2;
    }
    
    // Merging intervals
    for (int i = 0; i < num_of_intervals - 1; i++) {
        if (intervals[i][1] >= intervals[i + 1][0] && intervals[i + 1][0] >= intervals[i][0]
            && intervals[i + 1][1] >= intervals[i][1]) {
            intervals[i + 1][0] = intervals[i][0];
            intervals[i][0] = 10101;
        }
        if (intervals[i][1] >= intervals[i + 1][1] && intervals[i + 1][1] >= intervals[i][0]
            && intervals[i + 1][0] <= intervals[i][0]) {
            intervals[i + 1][1] = intervals[i][1];
            intervals[i][0] = 10101;
        }
        if (intervals[i][0] <= intervals[i + 1][0] && intervals[i + 1][1] <= intervals[i][1]) {
            intervals[i + 1][0] = intervals[i][0];
            intervals[i + 1][1] = intervals[i][1];
            intervals[i][0] = 10101; 
        }
        if (intervals[i][0] >= intervals[i + 1][0] && intervals[i + 1][1] >= intervals[i][1]) {
            intervals[i][0] = 10101; 
        }
    }
    
    // Printing new intervals
    printf("[");
    for (int i = 0; i < num_of_intervals; i++)
    {
        if (intervals[i][0] != 10101) {
            printf("[%d,%d]", intervals[i][0], intervals[i][1]);
            if (i != num_of_intervals - 1) {  // Print comma if not the last interval
                printf(",");
            }
        }
    }
    printf("]");
    
    return 0;
}