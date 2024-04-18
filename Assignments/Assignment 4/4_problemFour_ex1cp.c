// :::::::::::::: ex1cp.c ::::::::::::::
/* ex1cp.c: compare pointers */

#include <stdio.h>

typedef unsigned long ul;

int main()
{
    int i,j;
    char c = 'x';                           // Changed to single quotes 
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
        printf("*pequals *q: values pointed to are equal\n");
        *cp = 't' ; /* same as c = ’t’; */                      // Changed to single quotes
    }

    if ( p == q ) 
    {
        printf("p equals q: p and q point to same location\n");
    }
    else 
    {
        printf("p != q: p and q point to different places\n");
        /* now to print them out */
        printf("i=%d, j=%d, c=%c\n", i,j,c);
        printf("locations are:\n");
        printf("i at %p, j at %p, c at %p\n", p, q, cp);
    }
    
    return 0;
}

/*
    Overall, this code demonstrates the manipulation of variables through pointers 
    and the comparison of pointer values to determine if they point to the same memory location.
*/