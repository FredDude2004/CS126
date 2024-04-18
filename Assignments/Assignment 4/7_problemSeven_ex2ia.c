// :::::::::::::: ex2ia.c ::::::::::::::
/* ex2ia.c index into arrays */

#include <stdio.h>

int main()
{
    char m[10] = "hello";
    char n[20] = "how are you?"; // declared the array to have extra space for modification
    char *p, *q;

    p = &m[0]; /* OR p = m */
    q = n;

    printf("chars in m[2] and m[4] are %c %c\n", p[2], p[4]);

    *q = p[2];

    printf("string at n is %s\n", q);
}

/*  This program initializes two character arrays, assigns the address of their first 
    elements to pointers, prints specific characters of one array, modifies a character in 
    the second array, and then prints the modified string.  
    
    What can we do with pointers to arrays?
    Pointers to arrays allow us grab specific parts of arrays 
    using with pointers, like p[2] gets the third letter of array m. Also, 
    they let us change what's inside arrays without directly touching them (like *q = p[2] 
    changes what's in array n). */