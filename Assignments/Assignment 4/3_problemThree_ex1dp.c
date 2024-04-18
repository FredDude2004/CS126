// :::::::::::::: ex1dp.c ::::::::::::::
/* ex1dp.c: dereference pointers */

#include <stdio.h>

typedef unsigned long ul;

int main()
{
    int i,j;
    char c;
    int *p; /*p holds address of an int */
    int *q; /*q holds address of an int */
    char *cp;

    p = &i; /*get address and store it */
    q = &j; /*get address and store it */
    cp = &c;
    *p = 3; /* same as: i = 3; */
    *q = *p; /* same as: j = i; */

    if ( *p == *q ) /* same as if ( i == j ) */
    {
        *cp = ’t’ ; /* same as c = ’t’; */
        /* now to print them out */
        printf("i=%d, j=%d, c=%c\n", i,j,c);
        printf("locations are:\n");
        printf("i at %p, j at %p, c at %p\n", p, q, cp);
    }
}