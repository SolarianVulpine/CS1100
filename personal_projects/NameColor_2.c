#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

/**
 * main - takes user input and prints results
 *
 * Description: This program is inspired by an
 * activity by @jared__cross on Instagram
 * in which he converts a person's name into a set of RGB values.
 * The first name represents the Red value.
 * The middle name represents the Green value.
 * The last name represents the Blue value.
 *
 * Retuen: 0 on success, 1 if there is an allocation error
 */


int letter_calculator(char *str);

int main(void)
{
	char *nameFirst;

	char *nameMiddle;

	char *nameLast;

	int n;

	int R_Value;

	int G_Value;

	int B_Value;

	/*Introduction*/
	printf("\nWelcome to the Name Color Generator!\n");
	printf("We will give you an RGB value based on the");
	printf(" combined letters of your name.\n\n");

	/*begin process for First name input*/
	nameFirst = (char *) malloc(1000 * sizeof(char));
	/*allocate memory for first name*/

	/*check if memory was allocated correctly*/
	if (nameFirst == NULL)
	{
		printf("Memory not allocated for first Name.\n");
		return (1);
	}

	/*take First name from user*/
	printf("Please enter your first name (this will be your R value): ");
	scanf("%s", nameFirst);

	/*reallocate memory based on the length of input*/
	n = strlen(nameFirst);
	nameFirst = (char *) realloc(nameFirst, (n + 1) * sizeof(char));

	/*check again if memory was allocated correctly*/
	if (nameFirst == NULL)
	{
		printf("Memory not allocated for first Name.\n");
		return (1);
	}

	/*begin process for middle name input*/
	nameMiddle = (char *) realloc(1000 * sizeof(char));

	if (nameMiddle == NULL)
	{
		printf("Memory not allocated for middle Name.\n");
		return (1);
	}

	printf("Please enter your middle name (this will be your G value): ");
	scanf("%s", nameMiddle);

	n = strlen(nameMiddle);
	nameMiddle = (char *) realloc(nameMiddle, (n + 1) * sizeof(char));

	if (nameMiddle == NULL)
	{
		printf("Memory not allocated for middle Name.\n");
		return (1);
	}

	/*begin process for last name input*/
	nameLast = (char *) malloc(1000 * sizeof(char));

	if (nameLast == NULL)
	{
		printf("Memory not allocated for last Name.\n");
		return (1);
	}

	printf("Please enter your last name (this will be your B value): ");
	scanf("%s", nameLast);

	n = strlen(nameLast);
	nameLast = (char *) realloc(nameLast, (n + 1) * sizeof(char));

	if (nameLast == NULL)
	{
		printf("Memory not allocated for last Name.\n");
		return (1);
	}

	printf("\n");

	/*calculate RGB values for each string*/
	R_Value = letter_calculator(nameFirst);
	G_Value = letter_calculator(nameMiddle);
	B_Value = letter_calculator(nameLast);

	/**
	* Letter_calculator(nameFirst);
	* Letter_calculator(nameMiddle);
	* letter_calculator(nameLast);
	*/

	/*print results to user*/
	printf("The name you entered was \"%s %s %s\"\n\n",
		nameFirst, nameMiddle, nameLast);
	printf("Your RGB values are → %d, %d, %d ← What a pretty color!\n",
		R_Value, G_Value, B_Value);
	printf("Thank you for playing! Goodbye!\n");

	free(nameFirst);
	free(nameMiddle);
	free(nameLast);

	return (0);
}

/**
 * letter_calculator - performs conversion and math to return
 * a value within the 0 - 255 RGB range
 *
 * @str: The string to be converted
 *
 * Description: This function aims to follow @jared__cross's
 * instructions to get a numeric value from a set of letters (such as a name.)
 * It takes a string of characters, converts them to uppercase,
 * then subtracts 64 from their ascii value.
 * This sets their numeric value to A = 1, B = 2, ... Z = 26.
 * It then adds the numbers up and multiplies the total by 4.
 * If at this point the value is greater than the RGB maximum of 255,
 * the function subtracts 256 from the total until it is under 255.
 * The total is now the RGB value.
 *
 * Return: Returns the total as the RGB value
 */

int letter_calculator(char *str)
{
	/*initializes the variable size to be equal to how many slots are in str*/
	int size = strlen(str);

	int i;

	int j;

	int total = 0;

	int values[sizeof(str)];


	for (i = 0; str[i] != '\0'; i++)
	{
		if (isalpha(str[i]))
		{
			values[i] = toupper(str[i]);
			values[i] = values[i] - 64;
		}
		else
		{
			values[i] = 0;
			/*if the character is not a letter set to zero*/

		}

	}

	j = size;
	values[j] = '\0';

	for (i = 0; values[i] != '\0'; i++)
	{
		total = total + values[i];
	}

	total = total * 4;

	while (total > 255)

	{
		total = total - 256;
	}

	return (total);
	/**
	* total is now an RGB value based on the specific
	* string of characters passed into the function.
	*/

}
