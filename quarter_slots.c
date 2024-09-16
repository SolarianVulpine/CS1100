/**
 * main - entry point of this code
 * 
 * Description - This program will run a slots game by generating a random number
 * 1-100 then processing input to determine a bet result base on that number
 * 
 * The user balance begins at $20 - 80 quarters
 * 
 * Display num of quarters and that amount's cash value before bet
 * 
 * user enters how much they want to bet in quarters
 * validate if input is eq 0 → cashout state
 * validate that input is not greater than current balance → invalid bet
 * 
 * if the slot machine number is less than 50 → the user loses bet → subtract
 * if the slot machine number is 50-74 → user gets their bet back
 * if the slot machine number is 75-94 → user's bet is doubled → add
 * if the slot machine number is 95-100 → user's bet is tripled (jackpot) → add
 * 
 * user is able to cashout by inputing "0" → display current balance and exit
 * 
 * Game Over occurs when balance value becomes 0 → display game over and close
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    srand(time(NULL));

    int quarters = 80;
    float balance ;
    int slot ;
    int bet ;
    int x = 1; /*keeps while loop true*/

    // printf("%d \n", slot);
    printf("Welcome to the Betting Game!\nYou have $20 worth of quarters.\n\n");

    while(x == 1)/*begins an infinite loop*/
    {
        float balance = quarters * .25;/*ensures balance is accurate and updated each bet*/
        int slot = rand() % 100 + 1;/*generates a new random number every bet*/

        if (quarters == 0)/*lose state if balance reaches zero*/
        {
            printf("Game Over\n");
            break;
        }

        /*prompts user with current balance and asks for bet total reads bet with scanf*/
        printf("You have %d quarters ($%.02f).\n", quarters, balance);
        printf("Enter the number of quarters to bet (or 0 to cash out): ");
        scanf("%d", &bet);

        /*exit case uses the number 0 as an early exit then tells user how much they made in dollars*/
        if (bet == 0)
        {
            printf("Cashing Out. You ended with $%.02f.", balance);
            break;;
        }

        /*reads bet amount, validates it, and performs arithmatic based on slot outcome*/
        if (bet > 0 && bet <= quarters)
        {
            printf("Reel stopped on the number: %d\n", slot);

            if (slot < 50)
            {
                quarters = quarters - bet;
                printf("You lose!\n");
            }
            else if (slot >= 75 && slot <= 94)
            {
                quarters = quarters + (bet * 2);
                printf("You double your money!\n");
            }
            else if (slot >= 95 && slot <= 100)
            {
                quarters = quarters + (bet * 3);
                printf("Jackpot! You triple your money!\n");
            }
            else if (slot >= 50 && slot <= 74)
            {
                printf("You get your money back!\n");
            }
        }
        else if (bet > quarters)
        {
            printf("")
            continue;
        }
        
        
    }

    return (0);
}