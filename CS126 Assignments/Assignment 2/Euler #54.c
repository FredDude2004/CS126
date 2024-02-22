#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    char hand1[5][2];
    char hand2[5][2];
   
    printf("Enter Poker Hand: ");
    scanf("%c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c %c%c",
          &hand1[0][0], &hand1[0][1], &hand1[1][0], &hand1[1][1], &hand1[2][0],
          &hand1[2][1], &hand1[3][0], &hand1[3][1], &hand1[4][0], &hand1[4][1],
          &hand2[0][0], &hand2[0][1], &hand2[1][0], &hand2[1][1], &hand2[2][0],
          &hand2[2][1], &hand2[3][0], &hand2[3][1], &hand2[4][0], &hand2[4][1]);
   
   
    // Converting hand1 into integer values
    int valuedHand1[5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            int value, suite;
            char c = hand1[i][j];
            switch (c)
            {
                case 'A':
                    value = 1;
                    break;
                case 'T':
                    value = 10;
                    break;
                case 'J':
                    value = 11;
                    break;
                case 'Q':
                    value = 12;
                    break;
                case 'K':
                    value = 13;
                    break;
                default:
                    value = c - '0';
                    break;
            }
            c = hand1[i][j+1];
            switch (c)
            {
                case 'C':
                    suite = 0;
                    break;
                case 'H':
                    suite = 1;
                    break;
                case 'S':
                    suite = 2;
                    break;
                case 'D':
                    suite = 3;
                    break;
            }
            valuedHand1[i] = value + (suite * 13);
        }
    }
   
    // Converting hand2 into interger values
    int valuedHand2[5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            int value, suite;
            char c = hand2[i][j];
            switch (c)
            {
                case 'A':
                    value = 1;
                    break;
                case 'T':
                    value = 10;
                    break;
                case 'J':
                    value = 11;
                    break;
                case 'Q':
                    value = 12;
                    break;
                case 'K':
                    value = 13;
                    break;
                default:
                    value = c - '0';
                    break;
            }
            c = hand2[i][j+1];
            switch (c)
            {
                case 'C':
                    suite = 0;
                    break;
                case 'H':
                    suite = 1;
                    break;
                case 'S':
                    suite = 2;
                    break;
                case 'D':
                    suite = 3;
                    break;
            }
            valuedHand2[i] = value + (suite * 13);
        }
    }
   
    // Sorting valuedHand1
    qsort(valuedHand1, size, sizeof(int), compare);

    // Sorting valuedHand2
    qsort(valuedHand2, size, sizeof(int), compare);
   
   
   
   
   
}
