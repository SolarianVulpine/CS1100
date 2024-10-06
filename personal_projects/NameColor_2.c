#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int letter_calculator(char* str);

int main()
{
    char *nameFirst;
    char *nameMiddle;
    char *nameLast;
    int n;

    int R_Value;
    int G_Value;
    int B_Value;

    //Introduction
    printf("\nWelcome to the Name Color Generator!\nWe will give you an RGB value based on the combined letters of your name.\n\n");

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

    printf("\n");

    //calculate RGB values for each string
    R_Value = letter_calculator(nameFirst);
    G_Value = letter_calculator(nameMiddle);
    B_Value = letter_calculator(nameLast);

    // letter_calculator(nameFirst);
    // letter_calculator(nameMiddle);
    // letter_calculator(nameLast);

    //print results to user
    printf("The name you entered was \"%s %s %s\"\n\n", nameFirst, nameMiddle, nameLast);
    printf("Your RGB values are %d, %d, %d   What a pretty color!\n", R_Value, G_Value, B_Value);
    printf("Thank you for playing! Goodbye!\n");


    return (0);
}

int letter_calculator(char* str)
{
    int size = strlen(str); //initializes the variable 'size' to be equal to how many slots are in str
    int i;
    int j;
    int total = 0;
    int values[sizeof(str)]; //creates an array to hold the numeric values of each letter

    for(i = 0; str[i] != '\0'; i++) //this loop converts letter characters into numeric value
    {
        if (isalpha(str[i])) //checks if character is a letter
        {
            values[i] = toupper(str[i]); //converts the letter to uppercase
            values[i] = values[i] - 64; //subtracts 64 from the ascii value of the uppercase letters (setting the values as A = 1 ... Z = 26)
        }
        else
        {
            values[i] = 0; //if the character is not a letter it's value is set to zero nullifying it's affect on the total
        }

    }

    j = size;
    values[j] = '\0';

    for(i = 0; values[i] != '\0'; i++) //this loop adds up the total of all character values
    {
        total = total + values[i];
    }

    total = total * 4; //multiplies the total by  4

    while(total > 255) // if the total at this point is greater than the max RGB Value 255 ↓
    {
        total = total - 256; // subract 256 until the total is within 255 range
    }

    return (total); //total is now an RGB value based on the specific string of characters passed into the function.

}