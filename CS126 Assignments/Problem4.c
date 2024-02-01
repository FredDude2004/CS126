/*
Your task is to take three numbers of int data type as input and output the largest among the
three:
• Declare variables: three of type int.
• Read lines of input from stdin (according to the sequence given in the 'Input Format'
section below) and initialize your variables.
• Use the operators to perform the following operations:
• Print the Highest common factor from the three values.
• Print the Lowest common multiple from the three values.
Sample:
Input Format
Input the first integer: 25
Input the second integer: 35
Input the third integer: 15
Output Format
HCF of three integers: 5
LCM of three integers: 525
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int num1, num2, num3, HCF, LCM;
    
    printf("Input the first integer: ");    // input
    scanf("%d", &num1);
    printf("Input the second integer: ");
    scanf("%d", &num2);
    printf("Input the third integer: ");
    scanf("%d", &num3);

    int smallest_num = (num1 < num2) ? num1 : num2; //  Finding the smallest number, using the ternary operator
    smallest_num = (smallest_num < num3) ? smallest_num : num3;
    
    bool found_HCF = false;  // Finding the HCF
    for (int i = smallest_num; !found_HCF; i--)  
    {
        if ((num1 % i == 0) && (num2 % i == 0) && (num3 % i == 0))
        {
            HCF = i;
            found_HCF = true;
        }
    }
    
    bool found_LCM = false;  // Finding the LCM
    for (int n = smallest_num; !found_LCM; n += smallest_num)
    {
        if (n % num1 == 0 && n % num2 == 0 && n % num3 == 0)
        {
            LCM = n;
            found_LCM = true;
        }
    }

    printf("HCF of three integers: %d\n", HCF); // output
    printf("LCM of three integers: %d\n", LCM);
    return 0;
}