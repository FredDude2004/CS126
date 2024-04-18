// :::::::::::::: ex1sa.c ::::::::::::::
/* ex1sa.c: store addresses */

#include <stdio.h>

typedef unsigned long ul;

int main()
{
    int i,j;
    char c;
    float a;
    int *p; /* p holds address of an int */
    int *q; /* q holds address of an int */
    char *cp;

    p = &i; /* get address and store it */
    q = &j; /* get address and store it */
    cp = &c;
    i = 3;
    j = i;

    if ( i == j ) {
        c = 't';
    }

    /* now to print them out */
    printf("i=%d, j=%d, c=%c\n", i,j,c);
    printf("locations are:\n");
    printf(" in hexadecimal:\n");
    printf(" i at %p, j at %p, c at %p\n", p, q, cp);
    printf(" in decimal:\n");
    printf(" i at %lu, j at %lu, c at %lu\n", (ul)p, (ul)q, (ul)cp);
    printf(" p at %lu, q at %lu, cp at %lu\n", &p, &q, &cp);
}
/*
    This program declares several variables of different types (int, char, and float),
    along with pointers to these types. It then assigns values to some of the variables,
    stores their memory addresses in the pointers, and prints out the values and memory locations.
*/






