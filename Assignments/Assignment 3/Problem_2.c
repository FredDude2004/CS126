#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m[5] = { 4, 3, 2, 1, 0 };
    int *p;
    p = m + 2;
    printf("m is %lu, &m is %lu, &m[0] is %lu, m[0] is %lu\n", m,
    (unsigned long)&m, (unsigned long)&m[0], m[0]);

    printf("p is %lu, &p is %lu, &p[0] is %lu, p[0] is %lu\n", p,
    (unsigned long)&p, (unsigned long)&p[0], p[0]);
}

/*
a)
    m is 6422216, &m is 6422216, &m[0] is 6422216, m[0] is 4
    p is 6422224, &p is 6422224, &p[0] is 6422224, p[0] is 2

b) 
    +------+------+------+------+------+------+
    |  4   |  3   |  2   |  1   |  0   |      |
    +------+------+------+------+------+------+
    ^      ^      ^      ^      ^      ^
    |      |      |      |      |      |
    m      |      |      |      |      p
           &m    &m[0]   &p    &p[0]

c) 
    The first three values in the first printf are the same because
    they all represent the base address of array m. In C, the name 
    of an array without an index (such as m) gives the address of its 
    ffirst element. So, m, &m, and &m[0] all point to the same memory 
    location, which is the starting address of array m.

d) 
    The first three values in the second printf (p, &p, and &p[0]) are 
    not the same because they represent different memory addresses. p 
    holds the address of the third element of array m, &p represents the 
    address of the pointer variable p itself, and &p[0] represents the address 
    where p[0] would be stored. These addresses are distinct because they 
    correspond to different variables in memory.

e) 
    p[-1] will give the value at the memory location preceding the address 
          pointed to by p. In this case, since p is pointing to the third 
          element of array m, p[-1] will access the value of the second element 
          of m, which is 3.
    p[-2] will give the value at the memory location two positions before the 
          address pointed to by p. So, p[-2] will access the value of the first 
          element of m, which is 4.
*/