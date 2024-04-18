// :::::::::::::: ex2.c ::::::::::::::
/* ex2.c: arrays */

#include <stdio.h>

int main()
{
    char
    char

    m[10] = "hello";
    n[] = "how are you?";

    char *p, *q;

    p = &m[0]; /* OR p = m */
    /* name of array is addr of 1st el */
    q = n;

    if ( *p == *q )
    {
        printf("values are same\n"); 
    }   
    if ( p == q )
    {
        printf("addresses are same\n"); 
    }   
    else 
    {
        printf("addresses differ\n");
        printf("the char at m is %c\n", *m);
        printf("the string at m is %s\n", m);
        printf("the address of m is %lu\n", (unsigned long) m); 
        printf("the address of n is %lu\n", (unsigned long) n);     
    }

    return 0;
}