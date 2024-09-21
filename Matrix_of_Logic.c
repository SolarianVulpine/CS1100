#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - entry point of the program
 * 
 * Description - Present user with a choice of taking one of four pills; Red, Blue, White, & Black.
 * program generates random binary values for two variables (p and q) and demonstrates the corresponding
 * logical operation beased on the user's choice
 * 
 * Return: zero? on success
 */

int main()
{
    srand(time(NULL));

    char choice;
    int x = 1;
    int p;
    int q;
    int bitwise_result;

    printf("Welcome to the Matrix of Logic!\n");

    while(choice != 'q' || choice != 'Q')
    {
        printf("You have a choice to make:\n");
        printf("Take the red pill (r), blue pill (b), white pill (w), or black (k): ");
        scanf("%c", &choice);

        p = rand() % 2;
        q = rand() % 2;

        printf("Binary dice roll: p = %d, q = %d\n", p, q);

        if(choice == 'r')
        {
            bitwise_result = p && q;
            printf("You took the red pill. Demonstrating LOGICAL AND: %d && %d = %d\n", p, q, bitwise_result);
        }

        if (choice == 'b')
        {
            bitwise_result = p ^ q;
            printf("You took the blue pill. Demonstrating LOGICAL XOR: %d ^ %d = %d\n", p, q, bitwise_result);
        }

        if (choice == 'w')
        {
            bitwise_result = p || q;
            printf("You took the white pill. Demonstrating LOGICAL OR: %d || %d = %d\n", p, q, bitwise_result);
        }
        if (choice == 'k')
        {
            printf("You took the black pill. Demonstrating LOGICAL NOT: !%d = %d and !%d = %d\n", p, !p, q, !q);
        }

        
        break;
    }


}