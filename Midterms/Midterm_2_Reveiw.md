# Quiz: Systems Programming in C

 ## 1. What happens if strtok() is called with a null pointer as its first argument?<br>
a) It returns NULL<br>
b) It starts tokenization from the beginning of the string<br>
c) The program crashes<br>
d) It generates an empty token<br>

## 2. What is the maximum bytes of memory required to store the 3D matrix quotations in memory?<br>
```c
#include <stdio.h>

int main() {
    char quotations[][3][32] = {
        {"Where there's a will, there's a way.", "All's well that ends well.", "A penny saved is a penny earned."},
        {"Beauty is in the eye of the beholder.", "Better late than never.", "Cleanliness is next to godliness."},
        {"Don't count your chickens before they hatch.", "Every cloud has a silver lining.", "Fortune favors the bold."}
    };    
    return 0;
}
```
a) It varies depending on the length of each quotation.<br>
b) 288 bytes<br>
c) 288 * 4 bytes<br>
d) 96 bytes<br>

## 3. What happens when you explicitly add \0 at the end of a string in C?
a) The string is terminated with a null character ('\0'), indicating the end of the string.<br>
b) The \0 character is treated as part of the string, affecting its length and content.<br>
c) The program encounters a compilation error due to an invalid escape sequence.<br>
d) The program behaves unpredictably, leading to undefined behavior.<br>

## 4. What is the difference between a NULL pointer and a void pointer in C?
a) A NULL pointer is a pointer that points to the address 0x00000000, while a void pointer is a pointer that points to the address of the first element of an array.<br>
b) A NULL pointer is a pointer that points to an invalid memory location, while a void pointer is a pointer that can point to any data type.<br>
c) A NULL pointer is a pointer that points to a memory location with the value zero, while a void pointer is a pointer that cannot be dereferenced.<br>
d) A NULL pointer is a pointer that cannot be dereferenced, while a void pointer is a pointer that points to an unspecified data type.<br>


## 5. How many bytes of memory does below malloc allocates ?
```c
char *str = malloc(sizeof(char) * 2);
```
a) 3<br>
b) 2<br>
c) 1<br>
d) Incorrect Syntax<br>

## 6. Identify the correct option below to make the code work properly without errors / warnings.
```c
#include <stdio.h>
#include <string.h>

int main() {
    const char *input_string = "Hello, world!";
    char *reversed_string;
    int length, i;

    length = strlen(input_string);

    reversed_string = (char *)malloc(sizeof(char) * (length + 1));
    if (reversed_string == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (i = 0; i < length; i++) {
        reversed_string[i] = input_string[length - 1 - i];
    }
   
    printf("Reversed string: %s\n", reversed_string);

    free(reversed_string);

    return 0;
}
```
a) Include a null terminator ('\0') at the end of the reversed string after the loop completes to ensure it is properly terminated.<br>
b) Incorrect allocation of memory size for reversed_string.<br>
c) All of the above.<br>
d) Modify the loop to copy characters from the input string in reverse order to the reversed string.<br>

## 7. What is the purpose of the realloc() function in C?
a) To release dynamically allocated memory.<br>
b) To allocate memory for new variables.<br>
c) To reallocate memory for previously allocated blocks.<br>
d) To increase the size of allocated memory blocks.<br>


## 8. What is the output of the following code?<br>
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
   int *ptr = malloc(42);
   printf("Value of *ptr = %d \n", *ptr);

   int *ptr_c = calloc(2, 21);
   printf("Value of *ptr_c = %d \n", *ptr_c);
    
    return 0;
}
```
a) Value of *ptr = Garbage Address / Random address or value <br>
   Value of *ptr_c = 0<br>
b) Value of *ptr = Address of pointer ptr, <br>
   Value of *ptr_c = Address of pointer ptr_c<br>
c) Value of *ptr   = Garbage Address / Random address or value<br>
   Value of *ptr_c = Address of ptr_c<br>
d) Value of *ptr   = Address of pointer ptr<br>
   Value of *ptr_c = Garbage Address / Random address or value<br>

## 9. What is the purpose of the calloc() function in C?

a) To release dynamically allocated memory.<br>
b) To allocate memory for new variables.<br>
c) To allocate and zero-initialize memory for an array.<br>
d) To increase the size of allocated memory blocks.<br>

## 10. What is the output of the following code?
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
   char *string1 = "needle in a haystack";
   char *string2 = "in";
   char *result;

   result = strstr(string1,string2);
   printf("%s\n", result);
}
```
a) needle in a haystack<br>
b) in<br>
c) in a haystack<br>
d) i<br>

## 11. What is the purpose of the free() function in C?
a) To release dynamically allocated memory.<br>
b) To allocate memory for new variables.<br>
c) To increase the size of allocated memory blocks.<br>
d) To prevent memory overflow by automatically deallocating memory when it is no longer needed.<br>

## 12. Which function is used to open a file in C?
a) open()<br>
b) fopen()<br>
c) read()<br>
d) file_open()<br>

## 13. What does the fclose() function do in C?
a) Frees dynamically allocated memory.<br>
b) Closes a file.<br>
c) Copies a file.<br>
d) Reads from a file.<br>

## 14. How do you handle command-line arguments in a C program?
a) Using the argc variable.<br>
b) Using the argv variable.<br>
c) Using both argc and argv.<br>
d) Using the args variable.<br>

## 15. Which preprocessor directive is used to include a file in C?
a) #define<br>
b) #include<br>
c) #ifdef<br>
d) #ifndef<br>

## 16. What happens if you attempt to use the realloc function in C without previously allocating memory using malloc or calloc?
a) The program compiles successfully, but a runtime error occurs, resulting in undefined behavior.<br>
b) The realloc function returns a null pointer without altering memory, indicating a failure.<br>
c) The program fails to compile due to a syntax error in the realloc function call.<br>
d) The program executes normally, and the realloc function allocates memory as needed.<br>

## 17. What is the output of the following program?
```c
\#include <stdio.h>

int main() {
    char *names[] = {"Alice", "Bob", "Charlie", "David", "Emma"};
    char **ptr_to_ptr = names;
    char ***ptr_to_ptr_to_ptr = &ptr_to_ptr;

    *(*(ptr_to_ptr_to_ptr) + 2) = "Carol"; 

    printf("\nModified array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", *(*(ptr_to_ptr_to_ptr) + i));
    }
    
    return 0;
}
```
a) Error in *(*(ptr_to_ptr_to_ptr) + 2) = "Carol"; and print statement<br>
b) Error in declaring char **ptr_to_ptr = names;<br>
   It is expected to declare like char **ptr_to_ptr = &names;<br>
c) Alice<br>
   Bob<br>
   Carol<br>
   David<br>
   Emma<br>
d) Alice<br>
   Bob<br>
   Charlie<br>
   David<br>
   Emma<br>