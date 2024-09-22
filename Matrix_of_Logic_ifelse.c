#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int x = 1;
    int p;
    int q;
    int bitwise_result;

    printf("Welcome to the Matrix of Logic!\n");

    while(x == 1)
    {
        char choice;

        printf("You have a choice to make:\n");
        printf("Take the red pill (r), blue pill (b), white pill (w), or black pill (k): ");
        scanf(" %c", &choice);

        p = rand() % 2;
        q = rand() % 2;

        if (choice == 'q' || choice == 'Q')
        {
            printf("Quitting! Are you sure? (y/n): ");
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y')
            {
                printf("Quitting!\n");
                break;
            }
            else
            {
                printf("Invalid choice.\n");
                continue;
            }
        }

        // printf("Binary dice roll: p = %d, q = %d\n", p, q);

        if (choice == 'r')
        {
            printf("Binary dice roll: p = %d, q = %d\n", p, q);    
            bitwise_result = p && q;
            printf("You took the red pill. Demonstrating LOGICAL AND: %d && %d = %d\n\n", p, q, bitwise_result);
        }
        else if (choice == 'b')
        {
            printf("Binary dice roll: p = %d, q = %d\n", p, q);
            bitwise_result = p ^ q;
            printf("You took the blue pill. Demonstrating LOGICAL XOR: %d ^ %d = %d\n\n", p, q, bitwise_result);
        }
        else if (choice == 'w')
        {
            printf("Binary dice roll: p = %d, q = %d\n", p, q);
            bitwise_result = p || q;
            printf("You took the white pill. Demonstrating LOGICAL OR: %d || %d = %d\n\n", p, q, bitwise_result);
        }
        else if (choice == 'k')
        {
            printf("Binary dice roll: p = %d, q = %d\n", p, q);
            printf("You took the black pill. Demonstrating LOGICAL NOT: !%d = %d and !%d = %d\n\n", p, !p, q, !q);
        }
        else 
        {
            printf("Invalid choice.\n");
            continue;
        }
    } 

    return (0);
}