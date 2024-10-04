#include <stdio.h>
#include <string.h>

#define MAX_LOCKERS 100        // Define maximum number of lockers
#define MAX_ITEM_LENGTH 50     // Define maximum length of item stored in a locker

void Menu()
{
    printf("\nLocker Rental Menu\n");
    printf("=============================\n");
    printf("1. View a locker\n");
    printf("2. Rent a locker\n");
    printf("3. End a locker rental\n");
    printf("4. List all locker contents\n");
    printf("5. Quit\n");
    printf("Enter your choice (1-5): ");
}

void viewLocker(char lockers[MAX_LOCKERS][MAX_ITEM_LENGTH])
{
    int lockerNumber;
    printf("Enter locker number (1-100): ");
    scanf("%d", &lockerNumber);

}

void rentLocker(char lockers[MAX_LOCKERS][MAX_ITEM_LENGTH])
{
    int lockerNumber;
    char item[MAX_ITEM_LENGTH];

}
