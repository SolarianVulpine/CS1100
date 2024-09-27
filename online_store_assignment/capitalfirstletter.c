#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "custom_functions.h"

/**
 * _capitalize - entry point of the program
 * 
 * meant to capitalize the first letter in an array
 */

char* _capitalize(char* str)
{

   // size_t len = strlen(str);
    // char* newStr = malloc(len + 1);

    // if (!newStr) 
    // {
    //     return NULL; // Memory allocation failed
    // }
    // char str[20];
    // int i;
    // int string_length;

    // printf("Enter a word in lowercase to capitalize the first letter: ");
    // scanf("%s", str);

    // if (str[0] != '\0') 
    // {
    //   char *str[0] = toupper(str[0]);
    // }

    // printf("Capitalized word: %s\n", str);
    if (str == NULL || *str == '\0') 
    {
        return str; // Return original string if it's NULL or empty
    }

    // Capitalize the first character
    *str = toupper(*str);

    return (str); // Return the modified string

}
