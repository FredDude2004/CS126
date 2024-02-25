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
    
    
    int handFound = 0, handRank1, handRank2;
    while (handFound == 0)
    {
        // Checking for Royal FLush
        int royalFlush = 1;
        while (royalFlush == 1)
        {
            if (valuedHand1[0] == 1  || valuedHand1[0] == 14 || 
                valuedHand1[0] == 27 || valuedHand1[0] == 40)
            {
                if (valuedHand1[0] == 10 || valuedHand1[0] == 23 || 
                    valuedHand1[0] == 36 || valuedHand1[0] == 49 || )
                {
                    royalFlush = 1;
                    for (int i = 1; i < 5; i++)
                    {
                        if (valuedHand1[i] != valuedHand1[i - 1] + 1)
                        {
                            royalFlush = 0;
                            break;
                        }
                    }
                    if (royalFlush == 1)
                    {
                        handRank1 = 10;
                        handFound = 1;   
                    }
                }
                else
                {
                    royalFlush = 0;
                }
            }
            else 
            {
                royalFlush = 0;
            }
        }
        
        // Checking for straight flush
        int straightFlush = 1;
        while (straightFlush == 1)
        {
            for (int i = 1; i < 5; i++)
            {
                if (valuedHand1[i] != valuedHand1[i - 1] + 1)
                {
                    straightFlush = 0;
                    break;
                }
            }
            if (straightFlush == 1)
            {
                handRank1 = 9;
                handFound = 1;   
            }
        }
        
        // Checking for Four of a Kind
        int FourOfKind = 1;
        while (FourOfKind == 1)
        {
            int count1 = 1, count2 = 1;
            if (valuedHand1[0] <= 13 && valuedHand1[2] > 13)
            {
                for (int i = 2; i < 5; i++)
                {
                    if (valuedHand1[i] % 13 == valuedHand1[0])
                        count1++;
                    else if (valuedHand1[i] % 13 == valuedHand1[1])
                        count2++;
                    else
                    {
                        FourOfKind = 0;
                        break;
                    }
                }
                if (count1 == 4 || count2 == 4)
                {
                    handRank1 = 8;
                    handFound = 1;
                }
                else
                    FourOfKind = 0;
            }
            else 
                FourOfKind = 0;
        }
        
        // Checking for Full House
        int FullHouse = 1;
        while (FullHouse == 1)
        {
            int HAND[5];
            for (int i = 0; i < 5; i++)
            {
                HAND[i] = valuedHand1[i] % 13;
            }
            qsort(HAND, size, sizeof(int), compare);
            int value1 = HAND[0]; // First value
            int value2 = HAND[4]; // Second value
            int count1 = 0;
            int count2 = 0;
            
            for (int i = 0; i < size; i++) 
            {
                if (HAND[i] == value1) 
                {
                    count1++;
                } 
                else if (HAND[i] == value2) 
                {
                    count2++;
                }
            }
            
            if (count1 == 3 && count2 == 2 ||
                count1 == 2 && count3 == 3)
            {
                handRank1 = 7;
                handFound = 1;
            }
            else
            {
                FullHouse = 0;
            }
            
        }
        
        // Checking for flush
        int flush = 1;
        while (flush == 1)
        {
            if (valuedHand1[0] >= 1  && valuedHand[4] <= 13 ||
                valuedHand1[0] >= 14 && valuedHand[4] <= 26 ||
                valuedHand1[0] >= 27 && valuedHand[4] <= 39 ||
                valuedHand1[0] >= 40 && valuedHand[4] <= 52)
            {
                handRank1 = 6;
                handFound = 1;
            }
            else
            {
                flush = 0;
            }
        }
        
        // Checking for Straight
        int straight = 1;
        while (straight == 1)
        {
            int HAND[5];
            for (int i = 0; i < 5; i++)
            {
                HAND[i] = valuedHand1[i] % 13;
            }
            qsort(HAND, size, sizeof(int), compare);
            
            for (int i = 1; i < 5; i++)
            {
                if (HAND[i] != HAND[i - 1] - 1)
                {
                    straight = 0;
                    break;
                }
            }
            handRank1 = 5;
            handFound = 1;
            
        }
        
        // Checking for Three of a Kind
        int ThreeOfKind = 1;
        while (ThreeOfKind == 1)
        {
            int HAND[5];
            for (int i = 0; i < 5; i++)
            {
                HAND[i] = valuedHand1[i] % 13;
            }
            qsort(HAND, size, sizeof(int), compare);
            
            if (HAND[0] == HAND[2] ||
                HAND[1] == HAND[3] ||
                HAND[2] == HAND[4])
            {
                handRank1 = 4;
                handFound = 1;
            }
            else 
            {
                ThreeOfKind = 0;
            }
        }
        
    }
}
