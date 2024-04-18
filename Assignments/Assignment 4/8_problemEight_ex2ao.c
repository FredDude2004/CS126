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
    printf("string at n is %s\n", q);

    p++;
    q = q + 3;

    printf("chars in m[2] and m[4] are %c %c\n", p[2], p[4]);
    printf("string at n is %s\n", q);
}
