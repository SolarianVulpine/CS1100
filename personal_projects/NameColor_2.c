#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char *nameFirst;
    char *nameMiddle;
    char *nameLast;
    int n;

    //Introduction
    printf("Welcome to the Name Color Generator!\nWe will give you an RGB value based on the combined letters of your name.\n");

    //begin process for First name input
    nameFirst = (char*) malloc(100 * sizeof(char)); //allocate memory for first name

    if (nameFirst == NULL)
    {
        printf("Memory not allocated for first Name.\n"); //check if memory was allocated correctly
        return (1);
    }

    printf("Please enter your first name (this will be your R value): "); //take First name from user
    scanf("%s", nameFirst);

    n = strlen(nameFirst);
    nameFirst = (char*) realloc(nameFirst, (n + 1) * sizeof(char)); //reallocate memory based on the length of input

    if (nameFirst == NULL)
    {
        printf("Memory not allocated for first Name.\n"); //check again if memory was allocated correctly
        return (1);
    }

    //begin process for middle name input
    nameMiddle = (char*) malloc(100 * sizeof(char)); //allocate memory for middle name

    if (nameMiddle == NULL)
    {
        printf("Memory not allocated for middle Name.\n"); //check for correct allocation
        return (1);
    }

    printf("Please enter your middle name (this will be your G value): ");
    scanf("%s", nameMiddle);

    n = strlen(nameMiddle);
    nameMiddle = (char*) realloc(nameMiddle, (n + 1) * sizeof(char)); //reallocate memory based on length of input

    if (nameMiddle == NULL)
    {
        printf("Memory not allocated for middle Name.\n"); //check for allocation success again
        return (1);
    }

    //begin process for last name input
    nameLast = (char*) malloc(100 * sizeof(char)); //allocate memory for last name input

    if (nameLast == NULL)
    {
        printf("Memory not allocated for last Name.\n"); //check for allocation success
        return (1);
    }

    printf("Please enter your last name (this will be your B value): ");
    scanf("%s", nameLast);

    n = strlen(nameLast);
    nameLast = (char*) realloc(nameLast, (n + 1) * sizeof(char)); //reallocate memory based on length of input

    if (nameLast == NULL)
    {
        printf("Memory not allocated for last Name.\n"); //check for allocation success
        return (1);
    }

    printf("The name you entered was \"%s %s %s\"\n", nameFirst, nameMiddle, nameLast);


    return (0);
}