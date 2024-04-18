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
    //c = ’t’; incorret code
              //The single quotes around 't' should be regular single quotes ('), not backticks (’).
       c = 't'; 
    }
        
    printf("i= %d, j= %d, c= %c, a= %f\n", i, j, c, a); 
    printf("locations are:\n");
    printf("i=%p, j=%p, c=%p, a=%p\n", &i, &j, &c, &a);
    printf("i at %lu, j at %lu, c at %lu, a at %lu\n",(ul)&i,(ul)&j,(ul)&c,(ul)&a);

    return 0;
}
/*
   This program defines several variables of different types (int, char, and float), 
   assigns values to some of them, and then prints their values and memory addresses.
*/