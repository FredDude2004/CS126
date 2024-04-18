// :::::::::::::: ex1pf.c ::::::::::::::
/* ex1pf.c: pass to functions */

#include <stdio.h>

void compare(int *, int *);

void display(int *, char *);

int main()
{
    int i,j;
    char c;
    int *p; /* p holds address of an int */
    int *q; /* q holds address of an int */
    char *cp;

    p = &i; /* get address and store it */
    q = &j; /* get address and store it */
    cp = &c;
    *p = 3; /* same as: i = 3; */
    *q = *p; /* same as: j = i; */

    if ( *p == *q ) 
    {
        c = ’t’;
    }
    
    compare(p, q);
    display(p, cp);
}

/* compare values AND addrs of two int ptrs */

void compare(int *p1, int *p2)
{
    if ( *p1 == *p2 ) /* same as if ( i == j ) */
        printf("values of pointees are equal\n");
    if ( p1 == p2 )
        printf("both point to same place\n");
    else
        printf("point to different places\n");
}

void display(int *ip, char *cp)
{
    printf("values are: %d %c\n", *ip, *cp);
    printf("addrs are %p %p\n", ip, cp);
}