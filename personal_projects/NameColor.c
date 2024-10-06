#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

// #define MAX_LENGTH 150
// #define MAX_FIRST_NAME 50
// #define MAX_MIDDLE_NAME 50
// #define MAX_LAST_NAME 50

// struct fullName{
//     char *firstName;
//     char *middleName;
//     char *lastName;
// };

int letterAverage(char* array);

int main()
{
    // struct fullName namearr[MAX_LENGTH];
    // char *nameinput;
    // char **names;
    // int count = 0;

    // char nameInput[MAX_LENGTH];
    // int length = strlen(nameInput);

    // char first[MAX_FIRST_NAME];
    // char middle[MAX_MIDDLE_NAME];
    // char last[MAX_LAST_NAME];

    // int first_len = strlen(first);
    // int middle_len = strlen(middle);
    // int last_len = strlen(last);

    #define MAX_LENGTH 150
    char nameInput[MAX_LENGTH];

    printf("Welcome to the Name Color Generator!\n");

    printf("Enter your First, Middle, and Last name separated by spaces: ");
    fgets(nameInput, MAX_LENGTH, stdin);

    char first[25];
    char middle[25];
    char last[25];
    // char nameInput[MAX_LENGTH];
    // char nameInput[] = "Lancelot Wayne Gay";
    // int length = strlen(nameInput);

    int first_len = 0;
    int middle_len = 0;
    int last_len = 0;
    
    int i = 0;
    int j = 0; 
    int k = 0;
    

    /*loop to separate name into three parts*/
    for(; nameInput[i] != '\0'; i++)
    {
        if(nameInput[i] != ' ')
        {
        if(first_len != i)
        {
            if((first_len + middle_len + 1) == i)
            {
            middle[j] = nameInput[i];
            j++;
            middle_len++;
            }
            // else if(nameInput[i] == ' ')
            // {
            //   continue;
            // }
            else if((first_len + middle_len + 2 + k) == i)
            {
            last[k] = nameInput[i];
            k++;
            last_len++;
            }
        }
        else
        {
            first[i] = nameInput[i];
            first_len++;
        }
        }
        else if(nameInput[i] == ' ')
        {
        continue;
        }

    }
    
    int first_value = letterAverage(first);
    int middle_value = letterAverage(middle);
    int last_value = letterAverage(last);

    printf("First Name: %s\n", first);
    printf("Middle Name: %s\n", middle);
    printf("Last Name: %s\n", last);

    printf("Your RGB values are: %d, %d, %d\n", first_value, middle_value, last_value);
    
    return 0;
}

int letterAverage(char* array)
{
    // int size = sizeof(array);
    int i;
    int j;
    // int temp = 1;
    int total = 0;
    // int result;
    int values[sizeof(array)];

    for(i = 0; array[i] != '\0'; i++)
    {
        if (isalpha(array[i]))
        {
            values[i] = toupper(array[i]);
            values[i] = values[i] - 64;
        }
        else
        {
            values[i] = 0;
        }
        printf("%d\n", values[i]);
    }

    j = sizeof(array) - 1;
    values[j] = '\0';

    for(i = 0; values[i] != '\0'; i++)
    {
        total = total + values[i];
    }

    total = total * 4;

    while(total > 255)
    {
        total = total - 256;
    }

    return (total);

}