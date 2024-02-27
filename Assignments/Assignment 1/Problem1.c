/*
Problem 01
Your task is to take two numbers of int data type, two numbers of float data type as input and
output their sum:
• Declare variables: two of type int and two of type float.
• Read lines of input from stdin (according to the sequence given in the 'Input Format'
section below) and initialize your variables.
• Use the operators to perform the following operations:
• Print the sum and difference of two int variable on a new line.
• Print the sum and difference of two float variable rounded to one decimal
place on a new line.
Input Format
The first line contains two integers.
The second line contains two floating point numbers.
Constraints
• integer variables
• float variables
Output Format
Print the sum and difference of both integers separated by a space on the first line, and the sum
and difference of both float (scaled to 1 decimal place) separated by a space on the second line.
Sample Input
10 4
4.0 2.0
Sample Output
14 6
6.0 2.0
*/
#include <stdio.h>

int main()
{
    int int1, int2;
    float float1, float2;
    
    // user input
    printf("Enter the first integer: ");
    scanf("%d", &int1);

    printf("Enter the second integer: ");
    scanf("%d", &int2);

    printf("Enter the first floating point number: ");
    scanf("%f", &float1);

    printf("Enter the second floating point number: ");
    scanf("%f", &float2);

    // output
    printf("%d %d\n", int1 + int2, int1 - int2);
    printf("%0.1f %0.1f", float1 + float2, float1 - float2);

    return 0;
}