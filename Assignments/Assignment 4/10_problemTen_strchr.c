// :::::::::::::: strchr.c ::::::::::::::
#include <stdio.h>

char *my_strchr(char *s, char c);

typedef unsigned long ul;

// a version of strchr

#define LEN 100
int main()
{
    char line[LEN];
    char chr;
    char *where;

    printf("Enter some text: ");
    fgets(line, LEN, stdin);
    printf("Enter a char: ");
//    getchar(); // Consume the newline character
  //  chr = getchar();

    
    chr = getchar();
    where = my_strchr(line, chr);
    
    printf("Line is at %lu, strchr returned %lu\n", (ul) line, (ul) where); 
    
    return 0;
}

/* strchr(str, chr) returns address of first instance of chr in str or NULL */

char *my_strchr(char *str, char chr)
{
    // search for chr in str, return address of where chr is found
    // or return NULL if not found
    // version1: Indexing
    int i;
    
    for ( i = 0 ; str[i] != '\0'; i++ )
    {
        if ( str[i] == chr )
        return &str[i];
    }
        
    return NULL;
    
    // version2: Using pointers
    
}

/*  This program asks the user to input some text and a single character. 
    Then, it searches for the first occurrence of that character in the 
    input text and prints out where it was found in memory.*/