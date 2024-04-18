// :::::::::::::: ex3.c ::::::::::::::
/* ex3.c: pointers to structs */

#include <stdio.h>
#include <string.h>

struct time
{
    int hr, mn;
};

struct tstop
{
    char stn[20];
    char dir;
    struct time when;
};

void print_event(struct tstop *);

int main()
{
    struct tstop s1, s2; // get space for the data
    struct tstop *p1, *p2; // get space to hold addresses

    p1 = &s1; // store addresses of data
    p2 = &s2; // in pointer variables
    
    strcpy(s1.stn, "lynn"); // use struct_name.member
    
    s1.dir = 'i'; // when using name of struct
    s1.when.hr = 9;
    s1.when.mn = 23;
    
    strcpy(p2->stn, "salem"); // use struct_ptr->member
    
    p2->dir = 'i'; // when using ptr to struct
    p2->when.hr = 9;
    p2->when.mn = 12;
    
    print_event( &s1 ); // pass address struct s1
    print_event( p2 ); // p2 holds address of struct s2
    
    return 0;
}

// print out an event: arg is pointer to a train stop event

void print_event(struct tstop *p)
{
    printf("station: %s\n", p->stn);
    printf(" dir: %c\n", p->dir);
    printf(" when: %d:%d\n", p->when.hr, p->when.mn);
}

/*  This program simulates train stop events. It defines structures to represent a train 
    stop with details like station name, direction, and time. Then, it uses pointers to these 
    structures to set and print out information about two train stops, demonstrating how to work 
    with structures and pointers in C.  

    For Struct "What can we do? Take addresses, compare, assign, select members pass to functions 
    by reference" please answer this question for ex3.c
    
    1. Take addresses: You can find out where a struct is stored in memory.
    2. Compare: You can check if two structs are the same or different.
    3. Assign: You can copy the contents of one struct into another.
    4. Select members: You can choose specific parts of a struct.
    5. Pass to functions by reference: You can let a function work directly with a struct, changing 
       its contents if needed.  */