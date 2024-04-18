// :::::::::::::: ex4.c ::::::::::::::
/* ex4.c: what do I do? */

#include <stdio.h>

int main()
{
    char veg[4][20];
    int i;

    strcpy(food[0], "peas");
    strcpy(food[1], "carrots");
    strcpy(food[2], "kale");
    strcpy(food[3], "lettuce");
    
    for(i=0; i<4; i++)
    {
        printf("item %d is %s\n", i, food[i]);
    }
    
    what_do_i_do(veg);
}

void what_do_i_do(char a[4][20])
{
    char *p[4];
    int i;
    
    for(i=0 ; i<4 ; i++)
    {
        p[i] = &a[4-i];
    }
    
    for(i=0 ; i<4 ; i++ )
    {
        printf("in array p, item %d is %s\n", i, p[i] + i);
    }
}