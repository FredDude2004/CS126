// :::::::::::::: ex4.c ::::::::::::::
/* ex4.c: what do I do? */

#include <stdio.h>

// Moved the method to the top of the program so that it is declared before it is used
void what_do_i_do(char a[4][20])
{
    char *p[4];
    int i;
    
    for(i=0 ; i<4 ; i++)
    {
        p[i] = &a[3 - i];
    }
    
    for(i=0 ; i<4 ; i++ )
    {
        printf("in array p, item %d is %s\n", i, p[i]); // pointer math wasn't correct 
    }
}

int main()
{
    char food[4][20]; // changed the name of the array
    int i;

    strcpy(food[0], "peas");
    strcpy(food[1], "carrots");
    strcpy(food[2], "kale");
    strcpy(food[3], "lettuce");
    
    for(i=0; i<4; i++)
    {
        printf("item %d is %s\n", i, food[i]);
    }
    
    what_do_i_do(food);
}


/*  This program first initializes an array called food with four food names. 
    It then prints these food names. After that, it calls a function named what_do_i_do 
    and passes the food array to it. Inside what_do_i_do, the order of the elements in 
    food is reversed, and then it prints them out. So, the program essentially reverses 
    the order of the food names and prints them again.  */
