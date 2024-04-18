/* :::::::::::::: ex1pa.c ::::::::::::::
   ex1pa.c: print addresses */
   
#include <stdio.h>

typedef unsigned long ul;
int main() 
{
    int i,j;
    char c;
    float a;

    i = 2;
    j = i;

    if ( i == j ) {
       c = 't'; 
    }
        
    printf("i= %d, j= %d, c= %c, a= %f\n", i, j, c, a);
    printf("locations are:\n");
    printf("i=%p, j=%p, c=%p, a=%p\n", &i, &j, &c, &a);
    printf("i at %lu, j at %lu, c at %lu, a at %lu\n",(ul)&i,(ul)&j,(ul)&c,(ul)&a);

    return 0;
}