/*
Your task is to convert the specified number of days into years, weeks and days, hours , minutes
and seconds:
• Take number of days as input.
• Calculate years, weeks and days.
• Display years, weeks and days, hours , minutes and seconds.
Input Format
The first line contains single integer.
Output Format
Print the years, weeks and days, hours, minutes and seconds in separate lines.
Sample Input
1329
Sample Output
Years: 3
Weeks: 33 and Days: 3
Hours: 31896
Minutes: 1913760
Seconds: 114825600
Note: Ignore leap year
*/

#include <stdio.h>

int main(){
    int days;

    printf("Enter the number of days: ");
    scanf("%d", &days);

    int years = days / 365;
    int weeks = (days % 365) / 7;
    int left_over_days = days - ((years * 365) + (weeks * 7));

    printf("Years: %d\nWeeks: %d and Days: %d\n", years, weeks, left_over_days);
    printf("Hours: %d\nMinutes: %d\nSeconds: %d", days * 24, days * 24 * 60, days * 24 * 60 * 60);

    return 0;
}