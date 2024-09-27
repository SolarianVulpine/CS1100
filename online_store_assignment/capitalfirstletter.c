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
    if (str == NULL || *str == '\0') 
    {
        return str; // Return original string if it's NULL or empty
    }

    // Capitalize the first character
    *str = toupper(*str);

    return (str); // Return the modified string

}
