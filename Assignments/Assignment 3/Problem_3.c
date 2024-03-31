#include <stdio.h>
#include <stdlib.h>

int main()
{
    char n[10]; // line 1
    char m[10] = "September"; // line 2
    char *p = "October"; // line 3
    
    strcpy(n, p+2);
    strncat(n, m+3, 3);
    
    printf("m contains \"%s\"\n", m);
    printf("n contains \"%s\"\n", n);
    printf("\"October\" has value %lu\n", "October");
    printf("\"October\"+3 has value %lu\n", "October"+3);
    printf("p+4 is %lu\n", (unsigned long)p+4);
    //p[0] = ’A’; // line 11
    
    printf("The address of m is %lu\n", &m);
    printf("The address of n is %lu\n", &n);
    printf("The address of p is %lu\n", p);
    printf("The address of main is %lu\n", &main);
    
    return 0;
}

/*
a) 
    In the code

b) 
    +------+------+------+------+------+------+------+------+------+------+------+
    |  S   |  e   |  p   |  t   |  e   |  m   |  b   |  e   |  r   |  \0  |      |  // m
    +------+------+------+------+------+------+------+------+------+------+------+
    |  o   |  b   |  e   |  r   |  \0  |  t   |  e   |  r   |  \0  |  \0  |      |  // n
    +------+------+------+------+------+------+------+------+------+------+------+
    ^      ^              ^                                                      ^
    |      |              |                                                      |
    m      |              n                                                      p
            &m             &n                                                     &p
                                                                                main

c) 
    Lines 2 and 3 look similar because they both involve initializing character arrays with 
    string literals. However, the difference lies in how the memory is allocated for these 
    arrays. m is a character array initialized with "September", meaning the characters and 
    null terminator are stored in memory allocated for m. p is a character pointer initialized 
    with the address of the string literal "October", which resides in read-only memory.

d) 
    The string "October" is stored far from the local variables, likely in a read-only memory 
    section. This distance would be evident when comparing the memory addresses of the local 
    variables (m, n, p, main) with the memory address of the string literal "October".

e)  
    When the program executes line 11, it tries to modify the contents of the string literal 
    pointed to by p. This operation invokes undefined behavior because string literals are 
    stored in read-only memory. To allow p to point to a mutable string, you can allocate memory 
    dynamically using malloc and copy the contents of the string literal into the dynamically 
    allocated memory. For example:

*/