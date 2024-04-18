// :::::::::::::: ex2.c ::::::::::::::
/* ex2.c: arrays */

#include <stdio.h>

int main()
{
    // removed random data types

    char m[10] = "hello";   // added the 'char' data type to properly declare the variables
    char n[] = "how are you?";

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
        printf("the string at m is %s\n", m);           // Changed format specifiers to %s
        printf("the address of m is %p\n", (void *)m);  // Changed format specifiers to %s
        printf("the address of n is %p\n", (void *)n);  // Changed format specifiers to %p
    }

    return 0;
}

/*  pointers to arrays can be used to compare the values and addresses of arrays. By assigning the 
    addresses of the first elements of m and n to pointers p and q, the program shows we can access 
    array elements and compare their values using pointers Also, comparing the addresses stored in 
    p and q shows how pointers can hold memory addresses and compare addresses.  */