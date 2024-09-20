#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * 
 * Description - Write a program to check if a number is odd or even using an if statement
 * 
 */

int main ()
{
    int input;
    int x = 1;

    printf("Welcome to the Odd or Even Checker!\n");
    printf("I will determine if your number is even or odd\n");

    while (x == 1)
    {
        printf("\nPlease enter your number: ");
        scanf("%d", &input);

        if (input % 2 == 0)
        {
            printf("Your number,%d , is\nDrum roll\nDrum roll\nDrum roll\nEVEN\n", input);
            break;
        }
        else if (input % 2 != 0)
        {
            printf("Your number,%d , is\nDrum roll\nDrum roll\nDrum roll\nODD\n", input);
            break;
        }

    }
    

    
    

}