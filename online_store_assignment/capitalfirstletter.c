#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - entry point of the program
 * 
 * meant to capitalize the first letter in an array
 */

int main ()
{
    char str[20];
    int i;
    int string_length;

    printf("Enter a word in lowercase to capitalize the first letter: ");
    scanf("%s", str);

    if (str[0] != '\0') 
    {
      str[0] = toupper(str[0]);
    }

    printf("Capitalized word: %s\n", str);

    return(0);
}
