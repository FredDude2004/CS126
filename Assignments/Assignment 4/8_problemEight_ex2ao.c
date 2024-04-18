/* ex2ao.c: arithmetic operations */

#include <stdio.h>

int main()
{
    char m[10] = "hello";
    char n[] = "how are you?";
    char *p, *q;

    p = &m[0]; /* OR p = m */
    q = n;

    printf("chars in m[2] and m[4] are %c %c\n", p[2], p[4]);
    printf("string n is %s\n", q); // made the print statement make more sense

    p++;
    q = q + 3;

    printf("chars in m[2] and m[4] are %c %c\n", p[2], p[4]);
    printf("string at n is %s\n", q);
}

/*  This program shows how we can change what element of an array a pointer is pointing at 
    if we add to it, like in line 17 p++; and line 18 q += 3; it changed the output of the exact 
    same print statement */
