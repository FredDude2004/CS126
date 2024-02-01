/*
Your task is to calculate area of circle or circumference of circle based on the option selected by
user
• Display menu to the user with below options:
• Area of Circle
• Circumference of Circle
• Take input from user as a or b
• Take radius from user
• Calculate and display output (scaled to 2 decimal place)
Sample:
Operations:
• Area of Circle
• Perimeter of Circle
Selected option: a
Enter radius of circle : 6
Area of circle is 113.04 square inches.
Note: Area = 𝝅 and Perimeter = 2𝝅r, 𝝅 = 3.14
*/
#include <stdio.h>

int main(){
    float radius, result;
    char option_select;
    const float PI = 3.141592653;

    // user input
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    printf("What would you like to find?\na) Area of Circle\nb) Circumference of Circle\nEnter your option (a or b): ");
    scanf(" %c", &option_select);

    // output
    switch(option_select){
        case 'a':
            result = PI * radius * radius;
            printf("Area of the circle is %0.2f square inches.", result);
            break;
        case'b': 
            result = 2 * PI * radius;
            printf("Circumference of the circle is %0.2f inches.", result);
            break;
        default: 
            printf("Error: incorrect input");
            break;
    }

    return 0;
}