// :::::::::::::: ex2ae.c ::::::::::::::
/* ex2ao.c: arithmetic exercises */

/*
    232 236 240 244 248 252 256 260 addrs
    +----+----+----+----+----+----+----+----+----+----+----+----+-----+----+
    |    |    |    |  ? |  ? |  ? |  ? |  ? |    |    |    |    |     |    |
    +----+----+----+----+----+----+----+----+----+----+----+----+-----+----+
    +---------+
    |     p   |
    +---------+
    +---+
    i| ? |
    +---+
*/

#include <stdio.h>

int main() {
    int t[5], *p, i;

    p = t;
    
    for (i = 0; i < 5; i++) {
        *p = i;
        p++;
    }
    
    p = t; // Resetting pointer p to the start of array t
    
    for (i = 0; i < 5; i++) {
        printf("t[%d] = %d\n", i, t[i]);
    }
    
    /*
    printf("t is at %p, p holds value %p and points to %d\n", t, p, *p); 
    printf("(p+2)[0] = %d\n", (p+2)[0]); 
    printf("(p-2)[4] = %d\n", (p-2)[4]);
    printf("(p+10)[-8] = %d\n", (p+10)[-8]);
    printf("(p+*p)[*(p+1)] = %d\n", (p+*p)[*(p+1)]);
    */
    printf("t is at %p, p holds value %p and points to %d\n", (void*)t, (void*)p, *p); 
    printf("(p+2)[0] = %d\n", *(p+2)); // Accessing the value at p+2
    printf("(p-2)[4] = %d\n", *(p-2+4)); // Accessing the value at p-2+4
    printf("(p+10)[-8] = %d\n", *(p+10-8)); // Accessing the value at p+10-8
    printf("(p+*p)[*(p+1)] = %d\n", *((p+*p) + *(p+1))); // Accessing the value at (p+*p) + *(p+1)
    
    return 0;
}

/*
    This program initializes an array of integers from 0 to 4 using pointer manipulation. 
    It then prints out the elements of the array and the memory addresses of the array and
    a pointer. Additionally, it performs some pointer arithmetic operations and prints the 
    results. The pointer arithmetic includes accessing elements at specific positions relative 
    to the pointer. However, there were potential bugs related to out-of-bounds memory access 
    and uninitialized variables, which have been fixed to ensure the program runs correctly. 
    Overall, the program demonstrates basic array manipulation and pointer arithmetic in C.
*/
